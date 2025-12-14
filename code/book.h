#pragma once
#include <string>
using namespace std;

class Book {
public:
    int bookID;
    string title;
    string author;
    string category;
    int copies;

    Book();
    Book(int id, string t, string a, string c, int copyCount);
};

