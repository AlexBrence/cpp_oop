#pragma once

#include <iostream>


class UnparseableDateException : public std::exception {
    private:
        std::string message;

    public:
        explicit UnparseableDateException(const std::string& date); 
        const char* what() const noexcept override;
};


