#include "widget.h"

#include <QApplication>
#include "problem_base.h"
#include "problem_self.h"
#include "alg_nsgaiii.h"
#include "alg_population.h"
#include "exp_experiment.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "gnuplot_interface.h"
#include "log.h"
#include "aux_misc.h"
#include "exp_indicator.h"


using namespace std;

int main(int argc, char *argv[])
{


    ifstream exp_list("explist.ini");
    if (!exp_list) { cout << "We need the explist.ini file." << endl; return 1; }

    string exp_name;

    while (exp_list >> exp_name)
    {
        //注:由于用Qt界面设置太过繁琐，为此决定在原有配置文件的基础上对原有配置文件进行修改，高内聚低耦合
        //修改开始
        QApplication a(argc, argv);
        Widget w;
        string filename = "Experiments\\" + exp_name;
        w.getFilename(filename);
        w.show();
//        return a.exec();
        a.exec();
        //修改结束

        ifstream exp_ini("Experiments\\" + exp_name);
        if (!exp_ini) { cout << exp_name << " file does not exist." << endl; continue; }
        // -----开始实验 ------
        CNSGAIII nsgaiii;
        CProblemSelf* problem = 0;
cout<<"Experiments\\" << exp_name<<endl;
        SetupExperiment(nsgaiii, &problem, exp_ini);
        Gnuplot gplot;
        ofstream IGD_results(nsgaiii.name() + "-" + problem->name() + "-IGD.txt");
cout<<"test222..."<<endl;

        const size_t NumRuns = 20; // 20是NSGA-III文件中的设置,可以变更
        for (size_t r = 0; r < NumRuns; r += 1)
        {
            srand(r); cout << "Solving " << problem->name() << " ... Run: " << r << endl;//控制台输出信息

            // --- Solve
            CPopulation solutions;
            nsgaiii.Solve(&solutions, *problem);

            // --- Output the result
            string logfname = "Results\\" + nsgaiii.name() + "-" + problem->name() + "-Run" + IntToStr(r) + ".txt";
            SaveScatterData(logfname, solutions);

            // --- Calculate the performance metric
            TFront PF, approximation;
            IGD_results << IGD(LoadFront(PF, "PF\\" + problem->name() + "-PF.txt"), LoadFront(approximation, logfname)) << endl;

            // --- Visualization (Show the last 3 dimensions. You need gnuplot.)

            ShowPopulation(gplot, solutions, "gnuplot-show"); //system("pause");
        }
        delete problem;

    }
   // return a.exec();
}
