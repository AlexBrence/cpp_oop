#include "Layout.h" 
#include <memory>


void Layout::add_view(std::unique_ptr<View> view) {
    views.emplace_back(std::make_unique<View>(*view));
}


std::unique_ptr<View> Layout::get_view(const int& position) {
    return std::move(views[position]);
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
