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
	//用typedef为现有类型创建别名
	typedef int TGene;
	typedef std::vector<TGene> TDecVec;
	typedef std::vector<double> TObjVec;

	explicit CIndividual(std::size_t num_vars = 0, std::size_t num_objs = 0);

	TDecVec & vars() { return variables_; }
	
	const TDecVec & vars() const { return variables_; }
	
	TObjVec & objs() { return objectives_; }
	const TObjVec & objs() const { return objectives_; }
	///////////
	TObjVec& actual_objs() { return actual_objectives_; }
	const TObjVec& actual_objs() const { return actual_objectives_; }
	//////////

	TObjVec & conv_objs() { return converted_objectives_; }
	void clone(CIndividual x);
	double getFvalue(double w[]);
	const TObjVec & conv_objs() const { return converted_objectives_; }

	static void SetTargetProblem(const BProblem &p) { target_problem_ = &p; }

	static void loadTargetProblem(BProblem& p) { target_problem_ = &p; }

	static void removedup(CIndividual * ind, int agtnum);
	static const BProblem & TargetProblem();
	
	private:
		TDecVec variables_;
		TObjVec objectives_;

		TObjVec actual_objectives_;
	
		TObjVec converted_objectives_;

	static const BProblem *target_problem_;
};

//运算符重载 <<
std::ostream & operator << (std::ostream &os, const CIndividual &indv);

#endif
