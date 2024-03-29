#include "UnparseableDateException.h"


UnparseableDateException::UnparseableDateException(const std::string& date) {
    message = "Unparseable date: " + date;
}

const char* UnparseableDateException::what() const noexcept {
    return message.c_str();
} 
