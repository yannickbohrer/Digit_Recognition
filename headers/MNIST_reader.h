#ifndef MNIST_READER_H
#define MNIST_READER_H

#include <fstream>
#include <vector>


class MNIST_reader {
public:
	MNIST_reader();


// attributes
private:
	// raw files
	std::ifstream m_training_images;
	std::ifstream m_training_labels;
	std::ifstream m_test_images;
	std::ifstream m_test_labels;

	// file buffers
    /*
     * DATA is stored in high endian -> intel needs to convert from low endian
     */
	std::vector<char> m_buffer_training_images;
	std::vector<char> m_buffer_training_labels;
	std::vector<char> m_buffer_test_images;
	std::vector<char> m_buffer_test_labels;

// methodes
private:
	std::vector<char> read_label_file_into_buffer(bool training_labels = true);
	std::vector<char> read_image_file_into_buffer(std::ifstream image_set);

};


#endif