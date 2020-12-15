#include "Athlete.h"
#include "Date.h"
#include "FilenameException.h"
#include "InvalidAthleteID.h"
#include "UnparseableDateException.h"

#include <iostream>
#include <vector>
#include <stdarg.h>

const Date CURRENT_DATE = Date(14, 12, 2020); 



bool ascending_ages(const Athlete& athlete1, const Athlete& athlete2) {
    return athlete1.get_age(CURRENT_DATE) < athlete2.get_age(CURRENT_DATE);    
}
bool descending_ages(const Athlete& athlete1, const Athlete& athlete2) {
    return athlete1.get_age(CURRENT_DATE) > athlete2.get_age(CURRENT_DATE);
}


double average_time(int n, ...) {
    double average= 0.0;
    va_list vl;
    va_start(vl, n); 

    for (int i = 0; i < n; i++) {
        average += va_arg(vl, double);  
    }

    return average / n;
}



int main() {

    try {
        // Read athletes from a file
        std::string filename;
        std::cout << "Enter path to your 'athletes.csv' file: ";
        std::cin >> filename;

        std::vector<Athlete> athletes = Athlete::load_from_file(filename);
        for (const auto& a : athletes) 
            std::cout << a.to_string() << std::endl << std::endl;
        

        // Sort them descending by age
        Athlete::sort_athletes(athletes, descending_ages);
        std::cout << "\n=== DESCENDING SORTED ATHLETES (by age) ===\n";
        for (const auto& a : athletes) 
            std::cout << a.to_string() << std::endl << std::endl;


        // Sort them ascending by age
        Athlete::sort_athletes(athletes, ascending_ages);
        std::cout << "\n=== ASCENDING SORTED ATHLETES (by age) ===\n";
        for (const auto& a : athletes) 
            std::cout << a.to_string() << std::endl << std::endl;

        // Writing to a file
        Athlete::save_to_file(athletes, "/home/alex/Documents/cpp_oop/task1001/sorted_athletes.txt");

        // Calling a function with variable number of parameters
        std::cout << "\n\n=== Athlete's average time ===\n" << average_time(3, 55.5, 34.5, 39.2) << " minutes\n";

    } catch (const UnparseableDateException& e) {
        std::cout << e.what() << std::endl;
    } catch (const FilenameException& e) {
        std::cout << e.what() << std::endl;
    } catch (const InvalidAthleteID& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    


    return 0;
}
