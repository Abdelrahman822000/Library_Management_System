Here's the updated README with the parts related to Qt removed:

---

**This Project was developed by Abdelrahman Mohamed Hamad**

# Library Management System

A C++ application that enables users to manage books in a library, allowing them to borrow, return, and view book availability status.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Contact](#contact)

## Project Description

The Library Management System is a console application developed using C++. It enables users to manage a library's book inventory by providing options to borrow, return, and display the availability of books. It simplifies library management and offers a user-friendly interface for book management.

## Features

- **Display All Books:** List all the books in the library along with their availability status.
- **Borrow Book:** Allows users to borrow an available book.
- **Return Book:** Enables users to return a previously borrowed book.
- **Exit:** Exit the application.

## Installation

### Prerequisites

- C++ Compiler (e.g., GCC, Clang, MSVC)

### Steps

1. **Clone the repository:**
    ```bash
    git clone https://github.com/Abdelrahman822000/Library_Management_System.git
    cd Library_Management_System
    ```

2. **Build the project:**
    ```bash
    g++ main.cpp -o LibraryManagementSystem
    ```

3. **Run the Program:**
    ```bash
    ./LibraryManagementSystem
    ```

## Usage

### Running the Application

1. **Start the Application:**
    - After running the `LibraryManagementSystem` executable, follow the on-screen instructions to display all books, borrow a book, return a book, or exit the system.

2. **Menu Options:**
    - **Display All Books:** Lists all the books in the library along with their current status (available/borrowed).
    - **Borrow Book:** Lets users borrow books from the library by choosing from the list of available books.
    - **Return Book:** Users can return a borrowed book and update its status.
    - **Exit:** Exit the program.

### Example Output

```
Welcome to the Library Management System!
1. Display All Books
2. Borrow Book
3. Return Book
4. Exit
Please choose an option (1-4): 1
Books Available in the Library:
1. The Great Gatsby - Available
2. 1984 - Borrowed
3. To Kill a Mockingbird - Available
4. Moby Dick - Available

1. Display All Books
2. Borrow Book
3. Return Book
4. Exit
Please choose an option (1-4): 2
Enter the number of the book you want to borrow: 1
You have borrowed "The Great Gatsby".
1. Display All Books
2. Borrow Book
3. Return Book
4. Exit
Please choose an option (1-4): 3
Enter the number of the book you want to return: 2
You have returned "1984".
1. Display All Books
2. Borrow Book
3. Return Book
4. Exit
Please choose an option (1-4): 4
Thank you for using the Library Management System!
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions, feel free to contact me:
- **Phone:** +201028325749
- **Email:** a.mohamed822000@gmail.com
- **LinkedIn:** [Abdelrahman Mohamed Hamad](https://www.linkedin.com/in/abdelrahman-mohamed-a1956b247/)