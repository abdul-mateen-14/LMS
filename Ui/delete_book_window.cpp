#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/fl_message.H>

#include "delete_book_window.h"
#include "../code/library.h"

extern Library lib;

void openDeleteBookWindow() {

    // Create main window
    Fl_Window* w = new Fl_Window(400, 200, "Delete Book");
    w->color(FL_LIGHT2);

    // Group for inputs
    Fl_Group* grp = new Fl_Group(50, 40, 300, 60);

    // Book ID label
    Fl_Box* idLabel = new Fl_Box(60, 50, 80, 30, "Book ID:");
    idLabel->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    idLabel->labelsize(14);
    idLabel->labelfont(FL_HELVETICA_BOLD);

    // Book ID input
    Fl_Input* idInp = new Fl_Input(150, 50, 180, 30);
    idInp->box(FL_FLAT_BOX);
    idInp->color(FL_WHITE);
    idInp->textsize(14);

    grp->end();

    // Delete button
    Fl_Button* btn = new Fl_Button(160, 120, 80, 40, "Delete");
    btn->color(FL_RED);
    btn->labelcolor(FL_WHITE);
    btn->labelfont(FL_HELVETICA_BOLD);
    btn->labelsize(14);

    // Callback
    btn->callback([](Fl_Widget*, void* ptr){
        Fl_Input* in = (Fl_Input*)ptr;
        int bookID = atoi(in->value());

        if (bookID <= 0) {
            fl_message("? Invalid Book ID!");
            return;
        }

        lib.deleteBook(bookID);
        fl_message("? Book Deleted Successfully!");
    }, idInp);

    w->end();
    w->show();
}

