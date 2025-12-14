// main.cpp
#include <iostream>
#include <string>
#include "../code/library.h" // Corrected path

using namespace std;

int main() {
    Library lib;
    int choice, bookID;
    string title, author, category;
    int copies;

    do {
        cout << "\n========= LIBRARY SYSTEM (Console Mode) =========\n";
        cout << "1. Add New Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Delete Book\n";
        cout << "5. View All Books (Forward)\n";
        cout << "6. View All Books (Reverse)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book Title: ";
            cin.ignore(); // Clear buffer
            getline(cin, title); // Use getline for titles with spaces
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Category: ";
            getline(cin, category);
            cout << "Enter Number of Copies: ";
            cin >> copies;

            lib.addBook(title, author, category, copies); // Corrected call
            cout << "Book added successfully.\n";
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> bookID;
            if (lib.borrowBook(bookID)) {
                cout << "Book borrowed successfully.\n";
            } else {
                cout << "Failed to borrow book. Check ID or availability.\n";
            }
            break;

        case 3:
            cout << "Enter Book ID: ";
            cin >> bookID;
            if (lib.returnBook(bookID)) {
                cout << "Book returned successfully.\n";
            } else {
                cout << "Failed to return book. Check ID.\n";
            }
            break;

        case 4:
            cout << "Enter Book ID: ";
            cin >> bookID;
            if (lib.deleteBook(bookID)) {
                cout << "Book deleted successfully.\n";
            } else {
                cout << "Failed to delete book. Check ID.\n";
            }
            break;

        case 5:
            cout << "\n--- All Books (Forward) ---\n";
            cout << lib.getAllBooks();
            break;

        case 6:
            cout << "\n--- All Books (Reverse) ---\n";
            cout << lib.getAllBooksReverse();
            break;

        case 7:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
