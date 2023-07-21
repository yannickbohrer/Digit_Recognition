#ifndef LAYER_H
#define LAYER_H

#include <vector>

#include "Neuron.h"


class Layer {
public:
	explicit Layer(size_t size);

	size_t size() const;

	void printValues() const;

	Neuron* operator [] (size_t idx);
private:
	std::vector<Neuron*> m_neurons;
	size_t m_size;
};

#endif
