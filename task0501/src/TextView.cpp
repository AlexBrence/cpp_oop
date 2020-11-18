#include "TextView.h"
#include <algorithm>

TextView::TextView() : text("Empty"), capitalize(false) {
}

TextView::TextView(const Position& position, const Size& size, const std::string& text) : View(position, size), text(text), capitalize(false) {
}

TextView::TextView(const TextView& tw) : View(tw.position, tw.size), text(tw.text), capitalize(tw.capitalize) {
}

TextView::~TextView() {
}



void TextView::set_text(const std::string& text) {
    this->text = text;
}

void TextView::set_capitalize(const bool& capitalize) {
    this->capitalize = capitalize;
}

std::string TextView::get_text() const {
    return text;
}

bool TextView::is_capitalize() const {
    return capitalize;
}

void TextView::draw() const {
    if (visible) {
        View::draw();

        std::cout << "=TextView=\n";
        if (capitalize) {
            std::string tmp = text;

            transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
            std::cout << tmp << std::endl;
        } else 
            std::cout << text << std::endl;
        
        std::cout << "Capitalize: " << (capitalize ? "true" : "false") << std::endl;
    } else 
        std::cout << "Visible is set to false!" << std::endl;
    
}
