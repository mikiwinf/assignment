#include <iomanip>
#include <iostream>
#include <string>

struct Student {
    std::string id;
    std::string name;
    int age;
    std::string gender;
    std::string address;
    float average;
};

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
                                        << std::setw(15) << "Average" << std::endl;

    std::cout << std::left << std::setw(15) << s.id
                           << std::setw(15) << s.name
                           << std::setw(15) << s.age
                           << std::setw(15) << s.gender
                           << std::setw(15) << s.address
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.average << std::endl;
}

int main() {
    Student s;
    inputInfo(s);
    printInfo(s);
    return 0;
}
