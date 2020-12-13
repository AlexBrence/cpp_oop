#include "Date.h"
#include "UnparseableDateException.h"


#include <iostream>


int main() {

    try {

        Date date1 = Date::get_date_from_string("22.4.2020");
        Date date2 = Date::get_date_from_string("22.1.2020");
        std::cout << date1.to_string() << std::endl;
        std::cout << date2.to_string() << std::endl;

    } catch (UnparseableDateException& e) {
        std::cout << e.what() << std::endl;
    }
    


    return 0;
}
