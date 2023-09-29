#include <cstdint>
#include <iostream>
#include "headers/network/Network.hpp"
#include "headers/training/Training.hpp"

int main(int argc, char* argv[]) {
    // 28 x 28 Pixel picture input
    const uint32_t number_of_input_neurons = 784;
    const uint32_t number_of_hidden_layers = 2;
    const uint32_t number_of_neurons_per_hidden_layer = 16;

    // 10 output possibilities ([0, ..., 9])
    const uint32_t number_of_output_neurons = 10;

    Network network(number_of_input_neurons, number_of_hidden_layers,
                    number_of_neurons_per_hidden_layer,
                    number_of_output_neurons);

    Training training(network);

    return EXIT_SUCCESS;
}
