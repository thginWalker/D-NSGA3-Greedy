
#ifndef CROSSOVER__
#define CROSSOVER__

// ----------------------------------------------------------------------------------
//		CSimulatedBinaryCrossover : simulated binary crossover (SBX) ģ������ƽ���
// ----------------------------------------------------------------------------------


class CIndividual;
class CProblemSelf;
class CCrossover
{
public:
	explicit CCrossover(double cr = 1.0):cr_(cr){} // NSGA-III (t-EC 2014) setting   NSGA-III(2014)���õı���

	void SetCrossoverRate(double cr) { cr_ = cr; }
	double CrossoverRate() const { return cr_; }
	void removedup(CIndividual *ind, const int agtnum);
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, CProblemSelf &prob,double cr) const;
	bool operator()(CIndividual *c1, CIndividual *c2, const CIndividual &p1, const CIndividual &p2, CProblemSelf &prob) const
	{
		return operator()(c1, c2, p1, p2, prob, cr_);//(Ĭ��cr_)
	}

private:

	double cr_; // crossover rate
};


#endif 