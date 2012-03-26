#include "StressFieldFactory.h++"


namespace StressFieldRepresentation
{


StressFieldFactory::StressFieldFactory(float &diameter, fem::Model &model, fem::AnalysisResult<double> &result)
{
	this->m_diameter = &diameter;
	this->m_model = &model;
	this->m_result = &result;
}


StressFieldRepresentation 
StressFieldFactory::operator() (fem::Element const &element) 
{
	StressFieldRepresentation representation;

	fem::BaseElement<double> *e = nullptr;
	std::vector<fem::point>	local_points;	// list of local_points coordinates where the tensors will be evaluated
	fem::point dxdcsi, dxdeta, dxdzeta;

	float e11, e22, e33, e12, e13, e23;

	//setup the stress field representation for this particular e
	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			e = &m_tetrahedron4;
			local_points = { {1.0/3, 1.0/3, 1.0/3} };
			break;

		case fem::Element::FE_TETRAHEDRON10:
			e = &m_tetrahedron10;
			local_points = { {1.0/3, 1.0/3, 1.0/3} };
			break;

		case fem::Element::FE_HEXAHEDRON8:
			e = &m_hexahedron8;
			local_points = { {0,0,0} };
			break;

		case fem::Element::FE_HEXAHEDRON20:
			e = &m_hexahedron20;
			local_points = { {0,0,0} };
			break;

		case fem::Element::FE_HEXAHEDRON27:
			e = &m_hexahedron27;
			local_points = { {0,0,0} };
			break;

		case fem::Element::FE_PRISM6:
			e = &m_prism6;
			local_points = { {0,0,0} };
			break;

		case fem::Element::FE_PRISM15:
			e = &m_prism15;
			local_points = { {1.0/3, 1.0/3, 0} };
			break;

		case fem::Element::FE_PRISM18:
			e = &m_prism18;
			local_points = { {1.0/3, 1.0/3, 0} };
			break;

		case fem::Element::FE_INVALID:
			// invalid e type
			//break;
		default:
			// something unexpected happened
			break;
	}

	e->setCoordinates();

	// calculate stresses
	for(auto local: local_points)
	{
		//TODO calculate stresses
		fem::point global;	// node coordinate in x, the global coordinates

		e->setdNdcsi(local);
		e->setdNdeta(local);
		e->setdNdzeta(local);

		dxdcsi.zero(); dxdeta.zero(); dxdzeta.zero();

		e11 = e22 = e33 = e12 = e13 = e23 = 0;

		// set Dg
		Dg.setZero();
		for(unsigned int node = 0; node < e->coordinates.size(); node++)
		{
			// get the node's x coordinate, the coordinate in the global frame of reference
			global = m_model->getNode(element.nodes[node]);

			dxdcsi += e->dNdcsi[node]*global;
			dxdeta += e->dNdeta[node]*global;
			dxdzeta += e->dNdzeta[node]*global;
		}

		Dg(0,0) = dxdcsi.x();	Dg(0,1) = dxdcsi.y();	Dg(0,2) = dxdcsi.z();
		Dg(1,0) = dxdeta.x();	Dg(1,1) = dxdeta.y();	Dg(1,2) = dxdeta.z();
		Dg(2,0) = dxdzeta.x();	Dg(2,1) = dxdzeta.y();	Dg(2,2) = dxdzeta.z();

		Dg.computeInverse(&invDg);

		//m_gradient_value[coord] = 0;

		// set strains
		float dNdx = 0;
		float dNdy = 0;
		float dNdz = 0;

		// iterate through each node in the element
		for(unsigned int node = 0; node < e->coordinates.size(); node++)
		{
			fem::point d; // displacements
			d = m_result->displacements[ element.nodes[node] ];	// displacements calculated in this node

			// calculate \epsilon_{11} = dNdx_1*d1
			dNdx  = invDg(0,0)*e->dNdcsi[node] + invDg(0,1)*e->dNdeta[node] + invDg(0,2)*e->dNdzeta[node];
			dNdy  = invDg(1,0)*e->dNdcsi[node] + invDg(1,1)*e->dNdeta[node] + invDg(1,2)*e->dNdzeta[node];
			dNdz  = invDg(2,0)*e->dNdcsi[node] + invDg(2,1)*e->dNdeta[node] + invDg(2,2)*e->dNdzeta[node];
			
			//m_gradient_value[coord] += dNdx*d.x(); 
			e11 += dNdx*d.x();
			e22 += dNdy*d.y();
			e33 += dNdz*d.z();
			e12 += dNdx*d.y() + dNdy*d.x();
			e13 += dNdx*d.z() + dNdz*d.x();
			e23 += dNdy*d.z() + dNdz*d.y();
		}

		float E, nu;
		E = this->m_model->material_list[element.material].E;
		nu = this->m_model->material_list[element.material].nu;

		// now, set up the stress vector
		A[0][0] = ( (1-nu)*e11 + nu*e22 + nu*e33 )*E/((1+nu)*(1-2*nu)) ;
		A[1][1] = ( nu*e11 + (1-nu)*e22 + nu*e33 )*E/((1+nu)*(1-2*nu)) ;
		A[2][2] = ( nu*e11 + nu*e22 + (1-nu)*e33 )*E/((1+nu)*(1-2*nu)) ;
		A[1][0] = A[0][1] = 0.5*e12*E/(1+nu);
		A[2][1] = A[1][2] = 0.5*e23*E/(1+nu);
		A[2][0] = A[0][2] = 0.5*e13*E/(1+nu);

		// calculate principal directions
		dsyevj3(A, eig_vec, eig_val);

		// get position
		fem::point pos;
		//TODO get global position
		e->setN(local);
		for(std::vector<fem::node_ref_t>::size_type n = 0; n < e->N.size(); n++)
		{
			pos += e->N[n]*m_model->node_list[ element.nodes[n]];
		}


		std::array<fem::point, 3> directions;
		std::array<float, 3> stresses;
		for(int i = 0; i < 3; i++)
		{
			directions[i].data[0] = eig_vec[i][0];
			directions[i].data[1] = eig_vec[i][1];
			directions[i].data[2] = eig_vec[i][2];

			directions[i].normalize();

			stresses[i] = eig_val[i];
		}

		// set values
		representation.push(pos, directions, stresses);

	}

	// update diameter
	
	// all ended well
	return representation;
}


float 
StressFieldFactory::max() const
{
	return m_max;
}


float 
StressFieldFactory::min() const
{
	return m_min;
}

// Macros
#define SQR(x)      ((x)*(x))                        // x^2 


// ----------------------------------------------------------------------------
int 
StressFieldFactory::dsyevj3(double A[3][3], double Q[3][3], double w[3]) const
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
#ifndef EVALS_ONLY
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
#ifndef EVALS_ONLY          
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

}
