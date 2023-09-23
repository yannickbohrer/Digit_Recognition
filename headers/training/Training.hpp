#ifndef TRAINING_HPP
#define TRAINING_HPP

#include "../MNIST_initializer.hpp"
#include "../network/Network.hpp"
#include <cstdint>
#include <vector>

class Training {
public:
  explicit Training(const Network &network);

  void test_sigmoid_times() const;

private:
  const Network *m_network;
  const MNIST_initializer *m_database;

  [[nodiscard]] double sigmoid(double value) const;
  [[nodiscard]] double NOT_SO_fast_sigmoid_approximation(double value) const;
  void gradient_descend_recursion(std::vector<double> x,
                        double (*funktion)(std::vector<double> pos),
                        double lambda = 1.0, int counter = 0);
  [[nodiscard]] std::vector<double>
  gradient(std::vector<double> x, double (*funktion)(std::vector<double> pos));
};

#endif
