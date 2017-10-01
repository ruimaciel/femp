#include <libfemp/ElementResults/ElementResultsFactory.h++>


namespace fem
{


ElementResultsFactory::ElementResultsFactory(fem::Model &model, AnalysisResult &results)
{
	this->m_model = &model;
	this->m_analysis_result = &results;
}


ElementResults *
ElementResultsFactory::operator() (const fem::Element &reference_element)
{
	assert(this->m_model != NULL);
	assert(this->m_analysis_result != NULL);

	ElementResults *results;
	results = new ElementResults;

	fem::BaseElement *element;

	switch(reference_element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			element = &m_tetrahedron4;
			results->resize(4);
			break;

		case fem::Element::FE_TETRAHEDRON10:
			element = &m_tetrahedron10;
			results->resize(10);
			break;

		case fem::Element::FE_HEXAHEDRON8:
			element = &m_hexahedron8;
			results->resize(8);
			break;

		case fem::Element::FE_HEXAHEDRON20:
			element = &m_hexahedron20;
			results->resize(20);
			break;

		case fem::Element::FE_HEXAHEDRON27:
			element = &m_hexahedron27;
			results->resize(27);
			break;

		case fem::Element::FE_PRISM6:
			element = &m_prism6;
			results->resize(6);
			break;

		case fem::Element::FE_PRISM15:
			element = &m_prism15;
			results->resize(15);
			break;

		case fem::Element::FE_PRISM18:
			element = &m_prism18;
			results->resize(18);
			break;

		default:
			throw FemException("unknown element type request");
			return NULL;
			break;
	}

	// calculate
	element->setCoordinates();

	fem::Point dxdcsi, dxdeta, dxdzeta;
	
	// cycle to calculate a gradient value for each node
	for(unsigned int coord = 0; coord < element->coordinates.size(); coord++)
	{
		fem::Point local = element->coordinates[coord];	// Point in element in \xi, the local coordinates
		fem::Point global;	// node coordinate in x, the global coordinates
		
		element->setdNdcsi(local);
		element->setdNdeta(local);
		element->setdNdzeta(local);

		dxdcsi.zero(); dxdeta.zero(); dxdzeta.zero();

		// set Dg
		Dg.setZero();
		for(unsigned int node = 0; node < element->coordinates.size(); node++)
		{
			// get the node's x coordinate, the coordinate in the global frame of reference
			global = m_model->getNode(reference_element.nodes[node]);

			dxdcsi += element->dNdcsi[node]*global;
			dxdeta += element->dNdeta[node]*global;
			dxdzeta += element->dNdzeta[node]*global;
		}

		Dg(0,0) = dxdcsi.x();	Dg(0,1) = dxdcsi.y();	Dg(0,2) = dxdcsi.z();
		Dg(1,0) = dxdeta.x();	Dg(1,1) = dxdeta.y();	Dg(1,2) = dxdeta.z();
		Dg(2,0) = dxdzeta.x();	Dg(2,1) = dxdzeta.y();	Dg(2,2) = dxdzeta.z();

		invDg = Dg.inverse();

		//m_gradient_value[coord] = 0;

		// set strains
		double dNdx = 0;
		double dNdy = 0;
		double dNdz = 0;
		for(unsigned int node = 0; node < element->coordinates.size(); node++)
		{
			fem::Point d; // displacements
			d = this->m_analysis_result->displacements[ reference_element.nodes[node] ];	// displacements calculated in this node

			// calculate \epsilon_{11} = dNdx_1*d1
			dNdx  = invDg(0,0)*element->dNdcsi[node] + invDg(0,1)*element->dNdeta[node] + invDg(0,2)*element->dNdzeta[node];
			dNdy  = invDg(1,0)*element->dNdcsi[node] + invDg(1,1)*element->dNdeta[node] + invDg(1,2)*element->dNdzeta[node];
			dNdz  = invDg(2,0)*element->dNdcsi[node] + invDg(2,1)*element->dNdeta[node] + invDg(2,2)*element->dNdzeta[node];
			
			//m_gradient_value[coord] += dNdx*d.x(); 
			results->strains[coord].e11 += dNdx*d.x();
			results->strains[coord].e22 += dNdy*d.y();
			results->strains[coord].e33 += dNdz*d.z();
			results->strains[coord].e12 += dNdx*d.y() + dNdy*d.x();
			results->strains[coord].e13 += dNdx*d.z() + dNdz*d.x();
			results->strains[coord].e23 += dNdy*d.z() + dNdz*d.y();
		}

		// set the stresses
		double E, nu;
		E = this->m_model->material_list[reference_element.material].E;
		nu = this->m_model->material_list[reference_element.material].nu;

		results->stresses[coord].s11 = ( (1-nu)*results->strains[coord].e11 + nu*results->strains[coord].e22 + nu*results->strains[coord].e33 )*E/((1+nu)*(1-2*nu)) ;
		results->stresses[coord].s22 = ( nu*results->strains[coord].e11 + (1-nu)*results->strains[coord].e22 + nu*results->strains[coord].e33 )*E/((1+nu)*(1-2*nu)) ;
		results->stresses[coord].s33 = ( nu*results->strains[coord].e11 + nu*results->strains[coord].e22 + (1-nu)*results->strains[coord].e33 )*E/((1+nu)*(1-2*nu)) ;
		results->stresses[coord].s12 = 0.5*results->strains[coord].e12*E/(1+nu);
		results->stresses[coord].s23 = 0.5*results->strains[coord].e23*E/(1+nu);
		results->stresses[coord].s13 = 0.5*results->strains[coord].e13*E/(1+nu);

		// set the von mises 
		Stresses<double> s = results->stresses[coord];
		results->von_mises[coord] = 0.7071067812*sqrt( 
		(s.s11 - s.s22)*(s.s11 - s.s22)  + 
		(s.s22 - s.s33)*(s.s22 - s.s33)  + 
		(s.s33 - s.s22)*(s.s33 - s.s22)  + 
		6*( s.s12*s.s12 + s.s23*s.s23 + s.s13*s.s13)
		);
		// */

		//STRAINS
		// adjust max values
		if(results->strains[coord].e11 > m_analysis_result->ranges.max_strain11)
			m_analysis_result->ranges.max_strain11 =results->strains[coord].e11;
		if(results->strains[coord].e22 > m_analysis_result->ranges.max_strain22)
			m_analysis_result->ranges.max_strain22 =results->strains[coord].e22;
		if(results->strains[coord].e33 > m_analysis_result->ranges.max_strain33)
			m_analysis_result->ranges.max_strain33 =results->strains[coord].e33;
		if(results->strains[coord].e12 > m_analysis_result->ranges.max_strain12)
			m_analysis_result->ranges.max_strain12 =results->strains[coord].e12;
		if(results->strains[coord].e23 > m_analysis_result->ranges.max_strain23)
			m_analysis_result->ranges.max_strain23 =results->strains[coord].e23;
		if(results->strains[coord].e13 > m_analysis_result->ranges.max_strain13)
			m_analysis_result->ranges.max_strain13 =results->strains[coord].e13;

		// adjust min values
		if(results->strains[coord].e11 < m_analysis_result->ranges.min_strain11)
			m_analysis_result->ranges.min_strain11 =results->strains[coord].e11;
		if(results->strains[coord].e22 < m_analysis_result->ranges.min_strain22)
			m_analysis_result->ranges.min_strain22 =results->strains[coord].e22;
		if(results->strains[coord].e33 < m_analysis_result->ranges.min_strain33)
			m_analysis_result->ranges.min_strain33 =results->strains[coord].e33;
		if(results->strains[coord].e12 < m_analysis_result->ranges.min_strain12)
			m_analysis_result->ranges.min_strain12 =results->strains[coord].e12;
		if(results->strains[coord].e23 < m_analysis_result->ranges.min_strain23)
			m_analysis_result->ranges.min_strain23 =results->strains[coord].e23;
		if(results->strains[coord].e13 < m_analysis_result->ranges.min_strain13)
			m_analysis_result->ranges.min_strain13 =results->strains[coord].e13;

		//STRESSES
		// adjust max values
		if(results->stresses[coord].s11 > m_analysis_result->ranges.max_stress11)
			m_analysis_result->ranges.max_stress11 =results->stresses[coord].s11;
		if(results->stresses[coord].s22 > m_analysis_result->ranges.max_stress22)
			m_analysis_result->ranges.max_stress22 =results->stresses[coord].s22;
		if(results->stresses[coord].s33 > m_analysis_result->ranges.max_stress33)
			m_analysis_result->ranges.max_stress33 =results->stresses[coord].s33;
		if(results->stresses[coord].s12 > m_analysis_result->ranges.max_stress12)
			m_analysis_result->ranges.max_stress12 =results->stresses[coord].s12;
		if(results->stresses[coord].s23 > m_analysis_result->ranges.max_stress23)
			m_analysis_result->ranges.max_stress23 =results->stresses[coord].s23;
		if(results->stresses[coord].s13 > m_analysis_result->ranges.max_stress13)
			m_analysis_result->ranges.max_stress13 =results->stresses[coord].s13;

		// adjust min values
		if(results->stresses[coord].s11 < m_analysis_result->ranges.min_stress11)
			m_analysis_result->ranges.min_stress11 =results->stresses[coord].s11;
		if(results->stresses[coord].s22 < m_analysis_result->ranges.min_stress22)
			m_analysis_result->ranges.min_stress22 =results->stresses[coord].s22;
		if(results->stresses[coord].s33 < m_analysis_result->ranges.min_stress33)
			m_analysis_result->ranges.min_stress33 =results->stresses[coord].s33;
		if(results->stresses[coord].s12 < m_analysis_result->ranges.min_stress12)
			m_analysis_result->ranges.min_stress12 =results->stresses[coord].s12;
		if(results->stresses[coord].s23 < m_analysis_result->ranges.min_stress23)
			m_analysis_result->ranges.min_stress23 =results->stresses[coord].s23;
		if(results->stresses[coord].s13 < m_analysis_result->ranges.min_stress13)
			m_analysis_result->ranges.min_stress13 =results->stresses[coord].s13;

		//VON MISES
		if(results->von_mises[coord] > m_analysis_result->ranges.max_von_mises)
			m_analysis_result->ranges.max_von_mises = results->von_mises[coord];

	}

	// nasty hack to set up the tensor
	double tensor[3][3];
	switch(reference_element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_TETRAHEDRON10:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_HEXAHEDRON8:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_HEXAHEDRON20:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_HEXAHEDRON27:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_PRISM6:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_PRISM15:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		case fem::Element::FE_PRISM18:
			tensor[0][0] = results->stresses[4].s11;
			tensor[1][1] = results->stresses[4].s22;
			tensor[2][2] = results->stresses[4].s33;
			tensor[0][1] = tensor[1][0] = results->stresses[4].s12;
			tensor[0][2] = tensor[2][0] = results->stresses[4].s13;
			tensor[1][2] = tensor[2][1] = results->stresses[4].s23;
			break;

		default:
			throw FemException("unknown element type request");
			return NULL;
			break;
	}

	// calculate eigenvalues and eigenvectors
	dsyevj3(tensor, results->eig_vec, results->eig_val);

	// tension and compression
	for(int i = 0; i < 3; i++)
	{
		if(results->eig_val[i] > m_analysis_result->ranges.max_tension)
			m_analysis_result->ranges.max_tension = results->eig_val[i];
		if(results->eig_val[i] < m_analysis_result->ranges.max_compression)
			m_analysis_result->ranges.max_compression = results->eig_val[i];
	}

	return results;
}


// ----------------------------------------------------------------------------
// Numerical diagonalization of 3x3 matrcies
// Copyright (C) 2006  Joachim Kopp
// ----------------------------------------------------------------------------
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
// ----------------------------------------------------------------------------

// Macros
#define SQR(x)      ((x)*(x))                        // x^2 


// ----------------------------------------------------------------------------
int 
ElementResultsFactory::dsyevj3(double A[3][3], double Q[3][3], double w[3]) const
// ----------------------------------------------------------------------------
// Calculates the eigenvalues and normalized eigenvectors of a symmetric 3x3
// matrix A using the Jacobi algorithm.
// The upper triangular part of A is destroyed during the calculation,
// the diagonal elements are read but not destroyed, and the lower
// triangular elements are not referenced at all.
// ----------------------------------------------------------------------------
// Parameters:
//   A: The symmetric input matrix
//   Q: Storage buffer for eigenvectors
//   w: Storage buffer for eigenvalues
// ----------------------------------------------------------------------------
// Return value:
//   0: Success
//  -1: Error (no convergence)
// ----------------------------------------------------------------------------
{
	const int n = 3;
	double sd, so;                  // Sums of diagonal resp. off-diagonal elements
	double s, c, t;                 // sin(phi), cos(phi), tan(phi) and temporary storage
	double g, h, z, theta;          // More temporary storage
	double thresh;

	// Initialize Q to the identitity matrix
#ifndef FEMP_EVALS_ONLY
	for (int i=0; i < n; i++)
	{
		Q[i][i] = 1.0;
		for (int j=0; j < i; j++)
			Q[i][j] = Q[j][i] = 0.0;
	}
#endif

	// Initialize w to diag(A)
	for (int i=0; i < n; i++)
		w[i] = A[i][i];

	// Calculate SQR(tr(A))  
	sd = 0.0;
	for (int i=0; i < n; i++)
		sd += fabs(w[i]);
	sd = SQR(sd);

	// Main iteration loop
	for (int nIter=0; nIter < 50; nIter++)
	{
		// Test for convergence 
		so = 0.0;
		for (int p=0; p < n; p++)
			for (int q=p+1; q < n; q++)
				so += fabs(A[p][q]);
		if (so == 0.0)
			return 0;

		if (nIter < 4)
			thresh = 0.2 * so / SQR(n);
		else
			thresh = 0.0;

		// Do sweep
		for (int p=0; p < n; p++)
			for (int q=p+1; q < n; q++)
			{
				g = 100.0 * fabs(A[p][q]);
				if (nIter > 4  &&  fabs(w[p]) + g == fabs(w[p])
						&&  fabs(w[q]) + g == fabs(w[q]))
				{
					A[p][q] = 0.0;
				}
				else if (fabs(A[p][q]) > thresh)
				{
					// Calculate Jacobi transformation
					h = w[q] - w[p];
					if (fabs(h) + g == fabs(h))
					{
						t = A[p][q] / h;
					}
					else
					{
						theta = 0.5 * h / A[p][q];
						if (theta < 0.0)
							t = -1.0 / (sqrt(1.0 + SQR(theta)) - theta);
						else
							t = 1.0 / (sqrt(1.0 + SQR(theta)) + theta);
					}
					c = 1.0/sqrt(1.0 + SQR(t));
					s = t * c;
					z = t * A[p][q];

					// Apply Jacobi transformation
					A[p][q] = 0.0;
					w[p] -= z;
					w[q] += z;
					for (int r=0; r < p; r++)
					{
						t = A[r][p];
						A[r][p] = c*t - s*A[r][q];
						A[r][q] = s*t + c*A[r][q];
					}
					for (int r=p+1; r < q; r++)
					{
						t = A[p][r];
						A[p][r] = c*t - s*A[r][q];
						A[r][q] = s*t + c*A[r][q];
					}
					for (int r=q+1; r < n; r++)
					{
						t = A[p][r];
						A[p][r] = c*t - s*A[q][r];
						A[q][r] = s*t + c*A[q][r];
					}

					// Update eigenvectors
#ifndef FEMP_EVALS_ONLY          
					for (int r=0; r < n; r++)
					{
						t = Q[r][p];
						Q[r][p] = c*t - s*Q[r][q];
						Q[r][q] = s*t + c*Q[r][q];
					}
#endif
				}
			}
	}

	return -1;
}

#undef SQR


}	// namespace fem

