## 📚 Library Management System (DSA Project)

## 📌 Project Description
This project is a C++ based Library Management System with a graphical user interface built using FLTK. The system allows librarians to manage books by adding, borrowing, returning, deleting, and viewing books. Data persistence is achieved using file handling on the server side.


## 🛠️ Technologies Used
- C++
- FLTK (Fast Light Toolkit)
- MinGW (g++)
- VS Code


## 📁 Folder Structure
Project/
│
├── code/ # Core logic & data structures
├── ui/ # GUI files (FLTK)
├── server/ # Server-side file handling
│ └── data/ # Stored data files
├── docs/ # Flowcharts & diagrams
├── testcases/ # Test case files
├── report.pdf
├── demo.mp4
└── README.md


## ▶️ How to Run the Project

### 1️⃣ Install Dependencies
- Install MinGW (C++ compiler)
- Install FLTK (same architecture as compiler)

### 2️⃣ Build the Project
Open VS Code and run:
Ctrl + Shift + B


### 3️⃣ Run the GUI
Execute:
LibraryGUI.exe


## 🖥️ Features
- Add new books
- Borrow books
- Return books
- Delete books
- View all books
- File-based data storage


## 💾 File Handling
All book data is saved in:
server/data/books.txt


Data is automatically:
- Loaded on startup
- Saved after every update


## 📊 Data Structures Used
- Dynamic Array
- Used to store book records
- Resizes automatically when full


## 🎥 Demo
A short demo video (`demo.mp4`) is included showing all major features.

