# Object-Oriented Library Manager

A simple menu-driven library management system developed using C++. This project demonstrates object-oriented programming concepts such as classes, encapsulation, objects, and collections.

## Features

- Add new books with a unique ID, title, and author.
- Display all available book records.
- Search for a book using its ID.
- Borrow a book.
- Return a borrowed book.
- Check book availability status.
- Validate user input and handle invalid operations.
- Prevent duplicate book IDs.

## Technologies Used

- C++
- Standard Template Library (STL)
- Vector
- String and stringstream

## Requirements

- A C++ compiler such as GCC or MinGW.
- C++11 or newer.

## How to Compile and Run

Compile the program using:

```bash
g++ -std=c++11 main.cpp -o library_manager
```

Run on Linux, macOS, or Termux:

```bash
./library_manager
```

On Windows:

```bash
library_manager.exe
```

## Menu Options

1. Add Book
2. List Books
3. Search Book by ID
4. Borrow Book
5. Return Book
6. Exit

## How It Works

The `Book` class stores the book ID, title, author, and borrowing status. The `Library` class manages the collection of books and provides functions to add, list, search, borrow, and return books.

The application displays a menu and accepts user choices. It validates IDs and prevents duplicate book IDs and invalid borrowing or returning operations.

## Current Limitation

Book records are stored in memory only. The records are lost when the program exits because file persistence is not implemented in this version.

## Author

Created as a C++ Programming project.# Object-Oriented-Library-Manager-
