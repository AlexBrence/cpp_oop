#include "View.h" 


View::View() : position(), size(), visible(true) {
}

View::View(const Position& p, const Size& s) : position(p), size(s), visible(true) {
}

View::View(const View& v) : position(v.position), size(v.size), visible(v.visible) {
}

View::~View() {
}


void View::set_position(const float& x, const float& y) {
    position.set_x(x);
    position.set_y(y);
}


void View::set_size(const float& w, const float& h, const std::string& u) {
    size.set_width(w);
    size.set_height(h);
    size.set_unit(u);
}


void View::set_visible(const bool& v) {
    visible = v;
}


Position View::get_position() const {
    Position tmp(position.get_x(), position.get_y());

    return tmp;
}


Size View::get_size() const {
    Size tmp(size.get_width(), size.get_height(), size.get_unit());

    return tmp;
}

bool View::is_visible() const {
    return visible;
}

void View::draw() const {

    if (visible) {
        std::cout << "=== View ===\n";
        std::cout << position.to_string() << std::endl;
        std::cout << size.to_string() << std::endl;
        std::cout << "Visible: true"; 
    } else 
        std::cout << "Visible is set to false!";
    
    std::cout << std::endl; 
}
