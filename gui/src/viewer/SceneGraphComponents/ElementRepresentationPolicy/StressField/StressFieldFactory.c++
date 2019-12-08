#include "StressFieldFactory.h++"

namespace StressFieldRepresentation {

StressFieldFactory::StressFieldFactory(float& diameter, fem::Model& model, fem::AnalysisResult& result)
{
    this->m_diameter = &diameter;
    this->m_model = &model;
    this->m_result = &result;

    m_max = m_min = 0;
}

StressFieldRepresentation
StressFieldFactory::operator()(fem::Element const& element)
{
    assert(m_model != nullptr);

    StressFieldRepresentation representation;

    fem::BaseElement* e = nullptr;
    std::vector<fem::Point3D> local_points; // list of local_points coordinates where the tensors will be evaluated
    fem::Point3D dxdcsi, dxdeta, dxdzeta;

    double e11, e22, e33, e12, e13, e23;

    // helper
    //auto di = [&m_diameter, &m_model, &element](float const scale, std::initializer_list< std::pair<fem::node_ref_t, fem::node_ref_t> > list)
    auto di = [&](float const scale, std::initializer_list<std::pair<fem::node_ref_t, fem::node_ref_t>> list) {
        for (auto a : list) {
            auto node_list = m_model->getNodeMap();
            fem::Point3D d = node_list[element.getNode(a.second)] - node_list[element.getNode(a.first)];
            if (scale * scale * dot_product(d, d) < (*m_diameter) * (*m_diameter))
                *m_diameter = scale * d.norm();
        }
    };

    //setup the stress field representation for this particular e
    switch (element.getType()) {
    case fem::Element::FE_TETRAHEDRON4:
        e = &m_tetrahedron4;
        local_points = { { 1.0 / 3, 1.0 / 3, 1.0 / 3 } };

        // tweak the diameter
        di(0.30f, { { 0, 1 }, { 1, 2 }, { 2, 0 }, { 0, 3 }, { 1, 3 }, { 2, 3 } });

        break;

    case fem::Element::FE_TETRAHEDRON10:
        e = &m_tetrahedron10;
        local_points = { { 1.0 / 3, 1.0 / 3, 1.0 / 3 } };

        // tweak the diameter
        di(0.20f, { { 0, 1 }, { 1, 2 }, { 2, 0 }, { 0, 3 }, { 1, 3 }, { 2, 3 } });
        break;

    case fem::Element::FE_HEXAHEDRON8:
        e = &m_hexahedron8;
        local_points = { { 0, 0, 0 } };

        // tweak the diameter
        di(0.40f, { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 }, { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 }, { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 } });
        break;

    case fem::Element::FE_HEXAHEDRON20:
        e = &m_hexahedron20;
        local_points = {
            { -0.57735, -0.57735, -0.57735 },
            { 0.57735, -0.57735, -0.57735 },
            { 0.57735, 0.57735, -0.57735 },
            { -0.57735, 0.57735, -0.57735 },
            { -0.57735, -0.57735, 0.57735 },
            { 0.57735, -0.57735, 0.57735 },
            { 0.57735, 0.57735, 0.57735 },
            { -0.57735, 0.57735, 0.57735 }
        };
        // tweak the diameter
        di(0.20f, { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 }, { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 }, { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 } });
        break;

    case fem::Element::FE_HEXAHEDRON27:
        e = &m_hexahedron27;
        local_points = {
            { -0.57735, -0.57735, -0.57735 },
            { 0.57735, -0.57735, -0.57735 },
            { 0.57735, 0.57735, -0.57735 },
            { -0.57735, 0.57735, -0.57735 },
            { -0.57735, -0.57735, 0.57735 },
            { 0.57735, -0.57735, 0.57735 },
            { 0.57735, 0.57735, 0.57735 },
            { -0.57735, 0.57735, 0.57735 }
        };
        // tweak the diameter
        di(0.20f, { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 }, { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 }, { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 } });
        break;

    case fem::Element::FE_PRISM6:
        e = &m_prism6;
        local_points = {
            { 1.0 / 3, 1.0 / 3, 0 }
        };

        // tweak the diameter
        di(0.40f, { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 0, 3 }, { 3, 4 }, { 3, 5 }, { 4, 5 } });
        break;

    case fem::Element::FE_PRISM15:
        e = &m_prism15;
        local_points = {
            { 1.0 / 3, 1.0 / 3, -0.57735 },
            { 1.0 / 3, 1.0 / 3, 0.57735 }
        };

        // tweak the diameter
        di(0.20f, { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 0, 3 }, { 3, 4 }, { 3, 5 }, { 4, 5 } });
        break;

    case fem::Element::FE_PRISM18:
        e = &m_prism18;
        local_points = {
            { 1.0 / 3, 1.0 / 3, -0.57735 },
            { 1.0 / 3, 1.0 / 3, 0.57735 }
        };

        // tweak the diameter
        di(0.20f, { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 0, 3 }, { 3, 4 }, { 3, 5 }, { 4, 5 } });
        break;

    case fem::Element::FE_INVALID:
        // invalid e type
        //break;
    default:
        //TODO this case must be dealt with
        // something unexpected happened
        break;
    }

    // calculate stresses
    for (auto local : local_points) {
        //TODO calculate stresses
        fem::Point3D global; // node coordinate in x, the global coordinates

        auto dNdcsi = e->getdNdcsi(local);
        auto dNdeta = e->getdNdeta(local);
        auto dNdzeta = e->getdNdzeta(local);

        dxdcsi.zero();
        dxdeta.zero();
        dxdzeta.zero();

        e11 = e22 = e33 = e12 = e13 = e23 = 0;

        // set Dg
        Dg.setZero();
        auto coordinates = e->getLocalCoordinates();
        for (unsigned int node = 0; node < coordinates.size(); node++) {
            // get the node's x coordinate, the coordinate in the global frame of reference
            global = m_model->getNode(element.getNode(node));

            dxdcsi += dNdcsi[node] * global;
            dxdeta += dNdeta[node] * global;
            dxdzeta += dNdzeta[node] * global;
        }

        Dg(0, 0) = dxdcsi.x();
        Dg(0, 1) = dxdcsi.y();
        Dg(0, 2) = dxdcsi.z();
        Dg(1, 0) = dxdeta.x();
        Dg(1, 1) = dxdeta.y();
        Dg(1, 2) = dxdeta.z();
        Dg(2, 0) = dxdzeta.x();
        Dg(2, 1) = dxdzeta.y();
        Dg(2, 2) = dxdzeta.z();

        invDg = Dg.inverse();

        //m_gradient_value[coord] = 0;

        // set strains
        double dNdx = 0;
        double dNdy = 0;
        double dNdz = 0;

        // iterate through each node in the element
        for (unsigned int node = 0; node < coordinates.size(); node++) {
            fem::Point3D d; // displacements
            d = m_result->displacements[element.getNode(node)]; // displacements calculated in this node

            // calculate \epsilon_{11} = dNdx_1*d1
            dNdx = invDg(0, 0) * dNdcsi[node] + invDg(0, 1) * dNdeta[node] + invDg(0, 2) * dNdzeta[node];
            dNdy = invDg(1, 0) * dNdcsi[node] + invDg(1, 1) * dNdeta[node] + invDg(1, 2) * dNdzeta[node];
            dNdz = invDg(2, 0) * dNdcsi[node] + invDg(2, 1) * dNdeta[node] + invDg(2, 2) * dNdzeta[node];

            //m_gradient_value[coord] += dNdx*d.x();
            e11 += dNdx * d.x();
            e22 += dNdy * d.y();
            e33 += dNdz * d.z();
            e12 += dNdx * d.y() + dNdy * d.x();
            e13 += dNdx * d.z() + dNdz * d.x();
            e23 += dNdy * d.z() + dNdz * d.y();
        }

        auto material = m_model->getMaterialByIndex(element.material);
        const double E = material.getYoungsModulus();
        const double nu = material.getPoissonRatio();

        // now, set up the stress vector
        A[0][0] = ((1 - nu) * e11 + nu * e22 + nu * e33) * E / ((1 + nu) * (1 - 2 * nu));
        A[1][1] = (nu * e11 + (1 - nu) * e22 + nu * e33) * E / ((1 + nu) * (1 - 2 * nu));
        A[2][2] = (nu * e11 + nu * e22 + (1 - nu) * e33) * E / ((1 + nu) * (1 - 2 * nu));
        A[1][0] = A[0][1] = 0.5 * e12 * E / (1 + nu);
        A[2][1] = A[1][2] = 0.5 * e23 * E / (1 + nu);
        A[2][0] = A[0][2] = 0.5 * e13 * E / (1 + nu);

        // calculate principal directions
        dsyevj3(A, eig_vec, eig_val);

        // get position
        fem::Point3D pos;
        //TODO get global position
        auto N = e->getN(local);
        for (std::vector<fem::node_ref_t>::size_type n = 0; n < N.size(); n++) {
            pos += N[n] * m_model->getNode(element.getNode(n));
        }

        std::array<fem::Point3D, 3> directions;
        std::array<float, 3> stresses;
        for (int i = 0; i < 3; i++) {
            directions[i].data[0] = eig_vec[0][i];
            directions[i].data[1] = eig_vec[1][i];
            directions[i].data[2] = eig_vec[2][i];

            directions[i].normalize();

            stresses[i] = eig_val[i];

            //update the max and min values
            if (eig_val[i] > m_max)
                m_max = eig_val[i];
            if (eig_val[i] < m_min)
                m_min = eig_val[i];
        }

        // set values
        representation.push(pos, directions, stresses);
    }

    // all ended well
    return representation;
}

float StressFieldFactory::max() const
{
    return m_max;
}

float StressFieldFactory::min() const
{
    return m_min;
}

// Macros
#define SQR(x) ((x) * (x)) // x^2

// ----------------------------------------------------------------------------
int StressFieldFactory::dsyevj3(double A[3][3], double Q[3][3], double w[3]) const
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
    double sd, so; // Sums of diagonal resp. off-diagonal elements
    double s, c, t; // sin(phi), cos(phi), tan(phi) and temporary storage
    double g, h, z, theta; // More temporary storage
    double thresh;

    // Initialize Q to the identitity matrix
#ifndef EVALS_ONLY
    for (int i = 0; i < n; i++) {
        Q[i][i] = 1.0;
        for (int j = 0; j < i; j++)
            Q[i][j] = Q[j][i] = 0.0;
    }
#endif

    // Initialize w to diag(A)
    for (int i = 0; i < n; i++)
        w[i] = A[i][i];

    // Calculate SQR(tr(A))
    sd = 0.0;
    for (int i = 0; i < n; i++)
        sd += fabs(w[i]);
    sd = SQR(sd);

    // Main iteration loop
    for (int nIter = 0; nIter < 50; nIter++) {
        // Test for convergence
        so = 0.0;
        for (int p = 0; p < n; p++)
            for (int q = p + 1; q < n; q++)
                so += fabs(A[p][q]);
        if (so == 0.0)
            return 0;

        if (nIter < 4)
            thresh = 0.2 * so / SQR(n);
        else
            thresh = 0.0;

        // Do sweep
        for (int p = 0; p < n; p++)
            for (int q = p + 1; q < n; q++) {
                g = 100.0 * fabs(A[p][q]);
                if (nIter > 4 && fabs(w[p]) + g == fabs(w[p])
                    && fabs(w[q]) + g == fabs(w[q])) {
                    A[p][q] = 0.0;
                } else if (fabs(A[p][q]) > thresh) {
                    // Calculate Jacobi transformation
                    h = w[q] - w[p];
                    if (fabs(h) + g == fabs(h)) {
                        t = A[p][q] / h;
                    } else {
                        theta = 0.5 * h / A[p][q];
                        if (theta < 0.0)
                            t = -1.0 / (sqrt(1.0 + SQR(theta)) - theta);
                        else
                            t = 1.0 / (sqrt(1.0 + SQR(theta)) + theta);
                    }
                    c = 1.0 / sqrt(1.0 + SQR(t));
                    s = t * c;
                    z = t * A[p][q];

                    // Apply Jacobi transformation
                    A[p][q] = 0.0;
                    w[p] -= z;
                    w[q] += z;
                    for (int r = 0; r < p; r++) {
                        t = A[r][p];
                        A[r][p] = c * t - s * A[r][q];
                        A[r][q] = s * t + c * A[r][q];
                    }
                    for (int r = p + 1; r < q; r++) {
                        t = A[p][r];
                        A[p][r] = c * t - s * A[r][q];
                        A[r][q] = s * t + c * A[r][q];
                    }
                    for (int r = q + 1; r < n; r++) {
                        t = A[p][r];
                        A[p][r] = c * t - s * A[q][r];
                        A[q][r] = s * t + c * A[q][r];
                    }

                    // Update eigenvectors
#ifndef EVALS_ONLY
                    for (int r = 0; r < n; r++) {
                        t = Q[r][p];
                        Q[r][p] = c * t - s * Q[r][q];
                        Q[r][q] = s * t + c * Q[r][q];
                    }
#endif
                }
            }
    }

    return -1;
}

#undef SQR

} // namespace StressFieldRepresentation
