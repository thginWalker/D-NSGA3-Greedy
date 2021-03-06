#ifndef BASE_PROBLEM__
#define BASE_PROBLEM__



#include <string>
#include <vector>

// ----------------------------------------------------------------------
//		BProblem: 2blems (e.g. ZDT and DTLZ)
// ----------------------------------------------------------------------
class CIndividual;



class BProblem
{
public:
	explicit BProblem(const std::string& name) :name_(name) {}

	virtual ~BProblem() {}


	virtual std::size_t num_variables() const = 0;
	virtual std::size_t num_objectives() const = 0;
	virtual bool Evaluate(CIndividual* indv) const = 0;


	const std::string& name() const { return name_; }
	const std::vector<double>& lower_bounds() const { return lbs_; }//获取变量下限
	const std::vector<double>& upper_bounds() const { return ubs_; }//获取变量上限

protected:
	std::string name_;

	std::vector<double> lbs_,
		ubs_;
};

#endif