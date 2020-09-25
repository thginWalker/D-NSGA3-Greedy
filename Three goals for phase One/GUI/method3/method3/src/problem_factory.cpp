#include "problem_factory.h"
#include "problem_base.h"
#include <string>
using namespace std;

CProblemSelf* GenerateProblem(std::ifstream& ifile)
{

	string pname, dummy;

	ifile >> dummy >> dummy >> pname;
	if (pname == "Self")
	{
		
		size_t num_agent, num_task;

		ifile >> dummy >> dummy >> num_agent;
		ifile >> dummy >> dummy >> num_task;

		return new CProblemSelf(num_agent, num_task);
	}
	return 0;
}
