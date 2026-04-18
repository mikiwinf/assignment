#include <iostream>
#include <string>

enum Day {
    MONDAY = 2,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

std::string getDay(int value) {
    switch (value) {
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        case SUNDAY: return "Sunday";
        default: return "Invalid day";
    }
}

int main() {
    int day;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Day: " << getDay(day) << std::endl;
    return 0;
}
