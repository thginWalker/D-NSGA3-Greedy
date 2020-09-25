#include "alg_population.h"
#include "update_chromosome.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

#include "problem_base.h"
#include "print_data.h"
#define MA 3000
using namespace std;

class CPopulation;


void UpdateChromosome::loadUpdateEnvironment(int number)
{

	ifstream renewal;
	string filename = "info\\agent" + to_string(number) + ".txt";
	renewal.open(filename);
	if (!renewal) {
		cout << filename << " file is not find" << endl;
		return;
	}
	string dummp;
	renewal >> dummp >> cutagentnum;
	for (int i = 0; i < cutagentnum; i++)
	{
		renewal >> ctagt[i];
	}
	renewal >> dummp >> addagentnum;
	for (int i = 0; i < addagentnum; i++)
	{
		renewal >> adagt[i].id
			>> adagt[i].x
			>> adagt[i].y
			>> adagt[i].res
			>> adagt[i].tskn;
		for (int j = 0; j < adagt[i].tskn; j++)
			renewal >> adagt[i].tsks[j];
		adagt[i].exist = true;//Ĭ�ϴ���
	}
	renewal.close();
	filename = "info\\tasks" + to_string(number) + ".txt";
	renewal.open(filename);
	if (!renewal) {
		cout << filename << " file is not find" << endl;
		return;
	}
	renewal >> dummp >> cutasknum;
	for (int i = 0; i < cutasknum; i++)
	{
		renewal >> ctskn[i];
	}
	renewal >> dummp >> addtasknum;
	for (int i = 0; i < addtasknum; i++)
	{
		renewal >> adtsk[i].id
			>> adtsk[i].x
			>> adtsk[i].y
			>> adtsk[i].start_t
			>> adtsk[i].end_t
			>> adtsk[i].res_cost
			>> adtsk[i].time_cost
			>> adtsk[i].gain
			>> adtsk[i].agtn;
		for (int j = 0; j < adtsk[i].agtn; j++)
			renewal >> adtsk[i].agts[j];
		adtsk[i].exist = true;//Ĭ�ϴ���
	}
	renewal.close();

}


void UpdateChromosome::updateChromosome(CPopulation* prob, CProblemSelf* problem)
{
	//ͨ�������Ϣ��ʼ��map����ӳ��
	//˼·:0.���ȴ洢ԭȾɫ����Ϣ(��ʵ0��1���Ժϲ�������ʱ�临�Ӷȸ�)
	//	1.�޸�ԭ���洢������������Ϣ(ע��1������0֮��)
	//	2.��ӳ��map�����޸�
	//	3.����Ⱦɫ����Ϣ

	map<int, pair<bool,vector<int> > > mapping[MA];
	//���д洢�ռ�ĳ�ʼ��
	for (size_t i = 0; i < (*prob).size(); i += 1)
	{
		int n = 0;
		

		for (int j = 0; j < (*problem).num_agent; j++)
		{
			pair <bool, vector<int> > pa;
			if ((*problem).agt[j].exist)
			{
				for (int k = n; k < n + (*problem).agt[j].tskn; k++)
				{
					pa.second.push_back((*prob)[i].vars()[k]);
				}
				n = n + (*problem).agt[j].tskn;
				pa.first = true;
			}
			else {
				pa.first = false;
				pa.second.resize(0);
			}

			mapping[i][j] = pa;
		}
	}

	//�޸�ԭ���洢������������Ϣ(ע��1������0֮��)
	//0.ɾ��������
	for (int j = 0; j < cutagentnum; j++)
	{	

		for (int k = 0; k < (*problem).num_task; k++)
		{
			if ((*problem).tsk[k].exist)
			{
				int num = 0;
				for (int m = 0; m < (*problem).tsk[k].agtn; m++)
				{
					if ((*problem).tsk[k].agts[m] == ctagt[j])
					{
						num++;
					}
					else {
						(*problem).tsk[k].agts[m - num] = (*problem).tsk[k].agts[m];
					}
				}
				(*problem).tsk[k].agtn -= num;
			}
		}

		(*problem).agt[ctagt[j]].exist = false;
		(*problem).agt[ctagt[j]].tskn = 0;
		(*problem).agt[ctagt[j]].res = 0;
	}
	//1.ɾ������
	for (int j = 0; j < cutasknum; j++)
	{  
		for (int k = 0; k < (*problem).num_agent; k++)
		{
			if ((*problem).agt[k].exist)
			{
				int num = 0;
				for (int m = 0; m < (*problem).agt[k].tskn; m++)
				{
					if ((*problem).agt[k].tsks[m] == ctskn[j])
					{
						num++;
					}else {
						(*problem).agt[k].tsks[m - num] = (*problem).agt[k].tsks[m];
					}
				}
				(*problem).agt[k].tskn -= num;
			}
		}

		(*problem).tsk[ctskn[j]].exist = false;
		(*problem).tsk[ctskn[j]].agtn = 0;
		(*problem).tsk[ctskn[j]].gain = 0;
		(*problem).tsk[ctskn[j]].res_cost = 1000;
	}
	//2.����������
	for (int j = 0; j < addagentnum; j++)
	{	
		for (int k = 0; k < adagt[j].tskn; k++)
		{
			if ((*problem).tsk[adagt[j].tsks[k]].exist)
			{
				(*problem).tsk[adagt[j].tsks[k]].agts[(*problem).tsk[adagt[j].tsks[k]].agtn++] = adagt[j].id;
			}
		}

		(*problem).agt[adagt[j].id] = adagt[j];
		(*problem).num_agent += 1;
	}

	for (int j = 0; j < addtasknum; j++)
	{	
		for (int m = 0; m < adtsk[j].agtn; m++)
		{
			if ((*problem).agt[adtsk[j].agts[m]].exist)
			{
				(*problem).agt[adtsk[j].agts[m]].tsks[(*problem).agt[adtsk[j].agts[m]].tskn++] = adtsk[j].id;
			}
		}

		(*problem).tsk[adtsk[j].id] = adtsk[j];
		(*problem).num_task += 1;
	}


	for (size_t i = 0; i < (*prob).size(); i += 1)
	{	
		for (int j = 0; j < cutagentnum; j++)
		{
			mapping[i][ctagt[j]].first = false;
			mapping[i][ctagt[j]].second.clear();
		}
	}

	//ɾ������, ��Ⱦɫ���и�������ɾ��
	for (size_t i = 0; i < (*prob).size(); i += 1)
	{
		for (int j = 0; j < cutasknum; j++)
		{
			for (int k = 0; k < mapping[i].size(); k++)
			{
				if (mapping[i][j].first)
				{
					vector<int>::iterator ite = mapping[i][k].second.begin();
					while (ite != mapping[i][k].second.end())
					{
						if (*ite == ctskn[j])
						{
							ite = mapping[i][k].second.erase(ite);
						}
						else ++ite;
					}
				}
			}
		}
	}

	//����������
	for (size_t i = 0; i < (*prob).size(); i += 1)
	{
		for (int j = 0; j < addagentnum; j++)
		{ 
			mapping[i][adagt[j].id].first = true;
			vector <int> ve;
			for (int k = 0; k < adagt[j].tskn; k++)
				ve.push_back(adagt[j].tsks[k]);
			mapping[i][adagt[j].id].second = ve;

		}
	}

	for (size_t i = 0; i < (*prob).size(); i += 1)
	{
		for (int j = 0; j < addtasknum; j++)
		{

			for (int m = 0; m < adtsk[j].agtn; m++)
			{
				if ((*problem).agt[adtsk[j].agts[m]].exist)
				{
					mapping[i][adtsk[j].agts[m]].second.push_back(adtsk[j].id);
				}
			}

		}
	}


	for (size_t i = 0; i < (*prob).size(); i += 1)
	{	
		vector<int> ve;
		for (int j = 0; j < mapping[i].size(); j++)
		{
			if (mapping[i][j].first)
			{

				for (int k = 0; k < mapping[i][j].second.size(); k++)
				{
					ve.push_back(mapping[i][j].second[k]);
				}
			}
		}
		(*prob)[i].vars() = ve;
		ve.clear();
	}


 }