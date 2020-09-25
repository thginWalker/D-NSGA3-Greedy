#include "generate.h"

using namespace std;


int tasknum;
int agentnum;
int rat;

double addagent;
double addtasks;
double cutagent;
double cuttasks;


Agent agt[M];	
Task tsk[N];	
bool flag[N];	
int sol[M][N];	
double fvalue;	
double f[4];	
 
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
	configure >> dummy >> dummy >> addagent;
	configure >> dummy >> dummy >> addtasks;
	configure >> dummy >> dummy >> cutagent;
	configure >> dummy >> dummy >> cuttasks;
	addagent = round(addagent * agentnum);
	addtasks = round(addtasks * tasknum);
	cutagent = round(cutagent * agentnum);
	cuttasks = round(cuttasks * tasknum);;
	configure.close();
	rat = tasknum / agentnum;
}

int randInt(int a, int b)//C++ rand()���� 
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
	i = start;//��i = start = ���� 
	while (i < n)
	{
		unsigned int t = rand() % tasknum;
		if (flag[t] == false)
		{
			idx[i] = t;
			i++;
			flag[t] = true;
		}
	}
}


//������� 
void randPermutation(int p[], int m)
{
	int i;
	for (i = 0; i < m; i++) p[i] = i;
	for (i = 0; i < m; i++)
	{//������� 
		int v = p[i];
		int idx = i + rand() % (m - i);
		p[i] = p[idx];
		p[idx] = v;
	}
}
 
void addRandPermutation(int p[], int m)
{
	int i;
	for (i = tasknum; i < m; i++) p[i] = i;
	for (i = tasknum; i < m; i++)
	{//������� 
		int v = p[i];
		int idx = i + rand() % (m - i);
		p[i] = p[idx];
		p[idx] = v;
	}
}


void divTasks(int p)
{
	int tk[N] ;
	int i;
	randPermutation(tk, tasknum);
	for (i = 0; i < tasknum; i++)
	{
		int j = i / p;
		int k = i % p;
		agt[j].tsks[k] = tk[i];
	}
}


void genAgent()
{
	int i, j;
	ofstream fout;
	string filename = "./files/agent.txt";
	fout.open(filename);
	divTasks(rat);
	for (i = 0; i < agentnum; i++)
	{
		agt[i].id = i;
		agt[i].x = randInt(0, 100);
		agt[i].y = randInt(0, 100);
		agt[i].res = 500;
		agt[i].tskn = 5 + randInt(5, 15);
		selectTasks(i, agt[i].tskn, agt[i].tsks, rat);
		fout << agt[i].id << " " << agt[i].x << " " << agt[i].y << " " << agt[i].res << " " << agt[i].tskn << endl;
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
	string filename = "./files/tasks.txt";
	fout.open(filename);
	int rat = tasknum / agentnum;
	int aMOD = 100;
	for (i = 0; i < tasknum; i++)
	{
		tsk[i].id = i;
		tsk[i].x = rand() % aMOD;
		tsk[i].y = rand() % aMOD;
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
		fout << tsk[i].id << " " << tsk[i].x << " " << tsk[i].y << " " << tsk[i].start_t << " " << tsk[i].end_t << " " << tsk[i].res_cost << " " << tsk[i].time_cost << " " << tsk[i].gain << " " << tsk[i].agtn << endl;
		for (j = 0; j < tsk[i].agtn; j++)
		{
			fout << tsk[i].agts[j] << " ";
		}
		fout << endl;
	}
	fout.close();

	return true;
}


////////////////////////////////////////////////////
//��������� 
void addAgent(ofstream& ifile)
{
	divTasks(rat);
	ifile << "addnum: " << addagent << endl;
	for (int i = 0; i < addagent; i++)//������Ϣ
	{

		int s = agentnum + i;//id���к�
		agt[s].id = s;
		agt[s].x = randInt(0, 100);
		agt[s].y = randInt(0, 100);
		agt[s].res = 500;//0.2~1.0;
		agt[s].tskn = 5 + randInt(5, 15);
		selectTasks(s, agt[s].tskn, agt[s].tsks, 0);
		ifile << agt[s].id << " "
			<< agt[s].x << " "
			<< agt[s].y << " "
			<< agt[s].res << " "
			<< agt[s].tskn << endl;
		for (int j = 0; j < agt[s].tskn; j++)
		{
			ifile << agt[s].tsks[j] << " ";
		}
		ifile << endl;
	}
	agentnum += addagent;//�ı���������Ŀ

}

//�������
bool addTask(ofstream& ifile)
{

	int i, j;
	ifile << "addnum: " << addtasks << endl;
	for (int i = 0; i < addtasks; i++)
	{
		int s = tasknum + i;//id���к�
		tsk[s].id = s;
		tsk[s].x = randInt(0, 100);
		tsk[s].y = randInt(0, 100);
		tsk[s].start_t = randInt(0, 100);
		tsk[s].end_t = randDouble(tsk[i].start_t, 150);
		tsk[s].res_cost = randDouble(0, 100);
		tsk[s].time_cost = randInt(1, 10);
		tsk[s].gain = randDouble(0, 1);
		tsk[s].agtn = 0;
	}

	for (int k = 0; k < addtasks; k++)
	{
		int s = tasknum + k;
		int carry = randInt(2, 8);
		tsk[s].agtn = carry;//���������������ִ��������
		for (int k = 0; k < carry; k++)
		{
			tsk[s].agts[k] = randInt(1, agentnum);
		}
		ifile << tsk[s].id << " "
			<< tsk[s].x << " "
			<< tsk[s].y << " "
			<< tsk[s].start_t << " "
			<< tsk[s].end_t << " "
			<< tsk[s].res_cost << " "
			<< tsk[s].time_cost << " "
			<< tsk[s].gain << " "
			<< tsk[s].agtn << endl;
		for (j = 0; j < tsk[s].agtn; j++)
		{
			ifile << tsk[s].agts[j] << " ";
		}
		ifile << endl;
	}
	tasknum += addtasks;//��������̬���
	ifile.close();
	return true;
}

//������̬��ɾ������
void dynamicAgent(int number)
{
	//��ɾ������
	ofstream fout;
	string filename = "./info/agent" + to_string(number) + ".txt";

	fout.open(filename);//�½��ļ� 
	fout << "removenum: " << cutagent << endl;
	for (int i = 0; i < cutagent; i++)//ɾ����Ϣ
	{
		fout << randInt(0, agentnum) << " ";

	}
	fout << endl;

	addAgent(fout);
	fout.close();
}

//������̬��ɾ����
void dynamicTask(int number)
{
	//��ɾ����
	int addnum = (int)(addtasks * tasknum);
	ofstream fout;
	string filename = "./info/tasks" + to_string(number) + ".txt";
	fout.open(filename);//�½��ļ� 
	fout << "removenum: " << cuttasks << endl;
	for (int i = 0; i < cuttasks; i++)//ɾ����Ϣ
	{
		fout << randInt(0, tasknum) << " ";
	}
	fout << endl;

	addTask(fout);
	fout.close();
}
