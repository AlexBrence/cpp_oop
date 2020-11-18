#ifndef LAYOUT_H
#define LAYOUT_H 

#include "View.h" 
#include <iostream>
#include <vector>


class Layout {
    private:
        std::vector<View*> views;

    public:
        void add_view(View* view);
        View* get_view(const int& position) const;
        int size() const;
        void draw() const;
};


#endif
