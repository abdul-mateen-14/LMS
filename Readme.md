# 📚 Library Management System

A modern, desktop-based **Library Management System** built with **C++** and the **FLTK (Fast Light Toolkit)** GUI library. This application provides a clean and intuitive graphical interface for managing a library's book collection, including adding, borrowing, returning, and deleting books. All data is persisted locally using a text file to ensure simplicity and reliability.

---

## 📑 Table of Contents

* Project Description
* Key Features
* Installation & Dependencies
* How to Run

  * Running the GUI Application
  * Running the Server Test
* Folder Structure

---

## 📖 Project Description

This project was developed to demonstrate the practical application of **Object-Oriented Programming (OOP)**, **dynamic data structures**, and **file I/O** in C++. It features a responsive and user-friendly GUI built using FLTK, along with a robust backend that handles all core library operations.

The system is lightweight, portable, and easy to set up, making it suitable for small libraries, educational institutions, and academic demonstrations.

---

## ✨ Key Features

* ➕ Add new books with title, author, category, and copy count
* 📖 Borrow books with automatic availability checking
* ↩️ Return borrowed books
* 🗑️ Delete books from the collection
* 👁️ View a complete, scrollable list of all books
* 💾 Automatic data persistence using a local `.txt` file

---

## 🛠️ Installation & Dependencies

To compile and run this project, the following dependencies are required:

### 1️⃣ Install a C++ Compiler

**Linux (Debian/Ubuntu):**

```bash
sudo apt update
sudo apt install build-essential g++
```

**macOS (Xcode Command Line Tools):**

```bash
xcode-select --install
```

**Windows:**

* Install **MinGW-w64** via MSYS2 or download it directly
* Ensure `g++` is added to the system PATH

---

### 2️⃣ Install the FLTK Library

**Linux (Debian/Ubuntu):**

```bash
sudo apt install libfltk1.3-dev
```

**macOS (Homebrew):**

```bash
brew install fltk
```

**Windows:**

1. Download the latest FLTK 1.3.x or 1.4.x development package from the official FLTK website
2. Extract it to a permanent directory (e.g., `C:\fltk`)
3. Update paths in `.vscode/tasks.json` if FLTK is installed in a different location

---

## ▶️ How to Run

This project includes multiple components. The **GUI application** is the primary interface.

---

### 🖥️ Running the GUI Application

1. Open the complete project folder in **Visual Studio Code**
2. Press `Ctrl + Shift + P` to open the command palette
3. Select **Tasks: Run Build Task**
4. Choose **Build GUI Application**
5. After successful compilation, an executable will be generated:

   * Linux/macOS: `library_app`
   * Windows: `LibraryGUI.exe`

Run the application:

```bash
./library_app
```

---

### 🧪 Running the Server Test (Console Backend Test)

This mode tests the backend logic without the GUI.

**Compile manually:**

```bash
g++ -std=c++17 -I./code server.cpp code/library.cpp code/book.cpp -o server_test
```

**Run the test:**

```bash
./server_test
```

This will execute predefined operations and display results in the terminal.

---

## 📁 Folder Structure

```
Library Management System/
├── .vscode/                 # VS Code build and launch configurations
│   ├── launch.json
│   └── tasks.json
│
├── code/                    # Core business logic
│   ├── book.h
│   ├── book.cpp
|   ├── main.cpp              # Console-only entry point
│   ├── library.h
│   └── library.cpp
│
├── ui/                      # GUI components (FLTK)
│   ├── add_book_window.h/.cpp
|   ├── gui_main.cpp              # GUI application entry point
│   ├── borrow_book_window.h/.cpp
│   ├── return_book_window.h/.cpp
│   ├── delete_book_window.h/.cpp
│   └── view_books_window.h/.cpp
│
├── server/                  # Data persistence module
│   ├── server.cpp                # Backend test entry point
|   └── data/
│       └── books.txt        # Auto-generated data file
│
├── docs/                    # Documentation and diagrams
│   └── diagrams.png
├── testcases/                    # Testcases
│   ├── test_cases.md
│
└── report.pdf                # Project Report
└── README.md                 # Project documentation
```

---

📄 For a detailed explanation of system design, algorithms, and testing, please refer to **`docs/report.pdf`**.

---

✅ *This project is developed for academic purposes and demonstrates core concepts of Data Structures & Algorithms using C++.*

