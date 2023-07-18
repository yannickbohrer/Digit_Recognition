#ifndef NEURON_H
#define NEURON_H


class Neuron {
public:
	Neuron(double value = 0.0);
	double value() const;
	bool setValue(double value);

private:
	double m_value;
};

#endif
