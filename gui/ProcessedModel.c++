#include "ProcessedModel.h++"


ProcessedModel::ProcessedModel()
{
	U = 0;
}


ProcessedModel::ProcessedModel(const ProcessedModel &other)
{
	this->k = other.k;
	this->f = other.f;
	this->d = other.d;
	this->U = other.U;
}


ProcessedModel::~ProcessedModel()
{
}


