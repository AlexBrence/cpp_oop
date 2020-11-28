#pragma once

#include <iostream>

class Date {
    private:
        int day;
        int month;
        int year;

    public:
        Date();
        Date(const int& day, const int& month, const int& year);
        Date(const Date& dt);
        ~Date();

        // GET
        int get_day() const;
        int get_month() const;
        int get_year() const;

        // SET
        void set_day(const int& day);
        void set_month(const int& month);
        void set_year(const int& year);

        // OTHER
        std::string to_string() const;

        friend std::ostream& operator<<(std::ostream& out, const Date& date);
        bool operator==(const Date& other) const;
        Date& operator++();
        Date operator++(int dummy);
};


