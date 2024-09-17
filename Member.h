#ifndef MEMBER_H
#define MEMBER_H

// Include necessary standard libraries and other headers
#include "includes.h"
#include "Book.h"

// Class to represent a Library Member
class Member
{
public:
    // Member's name
    std::string name;
    // Unique membership ID for the member
    std::string membershipID;
    // Contact information for the member
    std::string contactInfo;
    // List of books currently borrowed by the member
    std::vector<Book *> borrowedBooks;

    // Constructor to initialize a Member object with given details
    Member(std::string n, std::string id, std::string contact);

    // Destructor to clean up any resources held by the Member
    ~Member();

    // Function to borrow a book from the library
    void borrowBook(Book *book);

    // Function to return a borrowed book to the library
    void returnBook(Book *book);

    // Function to display a list of books borrowed by the member
    bool displayBorrowedBooks();
};

#endif