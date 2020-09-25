#ifndef PROBLEM_SELF__
#define PROBLEM_SELF__
#define N 5000
#define M 500
#include "problem_base.h"

struct Agent
{
	double x;//location x
	double y;//location y
	double res;//resources
	int tsks[N];
	int tskn;
};
struct Task
{
	double x;//location_x;
	double y;//location_y;
	double start_t;//earliest start time
	double end_t;//lastest start time
	double time_cost;
	double res_cost;
	double gain;
	int agtn;
	int agts[M];
};


// You can add your own problem here.

class CProblemSelf : public BProblem
{
public:
	CProblemSelf(std::size_t num_vars, std::size_t num_objs);

	virtual std::size_t num_variables() const { return num_vars_; }
	virtual std::size_t num_objectives() const { return num_objs_; }
	std::size_t agentNum() const {return num_agent;}
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