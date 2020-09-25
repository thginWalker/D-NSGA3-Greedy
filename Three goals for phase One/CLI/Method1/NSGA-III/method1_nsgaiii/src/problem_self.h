#ifndef PROBLEM_SELF__
#define PROBLEM_SELF__
#define N 5000//任务数目
#define M 500//智能体数
#include "problem_base.h"

//智能体
struct Agent
{
	double x;//位置 x  (x,y)
	double y;//位置 y
	double res;//资源
	int tsks[N];//定义该智能体要执行的任务序列
	int tskn;//定义该智能体要执行的任务个数
};

//任务
struct Task
{
	double x;//位置_x; (x,y)
	double y;//位置_y;
	double start_t;//最早开始时间
	double end_t;//最晚开始时间
	double time_cost;//任务时间消耗
	double res_cost;//任务资源消耗
	double gain;//任务收益
	int agtn;//定义该任务可以被执行的智能体序列
	int agts[M];//定义该任务可以被哪些智能体执行
};




class CProblemSelf : public BProblem
{
public:

	CProblemSelf(std::size_t num_vars, std::size_t num_objs);

	virtual std::size_t num_variables() const { return num_vars_; }
	virtual std::size_t num_objectives() const { return num_objs_; }
	virtual bool Evaluate(CIndividual* indv) const;
	virtual void loadEnvironment(int num_a, int num_t);
	Agent agt[M];
	Task tsk[N];
	int num_agent;
	int num_task;
private:

	std::size_t num_vars_, num_objs_;

};

#endif