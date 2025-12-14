#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/fl_ask.H>

#include "add_book_window.h"
#include "borrow_book_window.h"
#include "return_book_window.h"
#include "delete_book_window.h"
#include "view_books_window.h"

#include "../code/library.h"

Library lib; // Global Library object

int main() {

    // Main window
    Fl_Window* win = new Fl_Window(500, 500, "Library Management System");
    win->color(FL_LIGHT2);

    // Title
    Fl_Box* title = new Fl_Box(0, 20, 500, 60, "Library Management System");
    title->labelfont(FL_HELVETICA_BOLD);
    title->labelsize(26);
    title->labelcolor(FL_BLUE);
    title->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    // Panel
    Fl_Box* panel = new Fl_Box(80, 100, 340, 360);
    panel->box(FL_FLAT_BOX);
    panel->color(FL_GRAY);
    panel->redraw();

    // Button group
    Fl_Group* btnGroup = new Fl_Group(90, 110, 320, 340);

    // Add Book Button
    Fl_Button* addBookBtn = new Fl_Button(100, 120, 300, 50, "Add Book");
    addBookBtn->color(FL_BLUE);
    addBookBtn->labelcolor(FL_WHITE);
    addBookBtn->labelfont(FL_HELVETICA_BOLD);
    addBookBtn->labelsize(16);
    addBookBtn->box(FL_ROUND_UP_BOX);
    addBookBtn->tooltip("Add a new book to the library");
    addBookBtn->callback([](Fl_Widget*, void*) { openAddBookWindow(); });

    // Borrow Book Button
    Fl_Button* borrowBtn = new Fl_Button(100, 190, 300, 50, "Borrow Book");
    borrowBtn->color(FL_GREEN);
    borrowBtn->labelcolor(FL_WHITE);
    borrowBtn->labelfont(FL_HELVETICA_BOLD);
    borrowBtn->labelsize(16);
    borrowBtn->box(FL_ROUND_UP_BOX);
    borrowBtn->tooltip("Borrow a book from the library");
    borrowBtn->callback([](Fl_Widget*, void*) { openBorrowBookWindow(); });

    // Return Book Button
    Fl_Button* returnBtn = new Fl_Button(100, 260, 300, 50, "Return Book");
    returnBtn->color(FL_YELLOW);
    returnBtn->labelcolor(FL_BLACK);
    returnBtn->labelfont(FL_HELVETICA_BOLD);
    returnBtn->labelsize(16);
    returnBtn->box(FL_ROUND_UP_BOX);
    returnBtn->tooltip("Return a borrowed book");
    returnBtn->callback([](Fl_Widget*, void*) { openReturnBookWindow(); });

    // Delete Book Button
    Fl_Button* deleteBtn = new Fl_Button(100, 330, 300, 50, "Delete Book");
    deleteBtn->color(FL_RED);
    deleteBtn->labelcolor(FL_WHITE);
    deleteBtn->labelfont(FL_HELVETICA_BOLD);
    deleteBtn->labelsize(16);
    deleteBtn->box(FL_ROUND_UP_BOX);
    deleteBtn->tooltip("Remove a book from the library");
    deleteBtn->callback([](Fl_Widget*, void*) { openDeleteBookWindow(); });

    // View Books Button
    Fl_Button* viewBtn = new Fl_Button(100, 400, 300, 50, "View Books");
    viewBtn->color(FL_DARK_CYAN);
    viewBtn->labelcolor(FL_WHITE);
    viewBtn->labelfont(FL_HELVETICA_BOLD);
    viewBtn->labelsize(16);
    viewBtn->box(FL_ROUND_UP_BOX);
    viewBtn->tooltip("View all books in the library");
    viewBtn->callback([](Fl_Widget*, void*) { openViewBooksWindow(false); });

    btnGroup->end();

    win->resizable(win);
    win->end();
    win->show();

    return Fl::run();
}


