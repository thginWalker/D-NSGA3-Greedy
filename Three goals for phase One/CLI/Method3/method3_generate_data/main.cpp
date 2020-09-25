#include"generate.h"

using namespace std;


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
 
	for (int i = 0; i < 5; i++)//假设更改5次的信息
	{
		cout << "i=" << i << endl;
		dynamicAgent(i);
		dynamicTask(i);
	}


	return 0;
}