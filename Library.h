#ifndef LIBRARY_H
#define LIBRARY_H

#include "includes.h"
#include "Book.h"
#include "Member.h"
#include "Transaction.h"

// Class to represent the Library
class Library
{
public:
    std::vector<Book *> books;
    std::vector<Member *> members;
    std::vector<Transaction> transactions;
    std::unordered_map<std::string, Book *> bookLookup; // Mapping book titles to books

    ~Library();

    void addBook(Book *book);

    void registerMember(Member *member);

    void borrowBook(Book *book, Member *member);

    void returnBook(Book *book, Member *member);

    void displayBooks();

    Member *findMember(std::string membershipID);

    Book *findBookByTitle(std::string title);

    void displayTransactions();

    void displayMembers();
};

#endif