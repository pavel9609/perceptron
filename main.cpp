#include <iostream>
#include <random>
#include <fstream>

#include "perceptron.h"
#include "gnuplot.h"
#include "point.h"

int main(int argc, char* argv[]) {
    Point points[1000];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10,0);
    Perceptron* per = new Perceptron(0.5);
    std::ofstream ofs;
    ofs.open("./first.dat", std::ofstream::trunc);
    for (int i = 0; i < 500; i++) {
        points[i].x = dis(gen);
        points[i].y = dis(gen);
        points[i].d = 0;
        ofs << points[i].x << ' ' << points[i].y << ' ' << points[i].d << std::endl;
    }
    std::uniform_real_distribution<> diss(0,10);
    for (int i = 500; i < 1000; i++) {
        points[i].x = diss(gen);
        points[i].y = diss(gen);
        points[i].d = 1;
        ofs << points[i].x << ' ' << points[i].y << ' ' << points[i].d << std::endl;
    }
    ofs.close();
    Gnuplot plot;
    plot("x=0; y=0");
    plot("set palette rgb 33,13,10;");
    plot("set pointsize 20;");
    plot("set xzeroaxis line 10 linetype 3 linecolor rgb \"black\";");
    plot("set yzeroaxis line 10 linetype 3 linecolor rgb \"black\";");
    plot("plot \"./first.dat\"  using 1:2:3 pt 7 ps 1 palette");
    
    delete per;
    return 0;
}