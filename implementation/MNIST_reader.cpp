#define WINDOWS_ENV 0

#include "../headers/MNIST_reader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

MNIST_reader::MNIST_reader() {
#if WINDOWS_ENV == 1
    std::string base_path_assets = "C:\\Users\\bohre\\dev\\private\\machine_learning\\neuronal_networks\\Zahlen_Erkennung\\Neuronales_Netz\\assets\\";
    // paths training data
    std::string path_training_images = base_path_assets + "MNIST_DATABASE\\train-images-idx3-ubyte";
    std::string path_training_labels = base_path_assets + "MNIST_DATABASE\\train-labels-idx1-ubyte";

    // paths test data
    std::string path_test_images = base_path_assets + "MNIST_DATABASE\\t10k-images-idx3-ubyte";
    std::string path_test_labels = base_path_assets + "MNIST_DATABASE\\t10k-labels-idx3-ubyte";
#else
    // paths training data
    std::string path_training_images = "../assets/MNIST_DATABASE/train-images-idx3-ubyte";
    std::string path_training_labels = "../assets/MNIST_DATABASE/train-labels-idx1-ubyte";

    // paths test data
    std::string path_test_images = "../assets/MNIST_DATABASE/t10k-images-idx3-ubyte";
    std::string path_test_labels = "../assets/MNIST_DATABASE/t10k-labels-idx3-ubyte";
#endif
    // if WIN ENV : full paths
	m_training_images = std::ifstream(path_training_images, std::ios::binary);
	m_training_labels = std::ifstream(path_training_labels, std::ios::binary);

	m_test_images = std::ifstream(path_test_images, std::ios::binary);
	m_test_labels = std::ifstream(path_test_images, std::ios::binary);

	if (!m_training_images.is_open()
		|| !m_training_labels.is_open()
		|| !m_test_images.is_open()
		|| !m_test_labels.is_open()) {
		std::cout << "ERROR beim oeffnen eines Datensatzes" << std::endl;
		exit(-1);
	} else
        std::cout << "Alle Datensaetze konnten geoefnet werden!" << std::endl << std::endl;

	read_label_file_into_buffer();
}

std::vector<char> MNIST_reader::read_label_file_into_buffer(bool training_labels) {
	const uint32_t magic_number = 2049;
	const uint32_t offset = 4;

    //auto* actual_magic_number = new uint32_t ();
    //auto* actual_number_of_objects = new uint32_t();

    uint32_t actual_magic_number = 0;
    uint32_t actual_number_of_objects = 0;

    char file_name_buffer[24];
    char first_two_bytes_always_0[2];

    m_training_labels.read(first_two_bytes_always_0, 2);
    m_training_labels.read(reinterpret_cast<char*>(&actual_magic_number), sizeof(uint32_t));
    m_training_labels.read(reinterpret_cast<char*>(&actual_number_of_objects), sizeof(uint32_t));
	m_training_labels.read(file_name_buffer, 24 * sizeof(char));

#if WINDOWS_ENV == 0
    // INTEL PROCESSOR USES LOW ENDIAN -> SWAP
    //*actual_magic_number = __builtin_bswap32(*actual_magic_number);
    //*actual_number_of_objects = __builtin_bswap32(*actual_number_of_objects);

    actual_magic_number = __builtin_bswap32(actual_magic_number);
    actual_number_of_objects = __builtin_bswap32(actual_number_of_objects);
#endif

    std::cout << "actual_magic_number: " << actual_magic_number << std::endl << std::endl;
    std::cout << "actual_number_of_items: " << actual_number_of_objects << std::endl << std::endl;
	for (const char item : file_name_buffer)
		std::cout << item;
    std::cout << std::endl << std::endl;


    std::vector<uint8_t> labels; // die label Daten sind in unsigned bytes (8Bit als unsigned int) gespeichert

	std::vector<char> res_vec;
	return res_vec;
}

std::vector<char> MNIST_reader::read_image_file_into_buffer(std::ifstream image_set) {
	const unsigned int magic_number = 2051;
	const unsigned int offset = 4;

	std::vector<char> buffer;

	return buffer;
}

