#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <string.h>

#include "point.h"
#include "perceptron.h"
#include "gnuplot.h"

using std::vector;

int main(int argc, char* argv[]) {
    float cel;
    double coeff = 10;
    int pointCount = 1;
    vector<Point> points;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    if (argc > 1) {
        std::cout << strcmp(argv[1],"-b") << std::endl;
        if (strcmp(argv[1],"-b") == 0) {
            coeff = atof(argv[2]); 
        }
    }
    Perceptron* per = new Perceptron(coeff);
    
    //Генерим случайные данные
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10,10);
    //Записываем файл с точками
    std::ofstream ofs;
    points.clear();
    ofs.open("./first.dat", std::ofstream::trunc);
    for (int i = 0; i < pointCount; i++) {
        Point p;
        p.x = dis(gen);
        p.y = dis(gen);
        p.d = 0;
        points.push_back(p);
        ofs << p.x << ' ' << p.y << ' ' << p.d << std::endl;
    }
    std::uniform_real_distribution<> diss(-10,10);
    for (int i = 0; i < pointCount; i++) {
        struct Point p;
        p.x = diss(gen);
        p.y = diss(gen);
        p.d = 1;
        points.push_back(p);
        ofs << p.x << ' ' << p.y << ' ' << p.d << std::endl;
    }
    ofs.close();
    //Обучение
    per->onlineLearning(points);
    //Выводим тест
    ofs.open("./third.dat", std::ofstream::trunc);
    for (int i = -10*5; i <= 10*5; i++) {
        for (int j = -10*5; j <= 10*5; j++) {
            double x = (double)i/5;
            double y = (double)j/5;
            double d = per->check(x,y)+ 2;
            double c = modf(d, &cel);
            if (c < 0.5f) {
                d = cel;
            } else {
                d = cel+1;
            }
            ofs << x << ' ' << y << ' ' << d << std::endl;
        }
    }
    for (int i = 0; i < static_cast<int>(points.size()); i++) {
        ofs << points[i].x << ' ' << points[i].y << ' ' << points[i].d << std::endl;
    }
    //Выводим
    Gnuplot plot;
    plot("x=0; y=0");
    plot("set palette rgb 33,13,10;");
    plot("set pointsize 20;");
    plot("set xzeroaxis linetype 3 linecolor rgb \"black\";");
    plot("set yzeroaxis linetype 3 linecolor rgb \"black\";");
    plot("plot \"./third.dat\"  using 1:2:3 pt 7 ps 1 palette;");
    //plot("plot \"./first.dat\"  using 1:2:3 pt 7 ps 1 palette");
    //Убираем за собой
    delete per;
    points.clear();
    return 0;
}