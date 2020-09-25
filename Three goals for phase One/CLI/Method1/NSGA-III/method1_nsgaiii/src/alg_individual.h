#ifndef INDIVIDUAL__
#define INDIVIDUAL__

#include <vector>
#include <ostream>

// ----------------------------------------------------------------------
//		CIndividual
// ----------------------------------------------------------------------

class BProblem;

class CIndividual
{
public:

	typedef int TGene;
	typedef std::vector<TGene> TDecVec;
	typedef std::vector<double> TObjVec;

	explicit CIndividual(std::size_t num_vars = 0, std::size_t num_objs = 0);


	TDecVec& vars() { return variables_; }

	const TDecVec& vars() const { return variables_; }

	TObjVec& objs() { return objectives_; }
	const TObjVec& objs() const { return objectives_; }


	TObjVec& conv_objs() { return converted_objectives_; }
	const TObjVec& conv_objs() const { return converted_objectives_; }


	static void SetTargetProblem(const BProblem& p) { target_problem_ = &p; }//将其目标问题赋值给target_problem
	static void removedup(CIndividual* ind, int agtnum);
	static const BProblem& TargetProblem();

private:
	TDecVec variables_;
	TObjVec objectives_;
	TObjVec converted_objectives_;

	static const BProblem* target_problem_;
};


std::ostream& operator << (std::ostream& os, const CIndividual& indv);

#endif
