#include "../headers/MNIST_initializer.hpp"

#define WINDOWS_ENV 0

#if WINDOWS_ENV == 0
#include "../headers/mnist_reader.hpp"
#else
#include "../headers/mnist_reader_less.hpp"
#endif


MNIST_initializer::MNIST_initializer() {
    mnist::MNIST_dataset<std::vector, std::vector<uint8_t>, uint8_t> dataset =
            mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(MNIST_DATA_LOCATION);

    m_training_images = dataset.training_images;
    m_test_images = dataset.test_images;
    m_training_labels = dataset.training_labels;
    m_test_labels = dataset.test_labels;
}

std::vector<std::vector<unsigned char>> MNIST_initializer::training_images() const {
    return m_training_images;
}

std::vector<std::vector<unsigned char>> MNIST_initializer::test_images() const {
    return m_test_images;
}

std::vector<uint8_t> MNIST_initializer::training_labels() const {
    return m_training_labels;
}

std::vector<uint8_t> MNIST_initializer::test_labels() const {
    return m_test_labels;
}
