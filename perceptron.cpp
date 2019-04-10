#include "perceptron.h"

Perceptron::Perceptron(double _coeff = 0.5) {
    learningCount = 0;
    std::cout << "Coeff : " << _coeff << std::endl;
    coeff = _coeff;
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

double Perceptron::check(double x, double y){
    return activationFunc(1*weights[0]+x*weights[1]+y*weights[2]);
}

bool Perceptron::onlineLearning(std::vector<Point> points) {
        inputs[1] = 10000;
        inputs[2] = 100;
        for(int t = 0; t < points.size(); t++) {
            inputs[1] = points[t].x;
            inputs[2] = points[t].y;
                for (int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        weights[j] = weights[j]-inputs[i]*(activationFunc(inputs[0]*weights[1]+inputs[1]*weights[2]+inputs[2])-points[i].d);
                }
                }
                std::cout << std::endl;
                learningCount++;
        }
    std::cout << "Weights: " << weights[0] << " " << weights[1] << " " << weights[2] << " " <<std::endl;
    return true;
}