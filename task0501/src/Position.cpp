#include "Position.h"
#include <sstream> 

Position::Position() : x(0.0f), y(0.0f) {
}

Position::Position(const float& x, const float& y) : x(x), y(y) {
}

Position::Position(const Position& p) : x(p.x), y(p.y) {
}

Position::~Position() {
}



void Position::set_x(const float& x) {
    this->x = x;
}

void Position::set_y(const float& y) {
    this->y = y;
}

float Position::get_x() const {
    return x;
}

float Position::get_y() const {
    return y;
}

std::string Position::to_string() const {
    std::stringstream ss;
    
    ss << "x: " << x << ", y: " << y;
    
    return ss.str();
}
