#pragma once
#include <string>
#include <vector>

namespace me {

    void utilsReadFile(const std::string& filepath, std::string& result);
    void textToStringArray(const std::string& sIn, std::vector<std::string>& vOut, char delimiter);

} // namespace me
