#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <cstdint>
#include "Layer.hpp"


class Network {
public:
	explicit Network(
        uint32_t input_neuron_count,
        uint32_t number_of_hidden_layers,
        uint32_t neurons_per_hidden_layer,
        uint32_t output_neuron_count
    );

private:
	Layer* m_input_layer;
    std::vector<Layer*> m_hidden_layers;
	Layer* m_output_layer;
};


#endif
