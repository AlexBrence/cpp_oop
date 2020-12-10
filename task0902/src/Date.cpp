#include "Date.h"

#include <sstream>

Date::Date() : day(0), month(0), year(0) {
}

Date::Date(const int& day, const int& month, const int& year) : day(day), month(month), year(year) {
}

Date::Date(const Date& dt) : day(dt.day), month(dt.month), year(dt.year) {
}

Date::~Date() {
}



int Date::get_day() const {
    return day;
}

int Date::get_month() const {
    return month;
}

int Date::get_year() const {
    return year;
}


void Date::set_day(const int& day) {
    this->day = day;
}

void Date::set_month(const int& month) {
    this->month = month;
}

void Date::set_year(const int& year) {
    this->year = year;
}



std::string Date::to_string() const {
    std::stringstream ss;

    ss << day << ". " << month << ". " << year;

    return ss.str();
}


bool Date::operator==(const Date& other) const {
    bool same_day   = day == other.get_day();
    bool same_month = month == other.get_month();
    bool same_year  = year == other.get_year();

    if (same_day && same_month && same_year)
        return true;

    return false;
}

Date& Date::operator++() {
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day == months[month - 1]) {
        day = 1;
        (month == 12 ? (month = 1, year = year + 1) : month = month + 1);
    } else 
        day += 1;

    return *this;
}

Date Date::operator++(int dummy) {
    Date tmp(*this);
    ++(*this);

    return tmp;
}


