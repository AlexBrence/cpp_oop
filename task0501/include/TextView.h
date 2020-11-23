#pragma once

#include <iostream>
#include "View.h"


class TextView : public View {
    private:
        std::string text;
        bool capitalize;

    public:
        TextView();
        TextView(const Position& position, const Size& size, const std::string& text);
        TextView(const TextView& tw);
        ~TextView();
        
        // SET 
        void set_text(const std::string& text);
        void set_capitalize(const bool& capitalize);

        // GET
        std::string get_text() const;
        bool is_capitalize() const;

        // OTHER
        void draw() const override;
};


