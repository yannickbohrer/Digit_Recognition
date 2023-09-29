#include "../../headers/network/Neuron.hpp"

#include <iostream>

Neuron::Neuron(double value) {
    if (value >= 0 && value <= 1)
        m_value = value;
    else {
        std::cerr << "neuron activation value must be e [0.0, 1.0]"
                  << std::endl;
        exit(EXIT_FAILURE);
    }
}

double Neuron::value() const {
    return m_value;
}

void Neuron::setValue(double value) {
    if (value < 0 || value > 1) {
        std::cerr << "neuron activation value must be e [0.0, 1.0]"
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    m_value = value;
}
