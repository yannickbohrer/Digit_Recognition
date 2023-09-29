#include "../../headers/training/Training.hpp"

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "../../headers/MNIST_initializer.hpp"
#include "../../headers/network/Network.hpp"

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

void Training::test_sigmoid_times() const {
    auto start_actual_sigmuid = std::chrono::high_resolution_clock::now();
    for (uint32_t idx = 1; idx < 10000001; idx++)
        sigmoid(reinterpret_cast<double&>(idx));
    auto stop_actual_sigmuid = std::chrono::high_resolution_clock::now();
    auto duration_actual_sigmuid =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop_actual_sigmuid - start_actual_sigmuid);
    std::cout << "actual sigmoid: " << duration_actual_sigmuid.count() * 1e-6
              << " Sekunden" << std::endl;

    auto start_sigmuid_approximation =
        std::chrono::high_resolution_clock::now();
    for (uint32_t idx = 1; idx < 10000001; idx++)
        NOT_SO_fast_sigmoid_approximation(reinterpret_cast<double&>(idx));
    auto stop_sigmuid_approximation = std::chrono::high_resolution_clock::now();
    auto duration_sigmuid_approximation =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop_sigmuid_approximation - start_sigmuid_approximation);
    std::cout << "sigmoid approximation: "
              << duration_sigmuid_approximation.count() * 1e-6 << " Sekunden"
              << std::endl;
}

/* not std::abs --> custom abs function causes same results for testing double
 * abs(double value) { return (value <= 0 ? (-1) * value : value); } */
