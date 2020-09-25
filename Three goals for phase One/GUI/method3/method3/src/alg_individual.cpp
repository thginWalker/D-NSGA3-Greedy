
#include "alg_individual.h"
#include "problem_base.h"
#include <vector>
using namespace std;
using std::size_t;


const BProblem * CIndividual::target_problem_ = 0;

// ----------------------------------------------------------------------
CIndividual::CIndividual(std::size_t num_vars, std::size_t num_objs):
	variables_(num_vars), 
	objectives_(num_objs),
	actual_objectives_(num_objs),
	converted_objectives_(num_objs)//CIndividual˽�б����ĳ�ʼ��
{
	if (target_problem_ != 0)
	{	
		variables_.resize(target_problem_->num_variables());
		objectives_.resize(target_problem_->num_objectives());
		actual_objectives_.resize(target_problem_->num_objectives());///
		converted_objectives_.resize(target_problem_->num_objectives());
	}
}

void CIndividual::clone(CIndividual x)
{
	for (int i = 0; i < target_problem_->num_variables(); i++)
	{
		variables_[i] = x.vars()[i];
	}

	for (int i = 0; i < target_problem_->num_objectives(); i++)
	{
		objectives_[i] = x.objs()[i];
	}
}

double CIndividual::getFvalue(double w[])
{
	double fval = 0;
	for (int i = 0; i < target_problem_->num_objectives(); i++)
	{
		fval = fval + w[i] * objectives_[i];
	}
	return fval;
}
// ----------------------------------------------------------------------

const BProblem & CIndividual::TargetProblem() { return *target_problem_; }
// ----------------------------------------------------------------------

std::ostream & operator << (std::ostream &os, const CIndividual &indv)
{
	
	for (size_t i=0; i<indv.vars().size(); i+=1)
	{
		os << indv.vars()[i] << ' ';
	}

	os << " => ";
	for (size_t f=0; f<indv.objs().size(); f+=1)
	{
		os << indv.objs()[f] << ' ';
	}

	return os;
}