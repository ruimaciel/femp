#ifndef PROCESSED_MODEL_HPP
#define PROCESSED_MODEL_HPP

#include <map>
#include <Eigen/Core>
#include <Eigen/Sparse>

#include "fem/Node.h++"


/*
Storage class designed to hold all data resulting from the FEM analysis of a given model
*/
class ProcessedModel
{
	public:
		std::map<size_t, fem::Node> displacements_map;

		// the FEM equation 
		Eigen::DynamicSparseMatrix<double,Eigen::RowMajor> k;
		Eigen::Matrix<double,Eigen::Dynamic,1> f;
		Eigen::Matrix<double,Eigen::Dynamic,1> d;

	public:
		ProcessedModel();
		~ProcessedModel();
};

#endif

