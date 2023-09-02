cmake_minimum_required(VERSION 3.25)
project(Digit_Recognition)

set(CMAKE_CXX_STANDARD 20)

find_package(MNIST PATHS ./mnist)
if(NOT MNIST_FOUND)
    message(FATAL_ERROR "MNIST loader could not be found. It is available under https://github.com/wichtounet/mnist")
endif(NOT MNIST_FOUND)

include_directories(. ${MNIST_INCLUDE_DIR})

add_executable(Digit_Recognition
        main.cpp
        implementation/Layer.cpp
        implementation/MNIST_initializer.cpp
        implementation/Network.cpp
        implementation/Neuron.cpp
        implementation/Training.cpp)

target_compile_features(Digit_Recognition PRIVATE cxx_range_for)

# Pass MNIST data directory to main.cpp
target_compile_definitions(Digit_Recognition PRIVATE MNIST_DATA_LOCATION="${MNIST_DATA_DIR}")
