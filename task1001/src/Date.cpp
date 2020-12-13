#include "Date.h"
#include "UnparseableDateException.h"

#include <sstream>
#include <cctype> 

Date::Date() : day(0), month(0), year(0) {}
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year) {}
Date::~Date() {}


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


Date Date::get_date_from_string(const std::string& date) {
    int number_of_dots = 0;
    int date_arr[3];

    // If char is not digit nor dot throw an exception
    for (const auto& ch : date) {
        if (ch == '.') number_of_dots++;
        if (!isdigit(ch) && ch != '.') 
            throw UnparseableDateException(date);
    } 

    if (number_of_dots != 2)
        throw UnparseableDateException(date);


    // String to int, save into date_arr for later usage
    int index = 0;
    std::string tmp = "";
    for (const auto& ch : date) {
        if (ch != '.') 
            tmp += ch;
        else {
            date_arr[index++] = std::stoi(tmp); 
            tmp = "";
        }

        // If it is the last digit finish
        if (&ch == &date[date.length() - 1])
            date_arr[index++] = std::stoi(tmp); 
    }

    // If day or month is incorrect
    if (date_arr[0] < 1 || date_arr[0] > 31 || date_arr[1] < 1 || date_arr[1] > 12)
        throw UnparseableDateException(date);


    return Date(date_arr[0], date_arr[1], date_arr[2]);
}
