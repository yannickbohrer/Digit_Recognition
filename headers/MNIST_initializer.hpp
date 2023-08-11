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

// attributes
private:
    /*
	// raw files
	std::ifstream m_training_images_file;
	std::ifstream m_training_labels_file;
	std::ifstream m_test_images_file;
	std::ifstream m_test_labels_file;
    */
	// file buffers
    /*
     * DATA is stored in high endian -> intel needs to convert from low endian (for own implementation)
     */
	std::vector<std::vector<unsigned char>> m_training_images;
    std::vector<std::vector<unsigned char>> m_test_images;
	std::vector<uint8_t> m_training_labels;
	std::vector<uint8_t> m_test_labels;

/*
// methodes
private:
	std::vector<unsigned char> read_label_file_into_buffer(bool training_labels = true);
	std::vector<std::vector<unsigned char>> read_image_file_into_buffer(std::ifstream image_set);
*/
};


#endif