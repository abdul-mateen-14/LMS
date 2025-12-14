#include <iostream>
#include <fstream>
#include <string>
#include "../code/library.h"

using namespace std;

// Global Library object (server-side)
Library lib;

// -------------------------------------------------------
// Save all books to file
// -------------------------------------------------------
void saveToFile() {
    lib.saveToFile();
}

// -------------------------------------------------------
// Fetch all books and write to temp file
// -------------------------------------------------------
void fetchAll() {
    ofstream fout("server/data/temp_view.txt");
    fout << lib.getAllBooks();
    fout.close();
}

// -------------------------------------------------------
// Add a new book
// -------------------------------------------------------
void addBook(string title, string author, string category, int copies) { // Updated
    lib.addBook(title, author, category, copies); // Updated
    saveToFile();

// -------------------------------------------------------
// Borrow a book
// -------------------------------------------------------
void borrowBook(int bookID) {
    lib.borrowBook(bookID);
    saveToFile();
}

// -------------------------------------------------------
// Return a book
// -------------------------------------------------------
void returnBook(int bookID) {
    lib.returnBook(bookID);
    saveToFile();
}

// -------------------------------------------------------
// Delete a book
// -------------------------------------------------------
void deleteBook(int bookID) {
    lib.deleteBook(bookID);
    saveToFile();
}

// -------------------------------------------------------
// Console mode (Optional backend testing)
// -------------------------------------------------------
int main() {

    cout << "LIBRARY SERVER STARTED (Console Mode)\n";
    cout << "This program acts as backend for GUI.\n\n";

    // Sample backend test
    addBook("The C++ Programming Language", "Bjarne Stroustrup", "Programming", 5);
    borrowBook(1);
    returnBook(1);
    fetchAll();

    cout << "Server demo actions completed.\n";
    return 0;
}

