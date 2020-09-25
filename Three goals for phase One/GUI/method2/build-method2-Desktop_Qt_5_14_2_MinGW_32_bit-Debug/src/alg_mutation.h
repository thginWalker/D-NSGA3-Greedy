#ifndef MUTATION__
#define MUTATION__

// ----------------------------------------------------------------------------------
//		CPolynomialMutation : polynomial mutation
// ----------------------------------------------------------------------------------

class CIndividual;
class CProblemSelf;
class CMutation
{
public:
	explicit CMutation(double mr = 0.0):mr_(mr){}

	void SetMutationRate(double mr) { mr_ = mr; }
	double MutationRate() const { return mr_; }

	bool operator()(CIndividual *c, double mra, CProblemSelf *psf) const;
	bool operator()(CIndividual *c, CProblemSelf *psf) const
	{
		return operator()(c, mr_,psf);
	}

private:
	double mr_; // Í»±äÂÊ
};

#endif