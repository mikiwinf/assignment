#include <iostream>
#include <string>

enum Classification {
    EXCELLENT,
    GOOD,
    AVERAGE,
    POOR
};

Classification classificationByScore(float score) {
    if (score < 5) return POOR;
    else if (score < 6.5) return AVERAGE;
    else if (score < 8) return GOOD;
    else return EXCELLENT;
}

std::string toString(Classification c) {
    switch (c) {
        case POOR: return "Poor";
        case AVERAGE: return "Average";
        case GOOD: return "Good";
        case EXCELLENT: return "Excellent";
        default: return "";
    }
}

int main() {
    float score;
    std::cout << "Enter score: ";
    std::cin >> score;
    Classification c = classificationByScore(score);
    std::cout << "Classification: " << toString(c) << std::endl;
    return 0;
}
