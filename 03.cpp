#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Candidate {
    std::string name;
    std::string registrationNumber;
    float math, physics, chemistry, total;
};

void inputInfo(Candidate& c) {
    std::cout << "Enter name: ";
    std::getline(std::cin, c.name);

    std::cout << "Enter registration number: ";
    std::getline(std::cin, c.registrationNumber);

    std::cout << "Enter Math score: ";
    std::cin >> c.math;
    std::cin.ignore();

    std::cout << "Enter Physics score: ";
    std::cin >> c.physics;
    std::cin.ignore();

    std::cout << "Enter Chemistry score: ";
    std::cin >> c.chemistry;
    std::cin.ignore();

    c.total = c.math + c.physics + c.chemistry;
}

void inputCandidatesInfo(std::vector<Candidate>& candidates) {
    int n;
    std::cout << "\nEnter the number of candidates: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        Candidate s;
        std::cout << "\n=== Candidate " << i + 1 << " ===" << std::endl;
        inputInfo(s);
        candidates.push_back(s);
    }
}

void printHeader() {
    std::cout << std::endl << std::left << std::setw(15) << "Name"
                                        << std::setw(15) << "RN"
                                        << std::setw(15) << "Math"
                                        << std::setw(15) << "Physics"
                                        << std::setw(15) << "Chemistry"
                                        << std::setw(15) << "Total";
}

void printInfo(const Candidate& c) {
    std::cout << std::left << std::setw(15) << c.name
                           << std::setw(15) << c.registrationNumber
                           << std::setw(15) << std::fixed << std::setprecision(2) << c.math
                           << std::setw(15) << std::fixed << std::setprecision(2) << c.physics
                           << std::setw(15) << std::fixed << std::setprecision(2) << c.chemistry
                           << std::setw(15) << std::fixed << std::setprecision(2) << c.total;
}

void printCandidatesInfo(const std::vector<Candidate>& candidates) {
    printHeader();
    for (const auto& c : candidates) {
        printInfo(c);
    }
}

void printPassedCandidatesInfo(const std::vector<Candidate>& candidates, const float& admission) {
    printHeader();
    for (const auto& c : candidates) {
        if (c.total > admission) printInfo(c);
    }
}

int main() {
    std::vector<Candidate> candidates;
    inputCandidatesInfo(candidates);
    printCandidatesInfo(candidates);
    float admission;
    std::cout << "\nEnter admission score: ";
    std::cin >> admission;
    printPassedCandidatesInfo(candidates, admission);
    return 0;
}