#pragma once

#include <iostream>


class Date {
    private:
        int day;
        int month;
        int year;
        
    public:
        Date();
        Date(int day, int month, int year);
        Date(const Date& d);
        ~Date();

        // GET
        int get_day() const;
        int get_month() const;
        int get_year() const;

        // SET 
        void set_day(const int& day);
        void set_month(const int& month);
        void set_year(const int& year);

        std::string to_string() const;
        static Date get_date_from_string(const std::string& date);
};


