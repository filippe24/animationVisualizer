#include "shaderLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>


// const char* shaderLoader::readShaderFile(const char* filePath) {
//     static std::string shaderCode;
//     std::ifstream shaderFile;
//     shaderFile.open(filePath);

//     if (!shaderFile.is_open()) {
//         std::cerr << "Failed to open shader file: " << filePath << std::endl;
//         return nullptr;
//     }

//     std::stringstream shaderStream;
//     shaderStream << shaderFile.rdbuf();
//     shaderFile.close();

//     shaderCode = shaderStream.str();
//     return shaderCode.c_str();
// }

std::string shaderLoader::readShaderFile(const char* filePath) {
    std::ifstream shaderFile;
    shaderFile.open(filePath);

    if (!shaderFile.is_open()) {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        return "";
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

    return shaderStream.str();
}