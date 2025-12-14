#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <sstream>
#include <iomanip>

#include "view_books_window.h"
#include "../code/library.h"

extern Library lib;

void openViewBooksWindow(bool showBorrowedOnly) {
    Fl_Window* win = new Fl_Window(650, 400, "View All Books");
    win->color(FL_LIGHT2);

    Fl_Browser* browser = new Fl_Browser(10, 10, 620, 340);
    browser->type(FL_HOLD_BROWSER);
    browser->labelfont(FL_COURIER);
    browser->textsize(12);

    // --- FIX IS HERE ---
    // Create the header string and then convert it to const char* with .c_str()
    std::string header = "@B@f@C" + std::string("ID\tTitle\t\t\tAuthor\t\t\tCategory\t\tCopies");
    browser->add(header.c_str());
    browser->add("--------------------------------------------------------------------------------------------------------------------");

    // Add books from the library
    for (int i = 0; i < lib.getSize(); ++i) {
        Book b = lib.getBookAt(i);
        std::stringstream ss;
        ss << left << setw(5) << b.bookID
           << setw(25) << (b.title.length() > 24 ? b.title.substr(0, 21) + "..." : b.title)
           << setw(25) << (b.author.length() > 24 ? b.author.substr(0, 21) + "..." : b.author)
           << setw(25) << (b.category.length() > 24 ? b.category.substr(0, 21) + "..." : b.category)
           << b.copies;
        browser->add(ss.str().c_str()); // This line was already correct
    }

    Fl_Button* closeBtn = new Fl_Button(275, 360, 100, 30, "Close");
    closeBtn->callback([](Fl_Widget*, void* w) {
        ((Fl_Window*)w)->hide();
    }, win);

    win->end();
    win->show();
}
