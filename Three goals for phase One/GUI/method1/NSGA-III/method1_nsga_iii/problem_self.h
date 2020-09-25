#ifndef PROBLEM_SELF__
#define PROBLEM_SELF__
#define N 5000//������Ŀ
#define M 500//��������
#include "problem_base.h"

//������
struct Agent
{
	double x;//λ�� x  (x,y)
	double y;//λ�� y
	double res;//��Դ
	int tsks[N];//�����������Ҫִ�е���������
	int tskn;//�����������Ҫִ�е��������
};

//����
struct Task
{
	double x;//λ��_x; (x,y)
	double y;//λ��_y;
	double start_t;//���翪ʼʱ��
	double end_t;//����ʼʱ��
	double time_cost;//����ʱ������
	double res_cost;//������Դ����
	double gain;//��������
	int agtn;//�����������Ա�ִ�е�����������
	int agts[M];//�����������Ա���Щ������ִ��
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