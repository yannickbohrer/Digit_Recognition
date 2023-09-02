#ifndef LAYER_H
#define LAYER_H

#include <vector>

#include "Neuron.hpp"


class Layer {
public:
	explicit Layer(std::size_t size);

    std::size_t size() const;

	void printValues() const;

	Neuron* operator [] (std::size_t idx);
private:
	std::vector<Neuron*> m_neurons;
    std::size_t m_size;
};

#endif
