#include "Neuron.h"

Neuron::Neuron(double value) {
	if (value >= 0 && value <= 1)
		m_value = value;
	else
		m_value = -1;
}

double Neuron::value() const { return m_value; }

bool Neuron::setValue(double value) {
	if (value < 0 || value > 1)
		return false;
	m_value = value;
}