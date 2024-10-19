#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <string>

class shaderLoader {
public:
    static std::string readShaderFile(const char* filePath);

};

#endif // SHADERLOADER_H