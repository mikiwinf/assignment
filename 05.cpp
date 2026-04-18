#include <iomanip>
#include <iostream>
#include <string>

struct Book {
    std::string title;
    float price;
};

void inputBook(Book* b) {
    std::cout << "Enter title: ";
    std::getline(std::cin, b->title);

    std::cout << "Enter price: ";
    std::cin >> b->price;
    std::cin.ignore();
}

void printHeader() {
    std::cout << std::endl << std::left << std::setw(15) << "Title"
                                        << std::setw(15) << "Price" << std::endl;
}

void printBook(const Book* b) {
    std::cout << std::left << std::setw(15) << b->title
                           << std::setw(15) << std::fixed << std::setprecision(2) << b->price << std::endl;
}

void printBooksInfo(Book** list, int n) {
    printHeader();
    for (int i = 0; i < n; i++) {
        printBook(list[i]);
    }
}

void findBook(Book** list, int n) {
    std::string title;
    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    for (int i = 0; i < n; i++) {
        if (list[i]->title == title) {
            printHeader();
            printBook(list[i]);
            return;
        }
    }
    std::cout << "Book not found";
}

void sortAscending(Book** list, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[i]->price > list[j]->price) {
                Book* temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void deleteBooks(Book** list, int n) {
    for (int i = 0; i < n; i++) {
        delete list[i];
    }
    delete[] list;
}

int main() {
    int n;
    std::cout << "Enter number of books: ";
    std::cin >> n;
    std::cin.ignore();

    Book** list = new Book*[n];

    for (int i = 0; i < n; i++) {
        list[i] = new Book;
        inputBook(list[i]);
    }

    int choice;
    while (true) {
        std::cout << "\n=== MENU ===" << std::endl;
        std::cout << "1. Print books information" << std::endl;
        std::cout << "2. Find book information" << std::endl;
        std::cout << "3. Sort books information" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                printBooksInfo(list, n);
                break;
            case 2:
                findBook(list, n);
                break;
            case 3:
                sortAscending(list, n);
                printBooksInfo(list, n);
                break;
            case 4:
                deleteBooks(list, n);
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
}
