#ifndef VIEW_H
#define VIEW_H


#include "Position.h"
#include "Size.h"
#include <iostream>


class View {
    protected:
        Position position;
        Size size;
        bool visible;

    public:
        View();
        View(const Position& p, const Size& s);
        View(const View& v);
        ~View();

        // SET
        void set_position(const float& x, const float& y);
        void set_size(const float& w, const float& h, const std::string& u); 
        void set_visible(const bool& v);

        // GET
        Position get_position() const;
        Size get_size() const;
        bool is_visible() const;
        
        // OTHER
        virtual void draw() const; 
};


#endif
