#include "perceptron.h"

Perceptron::Perceptron(double coeff = 0.5) {
    learningCount = 0;
    coeff = 0.5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,1);
    inputs[0]=1;
    for (int i = 0; i < 3; i++) {
        weights[i] = dis(gen);
        std::cout << weights[i] << " ";
    }
}

double Perceptron::activationFunc(double u) {
    return 1/(1+exp(-coeff*u));
}

double Perceptron::dE(double u) {
    return (coeff*activationFunc(u))*(1-activationFunc(u));
}