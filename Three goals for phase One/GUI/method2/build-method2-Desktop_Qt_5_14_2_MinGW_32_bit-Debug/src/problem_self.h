#ifndef PROBLEM_SELF__
#define PROBLEM_SELF__
#define N 5000
#define M 800
#include "problem_base.h"

struct Agent
{
	double x;
	double y;
	double res;
	int tsks[N];
	int tskn;
	//新增属性
	int id;//id号
	bool exist;
};

//任务
struct Task
{
	double x;
	double y;
	double start_t;
	double end_t;
	double time_cost;
	double res_cost;
	double gain;
	int agtn;
	int agts[M];
	//新增属性
	int id;
	bool exist;
};




class CProblemSelf : public BProblem
{
public:

	CProblemSelf(std::size_t num_vars, std::size_t num_objs);
	void loadChange(std::size_t num_vars, std::size_t num_objs);

	virtual std::size_t num_variables() const { return num_vars_; }
	virtual std::size_t num_objectives() const { return num_objs_; }
	virtual bool Evaluate(CIndividual *indv) const;
	virtual void loadEnvironment(int num_a,int num_t);
	Agent agt[M];
	Task tsk[N];
	int num_agent;
	int num_task;
	int atcnt[M];
private:

	std::size_t num_vars_, num_objs_;

};

#endif