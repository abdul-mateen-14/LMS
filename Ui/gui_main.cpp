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

// --- Color Palette (for easy theme changes) ---
const Fl_Color COLOR_BACKGROUND = fl_rgb_color(245, 245, 250);      // Soft light blue/gray
const Fl_Color COLOR_PANEL = fl_rgb_color(255, 255, 255);         // White
const Fl_Color COLOR_ACCENT = fl_rgb_color(52, 152, 219);         // A nice blue
const Fl_Color COLOR_TEXT_DARK = fl_rgb_color(44, 62, 80);        // Dark blue/gray
const Fl_Color COLOR_TEXT_LIGHT = fl_rgb_color(255, 255, 255);    // White

// Global Library object
Library lib;

// Helper function to create a styled button
Fl_Button* createStyledButton(int x, int y, int w, int h, const char* label, Fl_Color color, const char* tooltip = nullptr) {
    Fl_Button* btn = new Fl_Button(x, y, w, h, label);
    btn->color(color);
    btn->labelcolor(COLOR_TEXT_LIGHT);
    btn->labelfont(FL_HELVETICA_BOLD);
    btn->labelsize(16);
    btn->box(FL_ROUND_UP_BOX);
    if (tooltip) {
        btn->tooltip(tooltip);
    }
    return btn;
}

int main() {
    // Main window
    Fl_Window* win = new Fl_Window(520, 600, "Library Management System");
    win->color(COLOR_BACKGROUND);

    // --- Title Section ---
    Fl_Box* title = new Fl_Box(0, 30, 520, 60, "Library Management System");
    title->labelfont(FL_HELVETICA_BOLD);
    title->labelsize(28);
    title->labelcolor(COLOR_ACCENT);
    title->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    Fl_Box* subtitle = new Fl_Box(0, 80, 520, 30, "Manage your book collection with ease");
    subtitle->labelfont(FL_HELVETICA);
    subtitle->labelsize(14);
    subtitle->labelcolor(COLOR_TEXT_DARK);
    subtitle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    // --- Main Action Panel ---
    Fl_Group* actionPanel = new Fl_Group(40, 140, 440, 280);
    actionPanel->box(FL_FLAT_BOX);
    actionPanel->color(COLOR_PANEL);
    actionPanel->begin();

    // Action Buttons
    Fl_Button* addBookBtn = createStyledButton(60, 160, 400, 50, "Add New Book", COLOR_ACCENT, "Add a new book to the library");
    Fl_Button* borrowBtn = createStyledButton(60, 220, 400, 50, "Borrow Book", fl_rgb_color(46, 204, 113), "Borrow a book from the library");
    Fl_Button* returnBtn = createStyledButton(60, 280, 400, 50, "Return Book", fl_rgb_color(241, 196, 15), "Return a borrowed book");
    Fl_Button* deleteBtn = createStyledButton(60, 340, 400, 50, "Delete Book", fl_rgb_color(231, 76, 60), "Remove a book from the library");

    actionPanel->end();

    // --- Bottom Section ---
    Fl_Group* bottomPanel = new Fl_Group(40, 440, 440, 120);
    bottomPanel->box(FL_NO_BOX);
    bottomPanel->begin();

    Fl_Button* viewBtn = createStyledButton(60, 460, 190, 50, "View All Books", fl_rgb_color(52, 73, 94), "View all books in the library");
    Fl_Button* exitBtn = createStyledButton(270, 460, 190, 50, "Exit", fl_rgb_color(149, 165, 166), "Exit the application");

    bottomPanel->end();

    // --- Callbacks ---
    addBookBtn->callback([](Fl_Widget*, void*) { openAddBookWindow(); });
    borrowBtn->callback([](Fl_Widget*, void*) { openBorrowBookWindow(); });
    returnBtn->callback([](Fl_Widget*, void*) { openReturnBookWindow(); });
    deleteBtn->callback([](Fl_Widget*, void*) { openDeleteBookWindow(); });
    viewBtn->callback([](Fl_Widget*, void*) { openViewBooksWindow(false); });
    exitBtn->callback([](Fl_Widget*, void*) {
        if (fl_choice("Are you sure you want to exit?", "Cancel", "Exit", 0) == 1) {
            exit(0);
        }
    });

    win->resizable(win);
    win->end();
    win->show();

    return Fl::run();
}
