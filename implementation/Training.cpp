#include "../headers/Training.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>

#include <chrono>

#include "../headers/MNIST_initializer.hpp"

Training::Training(const Network& network) {
    m_network = &network;
    m_database = new MNIST_initializer();

    //m_database->print_database_info();
}

double Training::sigmuid(double value) const {
    return (1 / (1 + exp((-1) * value)));
}


// is supposed to be faster, how come the test results ?!?!
double Training::NOT_SO_fast_sigmuid_approximation(double value) const {
    return (value / (1 + std::abs(value)));
}

/*
// not std::abs --> custom abs function causes same results
// for testing
double abs(double value) {
    return (value <= 0 ? (-1) * value : value);
}
*/

void Training::test_sigmuid_times() const {
    auto start_actual_sigmuid = std::chrono::high_resolution_clock::now();
    for (uint32_t idx = 1; idx < 10000001; idx++)
        sigmuid(reinterpret_cast<double&>(idx));
    auto stop_actual_sigmuid = std::chrono::high_resolution_clock::now();
    auto duration_actual_sigmuid = std::chrono::duration_cast<std::chrono::microseconds>(stop_actual_sigmuid - start_actual_sigmuid);
    std::cout << "actual sigmuid: " << duration_actual_sigmuid.count() * 1e-6 << " Sekunden" << std::endl;


    auto start_sigmuid_approximation = std::chrono::high_resolution_clock::now();
    for (uint32_t idx = 1; idx < 10000001; idx++)
        NOT_SO_fast_sigmuid_approximation(reinterpret_cast<double&>(idx));
    auto stop_sigmuid_approximation = std::chrono::high_resolution_clock::now();
    auto duration_sigmuid_approximation = std::chrono::duration_cast<std::chrono::microseconds>(stop_sigmuid_approximation - start_sigmuid_approximation);
    std::cout << "sigmuid approximation: " << duration_sigmuid_approximation.count() * 1e-6 << " Sekunden" << std::endl;
}

