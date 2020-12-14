#pragma once

#include "Date.h"

#include <iostream>
#include <vector>


class Athlete {
    private:
        int id;
        std::string first_name;
        std::string last_name;
        Date birth_date;
        std::string country;

    public:
        Athlete(int id, std::string f_name, std::string l_name, Date b_date, std::string country);
        Athlete(const Athlete& a);
        ~Athlete();


        std::string to_string() const;
        int get_age(const Date& current_date) const;

        static std::vector<Athlete> load_from_file (const std::string& filename);
        static void sort_athletes(std::vector<Athlete>& athletes, bool(*c)(const Athlete&, const Athlete&));
};


