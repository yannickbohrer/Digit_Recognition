#ifndef TRAINING_HPP
#define TRAINING_HPP

#include "Network.hpp"

class Training {
public:
    explicit Training(const Network& network);

private:
    const Network* m_network;

    [[nodiscard]] double sigmuid(double value) const;
    [[nodiscard]] double fast_sigmuid_approximation(double value) const;
};

#endif
