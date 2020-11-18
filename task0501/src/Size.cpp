#include "Size.h" 
#include <sstream> 

Size::Size() : width(0.0f), height(0.0f), unit("not defined") {
}

Size::Size(const float& w, const float& h, const std::string& u) : width(w), height(h), unit(u) {
}

Size::Size(const Size& s) : width(s.width), height(s.height), unit(s.unit) {
}

Size::~Size() {
}



void Size::set_width(const float& w) {
    width = w;
}

void Size::set_height(const float& h) {
    height = h;
}

void Size::set_unit(const std::string& u) {
    unit = u;
}


float Size::get_width() const {
    return width;
}

float Size::get_height() const {
    return height;
}

std::string Size::get_unit() const {
    return unit;
}

std::string Size::to_string() const {
    std::stringstream ss;

    ss << "Width: " << width << unit << ", Height: " << height << unit;

    return ss.str();
}
