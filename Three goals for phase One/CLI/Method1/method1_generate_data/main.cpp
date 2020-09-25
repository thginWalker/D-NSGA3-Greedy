#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include <fstream>
#include <iostream>
using namespace std;

#define M 500
#define N 2000
int tasknum, agentnum, rat;


void init()
{
	ifstream configure("config.ini");
	if (!configure) {
		cout << "config.ini file is not find." << endl;
		return;
	}
	string dummy;
	configure >> dummy >> dummy >> agentnum;
	configure >> dummy >> dummy >> tasknum;
	configure.close();
	//	agentnum = 5;
	//	tasknum = 10;
	rat = tasknum / agentnum;
}


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
Agent agt[M];	
Task tsk[N];	
bool flag[N];	
int sol[M][N];	
double fvalue;	
double f[4];	

int randInt(int a, int b)
{
	return a + rand() % (b - a + 1);	
}

double randDouble(double a, double b)
{
	return a + (rand() % 10000) * 1.0 / 10000 * (b - a);
}



void selectTasks(int id, int n, int idx[], int start)
{
	int i;
	for (i = 0; i < tasknum; i++) flag[i] = false;
	for (i = 0; i < start; i++)
		flag[agt[id].tsks[i]] = true;
	i = start;
	while (i < n)
	{
		int t = rand() % tasknum;
		if (flag[t] == false)
		{
			idx[i] = t;
			i++;
			flag[t] = true;
		}
	}
}

//随机排列 
void randPermutation(int p[], int m)
{
	int i;
	for (i = 0; i < m; i++) p[i] = i;
	for (i = 0; i < m; i++)
	{
		int v = p[i];
		int idx = i + rand() % (m - i);
		p[i] = p[idx];
		p[idx] = v;
	}
}

void divTasks(int p)
{
	int tk[N];
	int i;
	randPermutation(tk, tasknum);	
	for (i = 0; i < tasknum; i++)	
	{
		int j = i / p;
		int k = i % p;
		agt[j].tsks[k] = tk[i];
	}
}

//产生智能体 
void genAgent()
{
	int i, j;
	int aMOD = 100;

	ofstream fout;
	fout.open("data//agents.txt");
	divTasks(rat);
	for (i = 0; i < agentnum; i++)
	{
		agt[i].x = rand() % aMOD; 
		agt[i].y = rand() % aMOD;
		agt[i].res = 500;
		agt[i].tskn = 5;
		selectTasks(i, 5, agt[i].tsks, rat);
		fout << agt[i].x << " " << agt[i].y << " " << agt[i].res << " " << agt[i].tskn << endl;
		for (j = 0; j < agt[i].tskn; j++)
		{
			fout << agt[i].tsks[j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

bool genTask()
{
	int i, j;
	ofstream fout;
	fout.open("data//tasks.txt");
	int tMOD = 100;
	int rat = tasknum / agentnum;

	for (i = 0; i < tasknum; i++)
	{
		tsk[i].x = rand() % tMOD;
		tsk[i].y = rand() % tMOD;
		tsk[i].start_t = randInt(0, 100);
		tsk[i].end_t = randDouble(tsk[i].start_t, 150);
		tsk[i].res_cost = randDouble(0, 100);
		tsk[i].time_cost = randInt(1, 10);
		tsk[i].gain = randDouble(0, 1);
		tsk[i].agtn = 0;
	}
	for (i = 0; i < agentnum; i++)
	{
		for (j = 0; j < agt[i].tskn; j++)
		{
			int t = agt[i].tsks[j];
			tsk[t].agts[tsk[t].agtn++] = i;
		}
	}
	for (i = 0; i < tasknum; i++)
	{
		if (tsk[i].agtn == 0)
		{
			printf("nonononon\n");
			return false;
		}
		fout << tsk[i].x << " " << tsk[i].y << " " << tsk[i].start_t << " " << tsk[i].end_t << " " << tsk[i].res_cost << " " << tsk[i].time_cost << " " << tsk[i].gain << " " << tsk[i].agtn << endl;
		for (j = 0; j < tsk[i].agtn; j++)
		{
			fout << tsk[i].agts[j] << " ";
		}
		fout << endl;
	}
	fout.close();
	return true;
}

int main()
{
	srand(unsigned(time(0)));
	bool flag = true;

	init();
	while (flag)
	{
		genAgent();
		if (genTask()) flag = false;
	}

	return 0;
}