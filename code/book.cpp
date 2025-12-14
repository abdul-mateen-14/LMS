#include "book.h"

Book::Book() {
    bookID = 0;
    copies = 0;
}

Book::Book(int id, string t, string a, string c, int copyCount) {
    bookID = id;
    title = t;
    author = a;
    category = c;
    copies = copyCount;
}

