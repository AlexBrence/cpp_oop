#pragma once

#include <iostream>

class FilenameException : public std::exception {
    private:
        std::string message;

    public:
        explicit FilenameException(const std::string& filename);
        const char* what() const noexcept override;
};


