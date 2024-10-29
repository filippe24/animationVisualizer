#include "binaryTools.h"

std::vector<float> BinaryTools::readBinaryToFloatArray(const std::string &fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return {};
    }

    // Record the file size
    file.seekg(0, std::ios::end);
    std::streamsize file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the first 4 bytes as an integer
    int32_t int_value = 0;
    file.read(reinterpret_cast<char*>(&int_value), sizeof(int_value));

    // Read the next 'int_value' number of integers
    std::vector<int32_t> int_array(int_value);
    file.read(reinterpret_cast<char*>(int_array.data()), int_value * sizeof(int32_t));

    // Calculate the total number of floats
    size_t num_floats = 1;
    for (int val : int_array) {
        num_floats *= val;
    }

    // Read the next 'num_floats' number of floats
    std::vector<float> float_array(num_floats);
    file.read(reinterpret_cast<char*>(float_array.data()), num_floats * sizeof(float));

    // Check if the file has been fully read
    std::streamsize bytes_read = file.tellg();
    if (bytes_read == file_size) {
        std::cout << "The whole file has been read." << std::endl;
    } else {
        std::cout << "Not all data was read. " << (file_size - bytes_read) << " bytes remain." << std::endl;
    }

    return float_array;
}

std::vector<int32_t> BinaryTools::readBinaryToIntArray(const std::string &fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return {};
    }

    // Record the file size
    file.seekg(0, std::ios::end);
    std::streamsize file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the first 4 bytes as an integer
    int32_t int_value = 0;
    file.read(reinterpret_cast<char*>(&int_value), sizeof(int_value));

    // Read the next 'int_value' number of integers
    std::vector<int32_t> int_array_shape(int_value);
    file.read(reinterpret_cast<char*>(int_array_shape.data()), int_value * sizeof(int32_t));

    // Calculate the total number of integers
    size_t num_integers = 1;
    for (int val : int_array_shape) {
        num_integers *= val;
    }

    // Read the next 'num_integers' number of integers
    std::vector<int32_t> int_array(num_integers);
    file.read(reinterpret_cast<char*>(int_array.data()), num_integers * sizeof(int32_t));

    // Check if the file has been fully read
    std::streamsize bytes_read = file.tellg();
    if (bytes_read == file_size) {
        std::cout << "The whole file has been read." << std::endl;
    } else {
        std::cout << "Not all data was read. " << (file_size - bytes_read) << " bytes remain." << std::endl;
    }

    return int_array;
}

