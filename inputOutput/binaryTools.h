#ifndef BINARYTOOLS_H
#define BINARYTOOLS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdint>
#include <cassert>

class BinaryTools 
{
public:
    /* 
    * Function to read binary data into a float array
    */
    static std::vector<float> readBinaryToFloatArray(const std::string& fileName);
    /*
    * Function to read binary data into an integer array
    */
    static std::vector<int32_t> readBinaryToIntArray(const std::string& fileName);
};

#endif