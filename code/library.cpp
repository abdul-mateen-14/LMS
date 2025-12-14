// code/library.cpp
#include "library.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm> // For reverse in getAllBooksReverse

using namespace std;
namespace fs = std::filesystem;

// Constructor
Library::Library() {
    capacity = 10;
    size = 0;
    nextId = 1;
    books = new Book[capacity];

    // Ensure folder exists
    fs::create_directories("server/data");

    // Load existing data
    loadFromFile();
}

// Destructor
Library::~Library() {
    saveToFile();
    delete[] books;
}

// Add book (UPDATED)
void Library::addBook(string title, string author, string category, int copies) {
    if (size == capacity) {
        capacity *= 2;
        Book* temp = new Book[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = books[i];
        delete[] books;
        books = temp;
    }

    books[size++] = { nextId++, title, author, category, copies }; // Added category
    saveToFile();
}

// Borrow book
bool Library::borrowBook(int id) {
    for (int i = 0; i < size; i++) {
        if (books[i].bookID == id && books[i].copies > 0) { // Use bookID
            books[i].copies--;
            saveToFile();
            return true;
        }
    }
    return false;
}

// Return book
bool Library::returnBook(int id) {
    for (int i = 0; i < size; i++) {
        if (books[i].bookID == id) { // Use bookID
            books[i].copies++;
            saveToFile();
            return true;
        }
    }
    return false;
}

// Delete book
bool Library::deleteBook(int id) {
    for (int i = 0; i < size; i++) {
        if (books[i].bookID == id) { // Use bookID
            for (int j = i; j < size - 1; j++)
                books[j] = books[j + 1];
            size--;
            saveToFile();
            return true;
        }
    }
    return false;
}

// View all books
string Library::getAllBooks() {
    stringstream ss;
    ss << "ID\tTitle\tAuthor\tCategory\tCopies\n";
    ss << "------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        ss << books[i].bookID << "\t" << books[i].title << "\t" << books[i].author << "\t" << books[i].category << "\t" << books[i].copies << "\n";
    }
    return ss.str();
}

// View all books in reverse (ADDED)
string Library::getAllBooksReverse() {
    stringstream ss;
    ss << "ID\tTitle\tAuthor\tCategory\tCopies\n";
    ss << "------------------------------------------------\n";

    for (int i = size - 1; i >= 0; i--) {
        ss << books[i].bookID << "\t" << books[i].title << "\t" << books[i].author << "\t" << books[i].category << "\t" << books[i].copies << "\n";
    }
    return ss.str();
}

// Helper methods for UI
int Library::getSize() const {
    return size;
}

Book Library::getBookAt(int index) const {
    if (index >= 0 && index < size) {
        return books[index];
    }
    return Book(); // Return a default empty book if index is invalid
}


// SAVE DATA TO FILE (UPDATED to include category)
void Library::saveToFile() {
    ofstream out("server/data/books.txt");
    for (int i = 0; i < size; i++) {
        out << books[i].bookID << "|"
            << books[i].title << "|"
            << books[i].author << "|"
            << books[i].category << "|" // Added category
            << books[i].copies << "\n";
    }
    out.close();
}

// LOAD DATA FROM FILE (UPDATED to include category)
void Library::loadFromFile() {
    ifstream in("server/data/books.txt");
    if (!in) return;

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string idStr, title, author, category, copiesStr;

        getline(ss, idStr, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, category, '|'); // Added category
        getline(ss, copiesStr, '|');

        int id = stoi(idStr);
        int copies = stoi(copiesStr);

        if (size == capacity) {
            capacity *= 2;
            Book* temp = new Book[capacity];
            for (int i = 0; i < size; i++)
                temp[i] = books[i];
            delete[] books;
            books = temp;
        }

        books[size++] = { id, title, author, category, copies }; // Added category
        if (id >= nextId)
            nextId = id + 1;
    }
    in.close();
}
