#include "../../headers/training/Gradient_Descent.hpp"

#include <cmath>

Gradient_Descent::Gradient_Descent(std::vector<double>& vector, Costfunction& costfunction) {
    m_starting_vector = vector;
    m_costfunction = costfunction;
}

std::vector<double> Gradient_Descent::gradient(
    std::vector<double>& x, double (*f)(std::vector<double>& pos)) {
    std::vector<double> grad(x.size());
    double h = 1 / 1e-8;
    double y1 = f(x);

    for (int index = 0; index < x.size(); index++) {
        std::vector<double> x2(x.size());
        x2 = x;
        x2.at(index) += h;

        grad.at(index) = (f(x2) - y1) * h;
    }
    return grad;
}

void Gradient_Descent::gradient_descent_recursion(
    std::vector<double>& x, double (*f)(std::vector<double>& pos), double lambda,
    int counter) {
    std::vector<double> grad = gradient(x, f);

    std::vector<double> one_lambda_step = x;
    for (std::size_t index = 0; index < one_lambda_step.size(); index++)
        one_lambda_step.at(index) -= (grad.at(index) * lambda);

    std::vector<double> vector_after_step = x;
    for (std::size_t index = 0; index < vector_after_step.size(); index++)
        vector_after_step.at(index) -= one_lambda_step.at(index);

    double y = f(x);
    double y_after_step = f(vector_after_step);
    double y_next;

    double grad_length = 0;
    {
        double sum = 0;
        for (const double val : grad)
            sum += (val * val);

        grad_length = std::sqrt(sum);
    }

    if (counter == 50)
        return;

    if (grad_length < 1e-5)
        return;

    if (y_after_step >= y) {
        y_next = y_after_step;
        while (y_next >= y) {
            lambda = lambda / 2;

            for (std::size_t index = 0; index < one_lambda_step.size(); index++)
                one_lambda_step.at(index) = (grad.at(index) * lambda);

            for (std::size_t index = 0; index < vector_after_step.size();
                 index++)
                vector_after_step.at(index) -= one_lambda_step.at(index);

            y_next = f(vector_after_step);
        }
        gradient_descent_recursion(vector_after_step, f, lambda, ++counter);
        return;
    }

    std::vector<double> vector_test = x;
    for (std::size_t index = 0; index < grad.size(); index++)
        vector_test.at(index) -= (grad.at(index) * lambda * 2);

    double valueAtTest = f(vector_test);

    if (valueAtTest < y_after_step) {
        gradient_descent_recursion(vector_test, f, lambda * 2, ++counter);
        return;
    }
    gradient_descent_recursion(vector_after_step, f, lambda, ++counter);
}
