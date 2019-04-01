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

bool Perceptron::onlineLearning(std::vector<Point> points) {
        inputs[1] = 10000;
        inputs[2] = 100;
        for(int i = 0; i < points.size(); i++) {
            std::cout << inputs[1] << '\t' << inputs[2] << std::endl;
                inputs[1] = points[i].x;
                inputs[2] = points[i].y;
                for(int j = 0; j < 3; j++) {
                    weights[j] = weights[j]-inputs[1]*(inputs[2]-points[i].d);
                    std::cout << weights[j] << " ";
                }
                std::cout << std::endl;
                learningCount++;
        }
    return true;
}