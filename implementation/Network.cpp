#include <iostream>
#include <string>

#include "../headers/Layer.hpp"
#include "../headers/Network.hpp"

Network::Network() {
    m_input_layer = new Layer(784); // 28 x 28 Pixel

    m_hidden_layers.reserve(2); // 2 hidden layers
    for (size_t i = 0; i < 2; i++)
    m_hidden_layers.emplace_back(new Layer(16)); // jeweils 16 Neuronen

    m_output_layer = new Layer(10); // 10 Neuronen wegen Dezimalsystem

    std::cout << "Hyperparameter des netzwerks\n\n";
    for (size_t i = 0; i < m_hidden_layers.size(); i++)
    std::cout << std::to_string(i + 1) << "Layer: "
              << std::to_string(m_hidden_layers[i]->size()) + "\n\n";
}
