#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include "Layer.hpp"
#include "MNIST_initializer.hpp"

class Network {
public:
	Network();

private:
	Layer* m_input_layer;
	std::vector<Layer*> m_hidden_layers;
	Layer* m_output_layer;
};


#endif
