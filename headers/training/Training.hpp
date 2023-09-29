#ifndef TRAINING_HPP
#define TRAINING_HPP

#include <cstdint>
#include <vector>
#include "../MNIST_initializer.hpp"
#include "../network/Network.hpp"

class Training {
public:
    explicit Training(const Network& network);

    void test_sigmoid_times() const;

private:
    const Network* m_network;
    const MNIST_initializer* m_database;

    double sigmoid(double value) const;
    double NOT_SO_fast_sigmoid_approximation(double value) const;
};

#endif
