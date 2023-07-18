#include <iostream>
#include <string>

#include "Network.h"
#include "Layer.h"

#define DEBUG_MODE 1

#if DEBUG_MODE == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

Network::Network() {
	m_input_layer = new Layer(784);				// 28 x 28 Pixel
	
	m_hidden_layers.reserve(2);					// 2 hidden layers
	for (size_t i = 0; i < 2; i++)
		m_hidden_layers.emplace_back(new Layer(16));		// jeweils 16 Neuronen

	m_output_layer = new Layer(10);				// 10 Neuronen wegen Dezimalsystem


	LOG("Input Layer Size: " + std::to_string(m_input_layer->size()) + "\n\n");
	for (size_t i = 0; i < m_hidden_layers.size(); i++)
		LOG("Hidden Layer " + std::to_string(i) + ": " + std::to_string(m_hidden_layers[i]->size()) + "\n\n");
	LOG("Output Layer Size: " + std::to_string(m_output_layer->size()) + "\n\n");
}