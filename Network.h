#ifndef NETWORK_H
#define NETWORK_H

#include <vector>

#include "Layer.h"

class Network {
public:
	Network();

private:
	Layer* m_input_layer;
	std::vector<Layer*> m_hidden_layers;
	Layer* m_output_layer;
};


#endif
