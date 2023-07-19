cmake_minimum_required(VERSION 3.25)
project(Digit_Recognition)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Digit_Recognition
        main.cpp
        implementation/Layer.cpp
        implementation/MNIST_reader.cpp
        implementation/Network.cpp
        implementation/Neuron.cpp)
