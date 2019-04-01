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
    std::uniform_real_distribution<> dis(-10,10);
    Perceptron* per = new Perceptron(0.5);

    for (int i = 0; i < 500; i++) {
        points[i].x = dis(gen);
        points[i].y = dis(gen);
        points[i].d = 0;
    }

    for (int i = 0; i < 500; i++) {
        points[i+500].x = dis(gen);
        points[i+500].y = dis(gen);
        points[i+500].d = 1;
    }
    Gnuplot plot;
    
    delete per;
    return 0;
}