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

	return 0;
}