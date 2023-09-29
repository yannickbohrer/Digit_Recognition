#include "../../headers/network/Layer.hpp"

#include <iostream>

Layer::Layer(size_t size) {
    m_size = size;
    m_neurons.reserve(size);

    for (size_t i = 0; i < size; i++)
        m_neurons.emplace_back(new Neuron());
}

size_t Layer::size() const {
    return m_size;
}

void Layer::printValues() const {
    for (const Neuron* neuron : m_neurons)
        std::cout << neuron->value()
                  << (neuron == m_neurons.back() ? "\n\n" : ", ");
}

Neuron* Layer::operator[](size_t idx) {
    return m_neurons[idx];
}
