#ifndef NEURON_H
#define NEURON_H


class Neuron {
public:
	explicit Neuron(double value = 0.0);
	[[nodiscard]] double value() const;
	void setValue(double value);

private:
	double m_value;
};

#endif
