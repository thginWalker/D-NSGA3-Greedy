#include <string>
#include <stdio.h>

#include <string>
#include <cstddef>

// ----------------------------------------------------------------------
// Gnuplot
//
//��ֻ��һ���ڳ����е���gnuplot�ķǳ��򵥵Ľӿڡ�

//�������ƺ�ֻ��Windows + Visual Studio�¹�����
// ----------------------------------------------------------------------

class Gnuplot
{
public:
	Gnuplot();
	~Gnuplot();

	// ��ֹ���� (VS2012 does not support 'delete')	
	Gnuplot(const Gnuplot&);
	Gnuplot& operator=(const Gnuplot&);

	// ��gnuplot�����κ�����
	void operator ()(const std::string& command);

	void reset() { operator()("reset"); }
	void replot() { operator()("replot"); }
	void set_title(const std::string& title);

	void plot(const std::string& fname, std::size_t x, std::size_t y);
	void splot(const std::string& fname, std::size_t x, std::size_t y, std::size_t z);
	// splot 3D��ͼ
protected:
	FILE* gnuplotpipe;
};
