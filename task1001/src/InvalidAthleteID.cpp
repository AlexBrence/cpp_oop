#include "InvalidAthleteID.h"

#include <sstream>

InvalidAthleteID::InvalidAthleteID(const std::string& id) {
    message = "Invalid Athlete's ID: " + id;
}


const char* InvalidAthleteID::what() const noexcept {
    return message.c_str();
}
