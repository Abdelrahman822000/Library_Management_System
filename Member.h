#ifndef MEMBER_H
#define MEMBER_H


#include "includes.h"
#include "Book.h"

// Class to represent a Member
class Member
{
public:
    std::string name;
    std::string membershipID;
    std::string contactInfo;
    std::vector<Book *> borrowedBooks;

    Member(std::string n, std::string id, std::string contact);

    ~Member();
    void borrowBook(Book *book);

    void returnBook(Book *book);

    bool displayBorrowedBooks();
};

#endif