#include "Athlete.h"
#include "FilenameException.h"
#include "InvalidAthleteID.h"

#include <algorithm>
#include <fstream>
#include <sstream>


Athlete::Athlete(int id, std::string f_name, std::string l_name, Date b_date, std::string country) : 
    id(id), first_name(f_name), last_name(l_name), birth_date(b_date), country(country) {}

Athlete::Athlete(const Athlete& a) :
    id(a.id), first_name(a.first_name), last_name(a.last_name), birth_date(a.birth_date), country(a.country) {}

Athlete::~Athlete() {}



std::string Athlete::to_string() const {
    std::stringstream ss;

    ss << "Id: " << id;
    ss << "\nFirst name: " << first_name;
    ss << "\nLast name: " << last_name;
    ss << "\nBirth date: " << birth_date.to_string();
    ss << "\nCountry: " << country;

    return ss.str();
}


int Athlete::get_age(const Date& current_date) const {
    int age = current_date.get_year() - birth_date.get_year();

    if (current_date.get_month() == birth_date.get_month()) {
        if (current_date.get_day() < birth_date.get_day())
            age -= 1;
    } else if (current_date.get_month() < birth_date.get_month())
        age -= 1;

    return age;
}


std::vector<Athlete> Athlete::load_from_file(const std::string& filename) {
    std::vector<Athlete> athletes;
    std::ifstream my_file(filename);
    std::string line, _id, _first_name, _last_name, _birth_date, _country;

    if (my_file.is_open()) {
       while (getline(my_file, line)) {
           std::istringstream iss(line);

           getline(iss, _id, ',');
           getline(iss, _first_name, ',');
           getline(iss, _last_name, ',');
           getline(iss, _birth_date, ',');
           getline(iss, _country, '\n'); 

           if (_id.length() != 8)
                throw InvalidAthleteID(_id);

           int id_to_int = std::stoi(_id);
           athletes.emplace_back(Athlete(id_to_int, _first_name, _last_name, Date::get_date_from_string(_birth_date), _country));
        } 

    my_file.close();
    } else {
        throw FilenameException(filename);
    }

    return athletes;
}


void Athlete::sort_athletes(std::vector<Athlete>& athletes, bool(*c)(const Athlete&, const Athlete&)) {
    std::sort(athletes.begin(), athletes.end(), *c); 
}
