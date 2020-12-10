#include "SmartPointer.h" 
#include "Date.h"

#include <iostream>



std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.to_string();
    return out;
}



int main() {
    SmartPointer<Date> date1(new Date(1, 1, 2020));
    SmartPointer<Date> date2(new Date(1, 1, 2019));
    date2 = date1 = date1 = date1 = date1 = date1;
    date2 = date2;
    date2 = date2;
    std::cout << "reference count: " << date2.use_count() << std::endl;

    return 0;
}
