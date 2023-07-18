#include "MNIST_reader.h"

#include <iostream>
#include <fstream>
#include <string>

MNIST_reader::MNIST_reader() {
	std::string base_path_assets = "C:\\Users\\bohre\\dev\\private\\machine_learning\\neuronal_networks\\Zahlen_Erkennung\\Neuronales_Netz\\assets\\";

	// paths training data
	std::string full_path_training_images = base_path_assets + "MNIST_DATABASE\\train-images-idx3-ubyte";
	std::string full_path_training_labels = base_path_assets + "MNIST_DATABASE\\train-labels-idx1-ubyte";

	std::string full_path_test_images = base_path_assets + "MNIST_DATABASE\\t10k-images-idx3-ubyte";
	std::string full_path_test_labels = base_path_assets + "MNIST_DATABASE\\t10k-labels-idx3-ubyte";

	// paths test data
	m_training_images = std::ifstream(full_path_training_images, std::ios::binary | std::ios::in);
	m_training_labels = std::ifstream(full_path_training_labels, std::ios::binary | std::ios::in);

	m_test_images = std::ifstream(full_path_training_images, std::ios::binary | std::ios::in);
	m_test_labels = std::ifstream(full_path_training_images, std::ios::binary | std::ios::in);

	if (!m_training_images.is_open()
		|| !m_training_labels.is_open()
		|| !m_test_images.is_open()
		|| !m_test_labels.is_open()) {
		std::cout << "ERROR beim oeffnen eines Datensatzes" << std::endl;
		exit(-1);
	}

	read_label_file_into_buffer();
}

std::vector<unsigned char> MNIST_reader::read_label_file_into_buffer(bool training_labels) {
	/*
	std::ifstream label_set;
	if (training_labels)
		label_set = m_training_labels;
	else
		label_set = m_test_labels;
	*/
	const unsigned int magic_number = 2049;
	const unsigned int offset = 4;
	//size_t length = label_set.tellg();
	
	//if (sizeof(char_buffer) < length)
		//length = sizeof(char_buffer);

	//label_set.read(char_buffer, length);


	char buffer[34];		// training labels file ist genau 28881 Bytes lang

	m_training_labels.read(buffer, 34 * sizeof(char));

	for (const char item : buffer)
		std::cout << item << " ";


	std::vector<unsigned char> res_vec;

	return res_vec;
}

std::vector<unsigned char> MNIST_reader::read_image_file_into_buffer(std::ifstream image_set) {
	const unsigned int magic_number = 2051;
	const unsigned int offset = 4;

	std::vector<unsigned char> buffer;

	return buffer;
}

