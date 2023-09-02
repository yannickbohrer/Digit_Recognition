#ifndef MNIST_INITIALIZER_HPP
#define MNIST_INITIALIZER_HPP

#include <fstream>
#include <vector>


class MNIST_initializer {
public:
	MNIST_initializer();

    std::vector<std::vector<unsigned char>> training_images() const;
    std::vector<std::vector<unsigned char>> test_images() const;
    std::vector<uint8_t> training_labels() const;
    std::vector<uint8_t> test_labels() const;

private:
	std::vector<std::vector<unsigned char>> m_training_images;
    std::vector<std::vector<unsigned char>> m_test_images;
	std::vector<uint8_t> m_training_labels;
	std::vector<uint8_t> m_test_labels;
};


#endif
