#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int age;
    std::string gender;
    std::string address;
    float english, discreteMath, computerGraphics, specializedIT, average;
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

    std::cout << "Enter English score: ";
    std::cin >> s.english;
    std::cin.ignore();

    std::cout << "Enter Discrete Math score: ";
    std::cin >> s.discreteMath;
    std::cin.ignore();

    std::cout << "Enter Computer Graphics score: ";
    std::cin >> s.computerGraphics;
    std::cin.ignore();

    std::cout << "Enter Specialized IT score: ";
    std::cin >> s.specializedIT;
    std::cin.ignore();

    s.average = (s.english + s.discreteMath + s.computerGraphics + s.specializedIT) / 4;
}

void inputStudentsInfo(std::vector<Student>& students) {
    int n;
    std::cout << "\nEnter the number of students: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        Student s;
        std::cout << "\n=== Student " << i + 1 << " ===" << std::endl;
        inputInfo(s);
        students.push_back(s);
    }
}

void printHeader() {
    std::cout << std::endl << std::left << std::setw(15) << "ID"
                                        << std::setw(15) << "Name"
                                        << std::setw(15) << "Age"
                                        << std::setw(15) << "Gender"
                                        << std::setw(15) << "Address"
                                        << std::setw(15) << "English"
                                        << std::setw(15) << "DM"
                                        << std::setw(15) << "CG"
                                        << std::setw(15) << "SIT"
                                        << std::setw(15) << "Average" << std::endl;
}

void printInfo(const Student& s) {
    std::cout << std::left << std::setw(15) << s.id
                           << std::setw(15) << s.name
                           << std::setw(15) << s.age
                           << std::setw(15) << s.gender
                           << std::setw(15) << s.address
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.english
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.discreteMath
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.computerGraphics
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.specializedIT
                           << std::setw(15) << std::fixed << std::setprecision(2) << s.average << std::endl;
}

void printStudentsInfo(const std::vector<Student>& students) {
    printHeader();
    for (const auto& s : students) {
        printInfo(s);
    }
}

void sortAscending(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
        [](const auto& a, const auto& b) {
            return a.average < b.average;
        });
}

void findStudent(std::vector<Student>& students) {
    std::string id;
    std::cout << "\nEnter the ID: ";
    std::getline(std::cin, id);

    for (const auto& s : students) {
        if (s.id == id) {
            printHeader();
            printInfo(s);
            return;
        }
    }
    std::cout << "ID not found" << std::endl;
}

void menu(std::vector<Student>& students) {
    while (true) {
        std::cout << "\n=== MENU ===" << std::endl;
        std::cout << "1. Input student information" << std::endl;
        std::cout << "2. Print student information" << std::endl;
        std::cout << "3. Sort student information" << std::endl;
        std::cout << "4. Find student information" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                inputStudentsInfo(students);
                break;
            case 2:
                printStudentsInfo(students);
                break;
            case 3:
                sortAscending(students);
                printStudentsInfo(students);
                break;
            case 4:
                findStudent(students);
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
}

int main() {
    std::vector<Student> students;
    menu(students);
    return 0;
}
