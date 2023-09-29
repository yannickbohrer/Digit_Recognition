#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP
#include <vector>
#include "Cost_Function.hpp"

class Gradient_Descent {
public:
    Gradient_Descent(std::vector<double>& vector, Costfunction& cost_function);

private:
    std::vector<double> m_starting_vector;
    std::vector<double> m_result_adjustments_vector;

    Costfunction m_costfunction;

    void gradient_descent_recursion(std::vector<double>& x,
                                    double (*f)(std::vector<double>& pos),
                                    double lambda = 1.0, int counter = 0);
    [[nodiscard]] std::vector<double> gradient(
        std::vector<double>& x, double (*f)(std::vector<double>& pos));
};

#endif
