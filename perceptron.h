#include <random>
#include <iostream>
#include <math.h>

class Perceptron {
    public:
        double coeff;
        double inputs[2];
        double weights[2];
        int learningCount;
        Perceptron(double coeff);
        double activationFunc(double u);
};