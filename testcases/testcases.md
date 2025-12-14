# Test Cases – Library Management System

| Test Case ID | Description | Pre-conditions | Test Steps | Expected Result | Status |
|---|---|---|---|---|---|
| **TC-ADD-01** | Add a valid book | Library is empty or has existing books. | 1. Open "Add Book" window.<br>2. Enter "C++ Primer" for Title.<br>3. Enter "Lippman" for Author.<br>4. Enter "Programming" for Category.<br>5. Enter "5" for Copies.<br>6. Click "Add". | A success message appears. The new book is visible in the "View Books" window with ID 1 (or next available ID) and 5 copies. | Pass |
| **TC-ADD-02** | Add a book with empty title | Library is empty. | 1. Open "Add Book" window.<br>2. Leave Title empty.<br>3. Fill other fields.<br>4. Click "Add". | An error message "All fields must be filled!" appears. No book is added. | Pass |
| **TC-ADD-03** | Add a book with zero copies | Library is empty. | 1. Open "Add Book" window.<br>2. Fill all fields.<br>3. Enter "0" for Copies.<br>4. Click "Add". | An error message "Copies must be greater than zero!" appears. No book is added. | Pass |
| **TC-BRW-01** | Borrow an available book | A book with ID 1 and 5 copies exists. | 1. Open "Borrow Book" window.<br>2. Enter "1" for Book ID.<br>3. Click "Borrow". | A success message appears. The book's copy count is reduced to 4. | Pass |
| **TC-BRW-02** | Borrow a book with no copies available | A book with ID 2 and 0 copies exists. | 1. Open "Borrow Book" window.<br>2. Enter "2" for Book ID.<br>3. Click "Borrow". | An error message "Book not available!" appears. | Pass |
| **TC-BRW-03** | Borrow a non-existent book | No book with ID 99 exists. | 1. Open "Borrow Book" window.<br>2. Enter "99" for Book ID.<br>3. Click "Borrow". | An error message "Book not available!" appears. | Pass |
| **TC-RTN-01** | Return a borrowed book | A book with ID 1 has been borrowed. | 1. Open "Return Book" window.<br>2. Enter "1" for Book ID.<br>3. Click "Return". | A success message appears. The book's copy count increases by 1. | Pass |
| **TC-RTN-02** | Return a non-existent book | No book with ID 99 exists. | 1. Open "Return Book" window.<br>2. Enter "99" for Book ID.<br>3. Click "Return". | An error message "Book not found!" appears. | Pass |
| **TC-DEL-01** | Delete an existing book | A book with ID 1 exists. | 1. Open "Delete Book" window.<br>2. Enter "1" for Book ID.<br>3. Click "Delete". | A success message appears. The book is removed from the system. | Pass |
| **TC-DEL-02** | Delete a non-existent book | No book with ID 99 exists. | 1. Open "Delete Book" window.<br>2. Enter "99" for Book ID.<br>3. Click "Delete". | An error message "Invalid Book ID!" appears. | Pass |
