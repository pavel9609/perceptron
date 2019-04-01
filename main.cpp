#include <iostream>
#include <random>
#include <fstream>
#include <vector>

#include "point.h"
#include "perceptron.h"
#include "gnuplot.h"

using std::vector;

int main(int argc, char* argv[]) {
    vector<Point> points;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10,0);
    Perceptron* per = new Perceptron(0.5);
    std::ofstream ofs;
    ofs.open("./first.dat", std::ofstream::trunc);
    for (int i = 0; i < 50; i++) {
        Point p;
        p.x = dis(gen);
        p.y = dis(gen);
        p.d = 0;
        points.push_back(p);
        ofs << p.x << ' ' << p.y << ' ' << p.d << std::endl;
    }
    std::uniform_real_distribution<> diss(0,10);
    for (int i = 0; i < 50; i++) {
        Point p;
        p.x = diss(gen);
        p.y = diss(gen);
        p.d = 10;
        points.push_back(p);
        ofs << p.x << ' ' << p.y << ' ' << p.d << std::endl;
    }
    ofs.close();
    
    per->onlineLearning(points);

    Gnuplot plot;
    plot("x=0; y=0");
    plot("set palette rgb 33,13,10;");
    plot("set pointsize 20;");
    plot("set xzeroaxis line 10 linetype 3 linecolor rgb \"black\";");
    plot("set yzeroaxis line 10 linetype 3 linecolor rgb \"black\";");
    plot("plot \"./first.dat\"  using 1:2:3 pt 7 ps 1 palette");
    delete per;
    points.clear();
    return 0;
}