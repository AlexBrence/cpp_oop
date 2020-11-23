#pragma once 

#include "View.h" 
#include <iostream>
#include <memory>
#include <vector>


class Layout {
    private:
        std::vector<std::unique_ptr<View>> views;

    public:
        void add_view(std::unique_ptr<View> view);
        std::unique_ptr<View> get_view(const int& position);
        int size() const;
        void draw() const;
};


