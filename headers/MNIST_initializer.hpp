#ifndef MNIST_INITIALIZER_HPP
#define MNIST_INITIALIZER_HPP

#include <cstdint>
#include <vector>


class MNIST_initializer {
public:
	MNIST_initializer();

    [[nodiscard]] std::vector<std::vector<unsigned char>> training_images() const;
    [[nodiscard]] std::vector<std::vector<unsigned char>> test_images() const;
    [[nodiscard]] std::vector<uint8_t> training_labels() const;
    [[nodiscard]] std::vector<uint8_t> test_labels() const;

private:
	std::vector<std::vector<unsigned char>> m_training_images;
    std::vector<std::vector<unsigned char>> m_test_images;
	std::vector<uint8_t> m_training_labels;
	std::vector<uint8_t> m_test_labels;
};


#endif
