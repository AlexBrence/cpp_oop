#include <iostream>


// GLOBAL VARIABLES 
bool running = true;


// FUNCTIONS
std::string red(const std::string& text) {
    return "\033[1;91m" + text + "\033[0m";
}


std::string blue(const std::string& text) {
    return "\033[1;94m" + text + "\033[0m";
}

std::string blue_background(const std::string& text) {
    return "\033[1;44m" + text + "\033[0m";
}


void main_menu() {
    int choice;

    std::cout << "\t\t\t" << blue("CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM") << "\n\n\n";
    std::cout << "\t\t\t" << blue_background("        ") << blue(" WELCOME TO THE MAIN MENU ") << blue_background("        ") << "\n\n";
    std::cout << blue("\t1. Create new account") << std::endl;
    std::cout << blue("\t2. Update information of existing account") << std::endl;
    std::cout << blue("\t3. For transactions") << std::endl;
    std::cout << blue("\t4. Check the details of existing account") << std::endl;
    std::cout << blue("\t5. Removing existing account") << std::endl;
    std::cout << blue("\t6. View customer's list") << std::endl;
    std::cout << blue("\t7. Exit") << "\n\n\n\n";

    std::cout << blue("\tEnter your choice: ");
    std::cin >> choice;

    if (choice > 7 || choice < 1) {
        while (choice > 7 || choice < 1) {
            std::cout << red("\tERROR: Invalid input!\n\n");

            std::cout << blue("\tEnter your choice: ");
            std::cin >> choice;
        }
    }

    switch(choice) {
        case 1:
            //new_account();
            system("clear");
            break;
            
        case 2:
            //view_list();
            system("clear");
            break;
            
        case 3:
            //edit();
            system("clear");
            break;

        case 4:
            //transact();
            system("clear");
            break; 
            
        case 5:
            //erase();
            system("clear");
            break;

        case 6:
            //see();
            system("clear");
            break;

        case 7:
            running = false;
            break;

        default:
            std::cout << red("\tERROR: Invalid input!\n\n");
            system("clear");
            return;
    }

}


int main() {

    while (running) {
        main_menu();
    }


    return 0;
}
