#include "problem_self.h"
#include "alg_individual.h"
#include <iostream>
#include <fstream>
using namespace std;


CProblemSelf::CProblemSelf(std::size_t num_a, std::size_t num_t) :
	BProblem("Self"), num_objs_(4)
{
	num_agent = num_a;	num_task = num_t;	
	loadEnvironment(num_agent, num_task);	
	int n = 0;
	for (int i = 0; i < num_agent; i++) {
		n = n + agt[i].tskn;
	}
	num_vars_ = n;	
	lbs_.resize(num_vars_, 0);	
	ubs_.resize(num_vars_, num_vars_);
}

void CProblemSelf::loadChange(std::size_t num_a, std::size_t num_t)
{
	num_agent = num_a;	num_task = num_t;	int n = 0;
	for (int i = 0; i < num_agent; i++) {
		n = n + agt[i].tskn;
	}
	num_vars_ = n;	lbs_.resize(num_vars_, 0);	ubs_.resize(num_vars_, num_vars_);
}

void CProblemSelf::loadEnvironment(int num_a, int num_t) {
	string filename = "files\\agent.txt";
	fstream f(filename, ios::in);
	if (!f) {
		cout << "./files/agents.txt is not find" << endl;
		return;
	}
	for (int i = 0; i < num_a; i++)
	{
		f >> agt[i].id
			>> agt[i].x
			>> agt[i].y
			>> agt[i].res
			>> agt[i].tskn;
		for (int j = 0; j < agt[i].tskn; j++) {
			f >> agt[i].tsks[j];
		}
		agt[i].exist = true;
	}
	f.close();
	f.open("files\\tasks.txt", ios::in);
	if (!f) {
		cout << "./files/agents.txt is not find" << endl;
		return;
	}
	for (int i = 0; i < num_t; i++)
	{
		f >> tsk[i].id
			>> tsk[i].x
			>> tsk[i].y
			>> tsk[i].start_t
			>> tsk[i].end_t
			>> tsk[i].res_cost
			>> tsk[i].time_cost
			>> tsk[i].gain
			>> tsk[i].agtn;
		for (int j = 0; j < tsk[i].agtn; j++)
		{
			f >> tsk[i].agts[j];
		}
		tsk[i].exist = true;
	}
	f.close();
}


bool CProblemSelf::Evaluate(CIndividual* indv) const
{
	CIndividual::TDecVec& x = indv->vars();
	CIndividual::TObjVec& f = indv->objs();
	CIndividual::TObjVec& acutal_f = indv->actual_objs();
	vector<int> flag(num_task + 1, 0);

	if (x.size() != num_vars_) return false;
	double max_gain = 0;	for (int i = 0; i < num_task; i++)
	{
		flag[i] = 0;
		max_gain = max_gain + tsk[i].gain;
	}
	f[0] = 1.0;
	f[1] = 1.0;
	f[2] = 0;
	f[3] = 0;	int n = 0;
	for (int i = 0; i < num_agent; i++) {
		if (agt[i].exist) {
			double cur_x = agt[i].x;
			double cur_y = agt[i].y;			
			int cur_tsk = -1;			
			double larrive_time = 0;			
			double last_cost = 0;			
			double tsum = 0;			
			for (int j = n; j < n + agt[i].tskn; j++) {
				if (flag[x[j]] == 0 && tsk[x[j]].exist) {
					double travel_time = sqrtf((tsk[x[j]].x - cur_x) * (tsk[x[j]].x - cur_x) + (tsk[x[j]].y - cur_y) * (tsk[x[j]].y - cur_y));					
					double travel_cost = travel_time;					
					double cost_time = 0;					
					double begin_time = 0;					
					double do_cost = tsk[x[j]].res_cost;					
					if (cur_tsk < 0) {
						cost_time = 0;
						begin_time = 0;
					}
					else {
						cost_time = tsk[cur_tsk].time_cost;						
						if (larrive_time < tsk[cur_tsk].start_t) {
							begin_time = tsk[cur_tsk].start_t;
						}
						else begin_time = larrive_time;
					}
					double arrival_time = begin_time + cost_time + travel_time;
					double total_cost = do_cost + travel_cost + last_cost;

					if ((arrival_time <= tsk[x[j]].end_t) && (total_cost <= agt[i].res))
					{
						f[0] = f[0] - 1.0 / num_task; 						
						f[1] = f[1] - tsk[x[j]].gain / max_gain; 						
						f[2] = f[2] + (travel_cost + tsk[x[j]].res_cost) / (500 * num_agent); 						
						if (arrival_time > tsk[x[j]].start_t) {
							tsum += travel_time + tsk[x[j]].time_cost;
						}
						else tsum += (tsk[x[j]].start_t - arrival_time) + travel_time + tsk[x[j]].time_cost;						cur_x = tsk[x[j]].x;						cur_y = tsk[x[j]].y;
						cur_tsk = x[j];
						larrive_time = arrival_time;
						last_cost = total_cost;
						flag[x[j]] = 1;
					}
				}
			}
			n = n + agt[i].tskn; 			
			if (tsum > f[3]) 				
				f[3] = tsum;
		}
	}
	f[3] = f[3] / 160; 	
	return true;
}