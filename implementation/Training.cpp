#include "../headers/Training.hpp"

#include <cmath>
#include <cstdlib>

Training::Training(const Network& network) {
    m_network = &network;
}

double Training::sigmuid(double value) const {
    return (1 / (1 + exp((-1) * value)));
}

double Training::fast_sigmuid_approximation(double value) const {
    return (value / (1 + std::abs(value)));
}
