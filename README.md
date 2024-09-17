**This Project was developed by Abdelrahman Mohamed Hamad**

# Library Management System

A console-based application for managing a library, allowing users to borrow and return books, view transactions, and manage members.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Contact](#contact)

## Project Description

The Library Management System is a C++ console application designed to manage books and members in a library. It allows users to borrow and return books, view transaction history, and register or sign in as members. The system also provides functionalities to view all available books and members.

## Features

- **Add Books:** Add new books to the library.
- **Register Member:** Register new library members.
- **Borrow Book:** Borrow a book from the library.
- **Return Book:** Return a borrowed book.
- **Display Books:** Show all books in the library along with their availability.
- **Display Transactions:** View the history of borrowing and returning transactions.
- **Display Members:** View all registered library members.
- **Sign In/Sign Up:** Log in or register as a new member.

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
    g++ main.cpp Book.cpp Member.cpp Transaction.cpp Library.cpp operations.cpp -o LibraryManagementSystem
    ```

3. **Run the Program:**
    ```bash
    ./LibraryManagementSystem
    ```

## Usage

### Running the Application

1. **Start the Application:**
    - After running the `LibraryManagementSystem` executable, follow the on-screen instructions to interact with the library system.

2. **Menu Options:**
    - **Add Book:** Add a new book to the library.
    - **Register Member:** Register a new member in the library.
    - **Borrow Book:** Borrow a book from the library.
    - **Return Book:** Return a borrowed book.
    - **Display Books:** View all books and their availability.
    - **Display Transactions:** See the history of transactions (borrowing and returning).
    - **Display Members:** List all registered members.
    - **Sign In/Sign Up:** Log in or register as a member.

### Example Output

```
Book "The Great Gatsby" added to the library.
Book "1984" added to the library.
Book "To Kill a Mockingbird" added to the library.
Book "Moby Dick" added to the library.
Book "Pride and Prejudice" added to the library.
Book "War and Peace" added to the library.
Book "The Catcher in the Rye" added to the library.
Book "The Hobbit" added to the library.
Book "Crime and Punishment" added to the library.
Book "The Odyssey" added to the library.
Book "Jane Eyre" added to the library.
Book "Brave New World" added to the library.
Book "The Lord of the Rings" added to the library.
Book "Animal Farm" added to the library.
Book "Les Mis├⌐rables" added to the library.
Book "The Divine Comedy" added to the library.
Book "Ulysses" added to the library.
Book "One Hundred Years of Solitude" added to the library.
Book "The Brothers Karamazov" added to the library.
Book "Don Quixote" added to the library.
Book "Wuthering Heights" added to the library.
Book "A Tale of Two Cities" added to the library.

Welcome to the Library Management System!

1. Sign In
2. Sign Up
Enter your choice: 2
Enter your name: Abdelrahman
Enter a membership ID: 1234
ID 1234 is available.
Enter your contact information: 01028325749
Member "Abdelrahman" registered.

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 1
Library books:
The Great Gatsby by F. Scott Fitzgerald - Available
1984 by George Orwell - Available
To Kill a Mockingbird by Harper Lee - Available
Moby Dick by Herman Melville - Available
Pride and Prejudice by Jane Austen - Available
War and Peace by Leo Tolstoy - Available
The Catcher in the Rye by J.D. Salinger - Available
The Hobbit by J.R.R. Tolkien - Available
Crime and Punishment by Fyodor Dostoevsky - Available
The Odyssey by Homer - Available
Jane Eyre by Charlotte Bronte - Available
Brave New World by Aldous Huxley - Available
The Lord of the Rings by J.R.R. Tolkien - Available
Animal Farm by George Orwell - Available
Les Mis├⌐rables by Victor Hugo - Available
The Divine Comedy by Dante Alighieri - Available
Ulysses by James Joyce - Available
One Hundred Years of Solitude by Gabriel Garcia Marquez - Available
The Brothers Karamazov by Fyodor Dostoevsky - Available
Don Quixote by Miguel de Cervantes - Available
Wuthering Heights by Emily Bronte - Available
A Tale of Two Cities by Charles Dickens - Available

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 2
Available books to borrow:
Library books:
The Great Gatsby by F. Scott Fitzgerald - Available
1984 by George Orwell - Available
To Kill a Mockingbird by Harper Lee - Available
Moby Dick by Herman Melville - Available
Pride and Prejudice by Jane Austen - Available
War and Peace by Leo Tolstoy - Available
The Catcher in the Rye by J.D. Salinger - Available
The Hobbit by J.R.R. Tolkien - Available
Crime and Punishment by Fyodor Dostoevsky - Available
The Odyssey by Homer - Available
Jane Eyre by Charlotte Bronte - Available
Brave New World by Aldous Huxley - Available
The Lord of the Rings by J.R.R. Tolkien - Available
Animal Farm by George Orwell - Available
Les Mis├⌐rables by Victor Hugo - Available
The Divine Comedy by Dante Alighieri - Available
Ulysses by James Joyce - Available
One Hundred Years of Solitude by Gabriel Garcia Marquez - Available
The Brothers Karamazov by Fyodor Dostoevsky - Available
Don Quixote by Miguel de Cervantes - Available
Wuthering Heights by Emily Bronte - Available
A Tale of Two Cities by Charles Dickens - Available
Enter the title of the book you want to borrow: 1984
Abdelrahman borrowed "1984".

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 3
Borrowing/Returning History:
Abdelrahman borrowed "1984"

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 4
Books you have borrowed:
- 1984
Enter the title of the book you want to return: 1984
Abdelrahman returned "1984".

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 3
Borrowing/Returning History:
Abdelrahman borrowed "1984"
Abdelrahman returned "1984"

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 5
Library Members:
Member: Abdelrahman, ID: 1234

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 6
Signing out Abdelrahman...
1. Sign In
2. Sign Up
Enter your choice: 2
Enter your name: Ahmed
Enter a membership ID: 1234
ID is taken!
Enter a membership ID again: 1342
ID 1342 is available.
Enter your contact information: 0102
Member "Ahmed" registered.

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 2
Available books to borrow:
Library books:
The Great Gatsby by F. Scott Fitzgerald - Available
1984 by George Orwell - Available
To Kill a Mockingbird by Harper Lee - Available
Moby Dick by Herman Melville - Available
Pride and Prejudice by Jane Austen - Available
War and Peace by Leo Tolstoy - Available
The Catcher in the Rye by J.D. Salinger - Available
The Hobbit by J.R.R. Tolkien - Available
Crime and Punishment by Fyodor Dostoevsky - Available
The Odyssey by Homer - Available
Jane Eyre by Charlotte Bronte - Available
Brave New World by Aldous Huxley - Available
The Lord of the Rings by J.R.R. Tolkien - Available
Animal Farm by George Orwell - Available
Les Mis├⌐rables by Victor Hugo - Available
The Divine Comedy by Dante Alighieri - Available
Ulysses by James Joyce - Available
One Hundred Years of Solitude by Gabriel Garcia Marquez - Available
The Brothers Karamazov by Fyodor Dostoevsky - Available
Don Quixote by Miguel de Cervantes - Available
Wuthering Heights by Emily Bronte - Available
A Tale of Two Cities by Charles Dickens - Available
Enter the title of the book you want to borrow: The Great Gatsby
Ahmed borrowed "The Great Gatsby".

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 6
Signing out Ahmed...
1. Sign In
2. Sign Up
Enter your choice: 1
Enter your membership ID to sign in: 1234
Welcome back, Abdelrahman!

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 1
Library books:
The Great Gatsby by F. Scott Fitzgerald - Checked Out
1984 by George Orwell - Available
To Kill a Mockingbird by Harper Lee - Available
Moby Dick by Herman Melville - Available
Pride and Prejudice by Jane Austen - Available
War and Peace by Leo Tolstoy - Available
The Catcher in the Rye by J.D. Salinger - Available
The Hobbit by J.R.R. Tolkien - Available
Crime and Punishment by Fyodor Dostoevsky - Available
The Odyssey by Homer - Available
Jane Eyre by Charlotte Bronte - Available
Brave New World by Aldous Huxley - Available
The Lord of the Rings by J.R.R. Tolkien - Available
Animal Farm by George Orwell - Available
Les Mis├⌐rables by Victor Hugo - Available
The Divine Comedy by Dante Alighieri - Available
Ulysses by James Joyce - Available
One Hundred Years of Solitude by Gabriel Garcia Marquez - Available
The Brothers Karamazov by Fyodor Dostoevsky - Available
Don Quixote by Miguel de Cervantes - Available
Wuthering Heights by Emily Bronte - Available
A Tale of Two Cities by Charles Dickens - Available

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 2
Available books to borrow:
Library books:
The Great Gatsby by F. Scott Fitzgerald - Checked Out
1984 by George Orwell - Available
To Kill a Mockingbird by Harper Lee - Available
Moby Dick by Herman Melville - Available
Pride and Prejudice by Jane Austen - Available
War and Peace by Leo Tolstoy - Available
The Catcher in the Rye by J.D. Salinger - Available
The Hobbit by J.R.R. Tolkien - Available
Crime and Punishment by Fyodor Dostoevsky - Available
The Odyssey by Homer - Available
Jane Eyre by Charlotte Bronte - Available
Brave New World by Aldous Huxley - Available
The Lord of the Rings by J.R.R. Tolkien - Available
Animal Farm by George Orwell - Available
Les Mis├⌐rables by Victor Hugo - Available
The Divine Comedy by Dante Alighieri - Available
Ulysses by James Joyce - Available
One Hundred Years of Solitude by Gabriel Garcia Marquez - Available
The Brothers Karamazov by Fyodor Dostoevsky - Available
Don Quixote by Miguel de Cervantes - Available
Wuthering Heights by Emily Bronte - Available
A Tale of Two Cities by Charles Dickens - Available
Enter the title of the book you want to borrow: 1984
Abdelrahman borrowed "1984".

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 3
Borrowing/Returning History:
Abdelrahman borrowed "1984"
Abdelrahman returned "1984"
Ahmed borrowed "The Great Gatsby"
Abdelrahman borrowed "1984"

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 5
Library Members:
Member: Abdelrahman, ID: 1234
Member: Ahmed, ID: 1342

Choose an option:
1. Show Available Books
2. Borrow a Book
3. Show Borrowed/Returned Books
4. Return a Book
5. View Library Members
6. Sign Out
7. Exit
Enter your choice: 7
Goodbye!

```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions, feel free to contact me:
- **Phone:** +201028325749
- **Email:** a.mohamed822000@gmail.com
- **LinkedIn:** [Abdelrahman Mohamed Hamad](https://www.linkedin.com/in/abdelrahman-mohamed-a1956b247/)