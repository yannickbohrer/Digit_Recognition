#include "../../headers/training/Gradient_Descent.hpp"

Gradient_Descent::Gradient_Descent() {

}

std::vector<double> Gradient_Descent::gradient(std::vector<double> x, double(*f)(std::vector<double> pos)) {
    std::vector<double> grad(x.size());
    double h = 1e-8;
    double function_value = f(x);

    for (int i = 0; i < x.size(); i++) {
        std::vector<double> grad_tmp(x.size());
        grad_tmp = x;
        grad_tmp[i] += h;
        
        double tmp = (f(grad_tmp) - function_value) / h;
        grad[i] = tmp;
    }
    return grad;
}

void Gradient_Descent::gradient_descend_recursion(std::vector<double> x, double(*f)(std::vector<double> pos), double lambda, int counter) {
    std::vector<double> grad = gradient(x, f);

    std::vector<double> one_lambda_step;
    for (double val : x)
        one_lambda_step.emplace_back(val);
    for (std::size_t index = 0 ; index < one_lambda_step.size(); index++)
        one_lambda_step.at(index) -= (grad.at(index) * lambda);

    std::vector<double> vector_after_step = x;
    for (std::size_t index = 0; index < vector_after_step.size(); index++)
        vector_after_step.at(index) -= one_lambda_step.at(index);

    double y = f(x);
    double y_after_step = f(vector_after_step);
    double y_next;

    double sum = 0;
    for (int i = 0; i < this->getDim(); i++) {
        sum += pow(this->getComponent(i), 2);
    }
    double grad_length = sqrt(sum);


    if (counter == 25)
        return;

    if (grad_length < 1e-5)
        return;

    if (y_after_step >= y) {
        y_next = y_after_step;
        while (y_next >= y) {
            lambda = lambda / 2;

            for (std::size_t index = 0; index < one_lambda_step.size(); index++)
                one_lambda_step.at(index) = (grad.at(index) * lambda);

            for (std::size_t index = 0; index < vector_after_step.size(); index++)
                vector_after_step.at(index) -= one_lambda_step.at(index);

            y_next = f(vector_after_step);
        }
        gradient_descend_recursion(vector_after_step, f, lambda, ++counter);
        return;
    }

    std::vector<double> vectorTest = x + (grad * lambda * 2);
    double valueAtTest = f(vectorTest);
    
    if (valueAtTest > y_after_step) {
        gradient_descend_recursion(vectorTest, f, lambda * 2, ++counter);
        return;
    }
    gradient_descend_recursion(vector_after_step, f, lambda, ++counter);
}
