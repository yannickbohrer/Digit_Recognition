#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP
#include <vector>

class Gradient_Descent {
public:
    Gradient_Descent();

private:
    void gradient_descent_recursion(std::vector<double> x,
                                    double (*f)(std::vector<double> pos),
                                    double lambda = 1.0, int counter = 0);
    [[nodiscard]] std::vector<double> gradient(
        std::vector<double> x, double (*f)(std::vector<double> pos));
};

#endif
