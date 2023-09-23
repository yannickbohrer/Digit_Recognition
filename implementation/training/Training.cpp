#include "../../headers/training/Training.hpp"
#include "../../headers/network/Network.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>

#include <chrono>

#include "../../headers/MNIST_initializer.hpp"

Training::Training(const Network& network) {
    m_network = &network;
    m_database = new MNIST_initializer();
}

double Training::sigmoid(double value) const {
    return (1 / (1 + exp((-1) * value)));
}


// is supposed to be faster, how come the test results ?!?!
double Training::NOT_SO_fast_sigmoid_approximation(double value) const {
    return (value / (1 + std::abs(value)));
}

std::vector<double> Training::gradient(std::vector<double> x, double(*f)(std::vector<double> pos)) {
    std::vector<double> grad(x.size());
    double h = 1e-8;
    double function_value = f(x);

    for (int i = 0; i < x.size(); i++) {
        std::vector<double> gradTmp(x.size());
        gradTmp = x;
        gradTmp[i] += h;
        
        double tmp = (f(gradTmp) - function_value) / h;
        grad[i] = tmp;
    }
    return grad;
}

void Training::gradient_descend_recursion(std::vector<double> x, double(*f)(std::vector<double> pos), double lambda = 1.0, int counter = 0) {
    std::vector<double> grad = gradient(x, f);
    std::vector<double> vectorStep = x + (grad * lambda);

    double xValue = f(x);
    double valueAtFirstStep = f(vectorStep);
    double valueAtStep;
    double gradLength = grad.size();

    if (counter == 25)
        return;

    if (gradLength < 1e-5)
        return;

    if (valueAtFirstStep <= xValue) {
        valueAtStep = valueAtFirstStep;
        while (valueAtStep <= xValue) {
            lambda = lambda / 2;
            vectorStep = x + (grad * lambda);
            valueAtStep = f(vectorStep);
        }
        gradient_descend_recursion(vectorStep, f, lambda, ++counter);
        return;
    }

    std::vector<double> vectorTest = x + (grad * lambda * 2);
    double valueAtTest = f(vectorTest);
    
    if (valueAtTest > valueAtFirstStep) {
        gradient_descend_recursion(vectorTest, f, lambda * 2, ++counter);
        return;
    }
    gradient_descend_recursion(vectorStep, f, lambda, ++counter);
}


void Training::test_sigmoid_times() const {
    auto start_actual_sigmuid = std::chrono::high_resolution_clock::now();
    for (uint32_t idx = 1; idx < 10000001; idx++)
        sigmoid(reinterpret_cast<double&>(idx));
    auto stop_actual_sigmuid = std::chrono::high_resolution_clock::now();
    auto duration_actual_sigmuid = std::chrono::duration_cast<std::chrono::microseconds>(stop_actual_sigmuid - start_actual_sigmuid);
    std::cout << "actual sigmoid: " << duration_actual_sigmuid.count() * 1e-6 << " Sekunden" << std::endl;


    auto start_sigmuid_approximation = std::chrono::high_resolution_clock::now();
    for (uint32_t idx = 1; idx < 10000001; idx++)
        NOT_SO_fast_sigmoid_approximation(reinterpret_cast<double&>(idx));
    auto stop_sigmuid_approximation = std::chrono::high_resolution_clock::now();
    auto duration_sigmuid_approximation = std::chrono::duration_cast<std::chrono::microseconds>(stop_sigmuid_approximation - start_sigmuid_approximation);
    std::cout << "sigmoid approximation: " << duration_sigmuid_approximation.count() * 1e-6 << " Sekunden" << std::endl;
}

/* not std::abs --> custom abs function causes same results for testing double abs(double value) { return (value <= 0 ? (-1) * value : value); } */
