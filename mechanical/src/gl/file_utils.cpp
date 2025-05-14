#include "mechanical/gl/file_utils.hpp"
#include <SDL3/SDL.h>
#include <fstream>
#include <sstream>

namespace me {

void utilsReadFile(const std::string& filepath, std::string& result) {
    std::ifstream in(filepath, std::ios::in | std::ios::binary);
    if (in) {
        in.seekg(0, std::ios::end);
        result.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&result[0], result.size());
        in.close();
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "File \"%s\" not found.", filepath.c_str());
        throw std::string("File not found: " + filepath);
    }
}

void textToStringArray(const std::string& sIn, std::vector<std::string>& vOut, char delimiter) {
    std::string token;
    std::istringstream tokenStream(sIn);
    while (std::getline(tokenStream, token, delimiter))
        vOut.push_back(token);
}

} // namespace me
