#ifndef TRAINING_HPP
#define TRAINING_HPP

#include "MNIST_initializer.hpp"
#include "Network.hpp"

class Training {
public:
    explicit Training(const Network& network);
    
    void test_sigmuid_times() const;

private:
    const Network* m_network;
    const MNIST_initializer* m_database;

    [[nodiscard]] double sigmuid(double value) const;
    [[nodiscard]] double NOT_SO_fast_sigmuid_approximation(double value) const;
};

#endif
