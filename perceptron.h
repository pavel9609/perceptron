#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <random>
#include <iostream>
#include <vector>
#include <math.h>

#include "point.h"

//Класс персептрона
class Perceptron {
    private:
        double coeff;                       //Коэффициент функции
        double eps = 0.1;
    public:
        double inputs[2];                   //Входные значения
        double weights[2];                  //Веса
        int learningCount;                  //Количество шагов обучения
        Perceptron(double _coeff);
        double activationFunc(double u);    //Функция активации
        bool onlineLearning(std::vector<Point> points);
        double check(double x, double y);
        double dE(double u);                //дельта e
};

#endif