#ifndef POSITION_H
#define POSITION_H


#include <iostream>

class Position {
    private:
        float x;
        float y;

    public:
        Position();
        Position(const float& x, const float& y);
        Position(const Position& p);
        ~Position();

        // SET
        void set_x(const float& x);
        void set_y(const float& y);   

        // GET
        float get_x() const;
        float get_y() const;

        // OTHER
        std::string to_string() const;
};


#endif
