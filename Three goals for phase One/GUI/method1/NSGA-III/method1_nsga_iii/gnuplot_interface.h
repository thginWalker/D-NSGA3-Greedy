#include <string>
#include <stdio.h>

#include <string>
#include <cstddef>

// ----------------------------------------------------------------------
// Gnuplot
//
//这只是一个在程序中调用gnuplot的非常简单的接口。

//现在它似乎只在Windows + Visual Studio下工作。
// ----------------------------------------------------------------------

class Gnuplot
{
public:
	Gnuplot();
	~Gnuplot();

	// 禁止复制 (VS2012 does not support 'delete')	
	Gnuplot(const Gnuplot&);
	Gnuplot& operator=(const Gnuplot&);

	// 向gnuplot发送任何命令
	void operator ()(const std::string& command);

	void reset() { operator()("reset"); }
	void replot() { operator()("replot"); }
	void set_title(const std::string& title);

	void plot(const std::string& fname, std::size_t x, std::size_t y);
	void splot(const std::string& fname, std::size_t x, std::size_t y, std::size_t z);
	// splot 3D绘图
protected:
	FILE* gnuplotpipe;
};
