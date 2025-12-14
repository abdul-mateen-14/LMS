// ui/add_book_window.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/fl_message.H>

#include "../code/library.h"
#include "add_book_window.h"

extern Library lib;

// Helper struct to hold pointers to input fields, preventing memory leaks
struct AddBookInputs {
    Fl_Input* title;
    Fl_Input* author;
    Fl_Input* category;
    Fl_Input* copies;
};

void openAddBookWindow() {
    // Window
    Fl_Window *win = new Fl_Window(420, 330, "Add New Book");
    win->color(FL_LIGHT2);

    // Input Group
    Fl_Group *grp = new Fl_Group(40, 30, 340, 230);

    // Title Label + Input
    Fl_Box *titleLabel = new Fl_Box(50, 40, 120, 30, "Title:");
    titleLabel->labelfont(FL_HELVETICA_BOLD);
    titleLabel->labelsize(14);
    Fl_Input *title = new Fl_Input(180, 40, 200, 30);
    title->box(FL_FLAT_BOX);
    title->color(FL_WHITE);
    title->textsize(14);

    // Author Label + Input
    Fl_Box *authorLabel = new Fl_Box(50, 90, 120, 30, "Author:");
    authorLabel->labelfont(FL_HELVETICA_BOLD);
    authorLabel->labelsize(14);
    Fl_Input *author = new Fl_Input(180, 90, 200, 30);
    author->box(FL_FLAT_BOX);
    author->color(FL_WHITE);
    author->textsize(14);

    // Category Label + Input
    Fl_Box *catLabel = new Fl_Box(50, 140, 120, 30, "Category:");
    catLabel->labelfont(FL_HELVETICA_BOLD);
    catLabel->labelsize(14);
    Fl_Input *category = new Fl_Input(180, 140, 200, 30);
    category->box(FL_FLAT_BOX);
    category->color(FL_WHITE);
    category->textsize(14);

    // Copies Label + Input
    Fl_Box *copyLabel = new Fl_Box(50, 190, 120, 30, "Copies:");
    copyLabel->labelfont(FL_HELVETICA_BOLD);
    copyLabel->labelsize(14);
    Fl_Input *copies = new Fl_Input(180, 190, 200, 30);
    copies->box(FL_FLAT_BOX);
    copies->color(FL_WHITE);
    copies->textsize(14);

    grp->end();

    // Add Button
    Fl_Button *btn = new Fl_Button(180, 250, 100, 50, "Add");
    btn->color(FL_BLUE);
    btn->labelcolor(FL_WHITE);
    btn->labelfont(FL_HELVETICA_BOLD);
    btn->labelsize(14);

    // --- CORRECTED CALLBACK ---
    AddBookInputs* inputs = new AddBookInputs{title, author, category, copies};

    btn->callback([](Fl_Widget*, void *d){
        AddBookInputs* inp = static_cast<AddBookInputs*>(d);

        string t = inp->title->value();
        string a = inp->author->value();
        string c = inp->category->value();
        int copyCount = atoi(inp->copies->value());

        if (t.empty() || a.empty() || c.empty()) {
            fl_message("Error: All fields must be filled!");
            delete inp; // Clean up even on error
            return;
        }

        if (copyCount <= 0) {
            fl_message("Error: Copies must be greater than zero!");
            delete inp; // Clean up even on error
            return;
        }

        lib.addBook(t, a, c, copyCount);
        fl_message("Book Added Successfully!");

        delete inp; // IMPORTANT: Clean up the memory

    }, inputs);

    win->end();
    win->show();
}
