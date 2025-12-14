// code/library.h
#pragma once
#include <string>
#include "book.h" // Include the single, correct Book definition

using namespace std;

class Library {
private:
    Book* books;
    int size;
    int capacity;
    int nextId;

public:
    Library();
    ~Library();

    // Core operations (UPDATED SIGNATURES)
    void addBook(string title, string author, string category, int copies); // Added category
    bool borrowBook(int id);
    bool returnBook(int id);
    bool deleteBook(int id);
    string getAllBooks();
    string getAllBooksReverse(); // Added this missing method

    // Helper for the UI view window
    int getSize() const;
    Book getBookAt(int index) const;

    // FILE HANDLING 
    void saveToFile();
    void loadFromFile();
};
