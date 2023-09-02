#include <cstdint>
#include <iostream>

#include "../headers/Layer.hpp"
#include "../headers/Network.hpp"

Network::Network(
    uint32_t input_neuron_count,
    uint32_t number_of_hidden_layers,
    uint32_t neurons_per_hidden_layer,
    uint32_t output_neuron_count
) {
    if (input_neuron_count < 1
        || number_of_hidden_layers < 1
        || number_of_hidden_layers < 1
        || output_neuron_count < 1
    ) {
        std::cerr << "failed initializing network: invalid hyperparameters" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_input_layer = new Layer(input_neuron_count);
    m_hidden_layers.reserve(number_of_hidden_layers);
    for (size_t i = 0; i < number_of_hidden_layers; i++)
        m_hidden_layers.emplace_back(new Layer(neurons_per_hidden_layer));

    m_output_layer = new Layer(output_neuron_count);
}
