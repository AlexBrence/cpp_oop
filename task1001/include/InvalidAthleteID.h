#pragma once

#include <iostream>

class InvalidAthleteID : public std::exception {
    private:
        std::string message;

    public:
        explicit InvalidAthleteID(const std::string& id);
        const char* what() const noexcept override;
};


