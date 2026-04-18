#include <iostream>

union Information {
    char phone[20];
    char email[50];
    char address[100];
};

int main() {
    Information info;
    std::cout << "Enter phone number: ";
    std::cin.getline(info.phone, 20);
    std::cout << "Phone number: " << info.phone << std::endl;
    std::cout << "Enter email: ";
    std::cin.getline(info.email, 50);
    std::cout << "Email: " << info.email << std::endl;
    std::cout << "Enter address: ";
    std::cin.getline(info.address, 100);
    std::cout << "Address: " << info.address << std::endl;
    return 0;
}
