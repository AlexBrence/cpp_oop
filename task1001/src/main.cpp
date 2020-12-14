#include "Athlete.h"
#include "Date.h"
#include "UnparseableDateException.h"

#include <iostream>
#include <vector>


int main() {

    try {
        // Reading from file not working, debug it
        std::vector<Athlete> athletes = Athlete::load_from_file("../athletes.csv");
        for (const auto& a : athletes) 
            std::cout << a.to_string() << std::endl << std::endl;
        

    } catch (UnparseableDateException& e) {
        std::cout << e.what() << std::endl;
    }
    


    return 0;
}
