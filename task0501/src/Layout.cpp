#include "Layout.h" 



void Layout::add_view(View* view) {
    views.emplace_back(view);
}

View* Layout::get_view(const int& position) const {
    for (const auto& v : views) {
        if (v->get_position().get_x() == position && v->get_position().get_y() == position)
            return v;
    }
    
    std::cout << "No view at this position: " << position << std::endl;
}


int Layout::size() const {
    return views.size();
}

void Layout::draw() const {
    int i = 1;
    for (const auto& v : views) {
        std::cout << "-> OBJECT " << i++ << " in views\n";
        v->draw();
    }
}
