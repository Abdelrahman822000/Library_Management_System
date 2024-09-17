#ifndef LIBRARY_H
#define LIBRARY_H

#include "includes.h"
#include "Book.h"
#include "Member.h"
#include "Transaction.h"

// Class to represent the Library system
class Library
{
public:
    std::vector<Book *> books;              // List of all books in the library
    std::vector<Member *> members;          // List of all library members
    std::vector<Transaction> transactions;  // Record of all transactions (borrow/return)
    std::unordered_map<std::string, Book *> bookLookup; // Mapping of book titles to Book pointers

    ~Library(); // Destructor to clean up dynamically allocated resources

    // Add a new book to the library
    void addBook(Book *book);

    // Register a new member in the library
    void registerMember(Member *member);

    // Handle the borrowing of a book by a member
    void borrowBook(Book *book, Member *member);

    // Handle the return of a book by a member
    void returnBook(Book *book, Member *member);

    // Display all books available in the library
    void displayBooks();

    // Find a member by their membership ID
    Member *findMember(std::string membershipID);

    // Find a book by its title
    Book *findBookByTitle(std::string title);

    // Display the list of all transactions
    void displayTransactions();

    // Display the list of all registered members
    void displayMembers();
};

#endif