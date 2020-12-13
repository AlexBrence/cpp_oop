#include "../include/SmartPointer.h"
#include "../include/Date.h"

#include <iostream>


std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.to_string();
    return out;
}


int main() {

    SmartPointer<Date> date1(new Date(10, 10, 2000));
    SmartPointer<Date> date2(new Date(31, 12, 1998));
    SmartPointer<Date> date3(new Date(31, 3, 2001));
    SmartPointer<Date> date4(new Date(10, 10, 2000));

    std::cout << *date1 << std::endl;


    const bool is_same = *date1 == *date4;
    std::cout << (is_same ? "true\n" : "false\n");

    std::cout << ++(*date2) << std::endl;
    *date1 = (*date1)++;

    std::cout << *date1 << std::endl;


    return 0;
}
