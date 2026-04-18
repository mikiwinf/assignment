#include <iomanip>
#include <iostream>
#include <string>

struct BirthDate {
    int day, month, year;
};

struct Student {
    std::string id;
    std::string name;
    int age;
    std::string gender;
    std::string address;
    BirthDate bd;
    float average;
};

bool checkBirthDate(int day, int month, int year) {
    if (year <= 0) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    auto isLeapYear = [](int year) {
        return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    };

    switch (month) {
        case 4: case 6: case 9: case 11:
            return day <= 30;
        case 2:
            return day <= (isLeapYear(year) ? 29 : 28);
        default:
            return day <= 31;
    }
}

void inputBirthDate(BirthDate& bd) {
    while (true) {
        int day, month, year;
        char separator;

        std::cout << "Enter birth date (dd/mm/yyyy): ";
        std::cin >> day >> separator >> month >> separator >> year;
        std::cin.ignore();

        if (checkBirthDate(day, month, year)) {
            bd.day = day;
            bd.month = month;
            bd.year = year;
            break;
        }

        std::cout << "Invalid date, try again" << std::endl;
    }
}

void inputInfo(Student& s) {
    std::cout << "Enter ID: ";
    std::getline(std::cin, s.id);

    std::cout << "Enter name: ";
    std::getline(std::cin, s.name);

    std::cout << "Enter age: ";
    std::cin >> s.age;
    std::cin.ignore();

    std::cout << "Enter gender: ";
    std::getline(std::cin, s.gender);

    std::cout << "Enter address: ";
    std::getline(std::cin, s.address);

    inputBirthDate(s.bd);

    std::cout << "Enter average score: ";
    std::cin >> s.average;
    std::cin.ignore();
}

void printInfo(const Student& s) {
    std::cout << std::endl << std::left << std::setw(15) << "ID"
                                        << std::setw(15) << "Name"
                                        << std::setw(15) << "Age"
                                        << std::setw(15) << "Gender"
                                        << std::setw(15) << "Address"
                                        << std::setw(15) << "Birth date"
                                        << std::setw(15) << "Average" << std::endl;

    std::cout << std::left << std::setw(15) << s.id
                           << std::setw(15) << s.name
                           << std::setw(15) << s.age
                           << std::setw(15) << s.gender
                           << std::setw(15) << s.address
                           << std::setw(15) << std::to_string(s.bd.day) + "/" + std::to_string(s.bd.month) + "/" + std::to_string(s.bd.year)
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.average << std::endl;
}

int main() {
    Student s;
    inputInfo(s);
    printInfo(s);
    return 0;
}
