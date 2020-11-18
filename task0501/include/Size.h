#ifndef SIZE_H
#define SIZE_H

#include <iostream>


class Size {
    private:
        float width;
        float height;
        std::string unit;

    public:
        Size();
        Size(const float& w, const float& h, const std::string& u);
        Size(const Size& s);
        ~Size();

        // SET
        void set_width(const float& w);
        void set_height(const float& h);
        void set_unit(const std::string& u);

        // GET
        float get_width() const;
        float get_height() const;
        std::string get_unit() const;

        // OTHER
        std::string to_string() const;
};


#endif
