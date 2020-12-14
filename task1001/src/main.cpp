#include "Athlete.h"
#include "Date.h"
#include "FilenameException.h"
#include "InvalidAthleteID.h"
#include "UnparseableDateException.h"

#include <iostream>
#include <vector>

const Date CURRENT_DATE = Date(14, 12, 2020); 



bool ascending_ages(const Athlete& athlete1, const Athlete& athlete2) {
    return athlete1.get_age(CURRENT_DATE) < athlete2.get_age(CURRENT_DATE);    
}
bool descending_ages(const Athlete& athlete1, const Athlete& athlete2) {
    return athlete1.get_age(CURRENT_DATE) > athlete2.get_age(CURRENT_DATE);
}



int main() {

    try {
        // Read athletes from a file
        std::vector<Athlete> athletes = Athlete::load_from_file("/home/alex/Documents/cpp_oop/task1001/athletes.csv");
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
