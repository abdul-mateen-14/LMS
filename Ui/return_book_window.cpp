#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>

#include "return_book_window.h"
#include "../code/library.h"

extern Library lib;

void openReturnBookWindow() {

    // Main window
    Fl_Window* w = new Fl_Window(400, 220, "Return Book");
    w->color(FL_LIGHT2);

    // Book ID label
    Fl_Box* label = new Fl_Box(50, 50, 100, 30, "Book ID:");
    label->labelfont(FL_HELVETICA_BOLD);
    label->labelsize(14);

    // Book ID input
    Fl_Input* bookIdInput = new Fl_Input(160, 50, 180, 30);
    bookIdInput->textsize(14);

    // Return button
    Fl_Button* btn = new Fl_Button(160, 120, 80, 40, "Return");
    btn->color(FL_YELLOW);
    btn->labelcolor(FL_BLACK);
    btn->labelfont(FL_HELVETICA_BOLD);
    btn->labelsize(14);

    // Correct callback (fully closed)
    btn->callback([](Fl_Widget*, void* ptr) {
        Fl_Input* in = (Fl_Input*)ptr;
        int bookID = atoi(in->value());

        if (bookID <= 0) {
            fl_message("? Invalid Book ID!");
            return;
        }

        if (lib.returnBook(bookID))
            fl_message("? Book returned successfully!");
        else
            fl_message("? Book not found!");
    }, bookIdInput);

    w->end();
    w->show();
}

