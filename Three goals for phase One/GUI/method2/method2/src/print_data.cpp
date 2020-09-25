#include"print_data.h"


using namespace std;

void Print::PrintAgent(CProblemSelf** prob)
{
	cout << "=========PrintAgent================" << endl;
	cout << "agent:" << (*prob)->num_agent << endl;
	cout << "task:" << (*prob)->num_task << endl;
	cout << "output:" << endl;
	for (int i = 0; i < (*prob)->num_agent; i++)
	{
		cout << (*prob)->agt[i].id << " "
			<< (*prob)->agt[i].x << " "
			<< (*prob)->agt[i].y << " "
			<< (*prob)->agt[i].res << " "
			<< (*prob)->agt[i].tskn << endl;
		for (int j = 0; j < (*prob)->agt[i].tskn; j++)
		{
			cout << (*prob)->agt[i].tsks[j] << " ";
		}
		cout << endl;
	}
	cout << "=========================" << endl;
}

void Print::PrintTasks(CProblemSelf** prob)
{
	cout << "===========printTasks==============" << endl;
	cout << "agent:" << (*prob)->num_agent << endl;
	cout << "task:" << (*prob)->num_task << endl;
	cout << "output:" << endl;

	for (int i = 0; i < (*prob)->num_task; i++)
	{
		cout << (*prob)->tsk[i].id << " "
			<< (*prob)->tsk[i].x << " "
			<< (*prob)->tsk[i].y << " "
			<< (*prob)->tsk[i].start_t << " "
			<< (*prob)->tsk[i].end_t << " "
			<< (*prob)->tsk[i].res_cost << " "
			<< (*prob)->tsk[i].time_cost << " "
			<< (*prob)->tsk[i].gain << " "
			<< (*prob)->tsk[i].agtn << endl;
		for (int j = 0; j < (*prob)->tsk[i].agtn; j++)
		{
			cout << (*prob)->tsk[i].agts[j] << " ";
		}
		cout << endl;
	}
	cout << "=========================" << endl;
}


void Print::PrintAgent(CProblemSelf& prob)
{
	cout << "=========PrintAgent================" << endl;
	cout << "agent:" << prob.num_agent << endl;
	cout << "task:" << prob.num_task << endl;
	cout << "output:" << endl;
	for (int i = 0; i < prob.num_agent; i++)
	{
		cout << prob.agt[i].id << " "
			<< prob.agt[i].x << " "
			<< prob.agt[i].y << " "
			<< prob.agt[i].res << " "
			<< prob.agt[i].tskn << endl;
		for (int j = 0; j < prob.agt[i].tskn; j++)
		{
			cout << prob.agt[i].tsks[j] << " ";
		}
		cout << endl;
	}
	cout << "=========================" << endl;
}

void Print::PrintTasks(CProblemSelf& prob)
{
	cout << "===========printTasks==============" << endl;
	cout << "agent:" << prob.num_agent << endl;
	cout << "task:" << prob.num_task << endl;
	cout << "output:" << endl;

	for (int i = 0; i < prob.num_task; i++)
	{
		cout << prob.tsk[i].id << " "
			<< prob.tsk[i].x << " "
			<< prob.tsk[i].y << " "
			<< prob.tsk[i].start_t << " "
			<< prob.tsk[i].end_t << " "
			<< prob.tsk[i].res_cost << " "
			<< prob.tsk[i].time_cost << " "
			<< prob.tsk[i].gain << " "
			<< prob.tsk[i].agtn << endl;
		for (int j = 0; j < prob.tsk[i].agtn; j++)
		{
			cout << prob.tsk[i].agts[j] << " ";
		}
		cout << endl;
	}
	cout << "=========================" << endl;
}

void Print::PrintChromosome(CPopulation* prob)
{
	for (size_t i = 0; i < (*prob).size(); i += 1) {

		for (size_t v = 0; v < (*prob)[i].vars().size(); v += 1)			cout << (*prob)[i].vars()[v] << ' ';
		cout << endl;
	}
}

void Print::PrintObject(CPopulation* prob)
{
	for (unsigned int i = 0; i < (*prob).size(); i++)
	{
		for (size_t f = 0; f < (*prob)[i].objs().size(); f += 1)
		{
			cout << (*prob)[i].objs()[f] << " ";
		}
		cout << endl;
	}
}

