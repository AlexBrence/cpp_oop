#include "FilenameException.h"


FilenameException::FilenameException(const std::string& filename) {
    message = "Error opening file: " + filename;
}


const char* FilenameException::what() const noexcept {
    return message.c_str();
}
