#include "Library.h"

// Destructor for Library class
// Deletes dynamically allocated Book and Member objects
Library::~Library()
{
    // Delete all books in the library
    for (auto book : books)
    {
        delete book;
    }
    // Delete all members of the library
    for (auto member : members)
    {
        delete member;
    }
}

// Add a new book to the library
void Library::addBook(Book *book)
{
    books.push_back(book);                     // Add book to the list of books
    bookLookup[book->title] = book;            // Add book to the lookup map using title as key
    std::cout << "Book \"" << book->title << "\" added to the library." << std::endl;
}

// Register a new member in the library
void Library::registerMember(Member *member)
{
    members.push_back(member);                 // Add member to the list of members
    std::cout << "Member \"" << member->name << "\" registered." << std::endl;
}

// Process the borrowing of a book by a member
void Library::borrowBook(Book *book, Member *member)
{
    member->borrowBook(book);                  // Call member's borrowBook method
    transactions.emplace_back(member->name, book->title, "borrowed"); // Record the transaction
}

// Process the return of a book by a member
void Library::returnBook(Book *book, Member *member)
{
    member->returnBook(book);                  // Call member's returnBook method
    transactions.emplace_back(member->name, book->title, "returned"); // Record the transaction
}

// Display all books in the library
void Library::displayBooks()
{
    if (books.empty())
    {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    std::cout << "Library books:" << std::endl;
    for (Book *book : books)
    {
        std::cout << book->title << " by " << book->author
                  << " - "
                  << (book->isAvailable ? "Available" : "Checked Out") << std::endl;
    }
}

// Find a member by their membership ID
Member *Library::findMember(std::string membershipID)
{
    for (Member *member : members)
    {
        if (member->membershipID == membershipID)
        {
            return member; // Return the member if found
        }
    }
    return nullptr; // Return nullptr if member not found
}

// Find a book by its title
Book *Library::findBookByTitle(std::string title)
{
    auto it = bookLookup.find(title);
    return (it != bookLookup.end()) ? it->second : nullptr; // Return the book if found
}

// Display all recorded transactions
void Library::displayTransactions()
{
    if (transactions.empty())
    {
        std::cout << "No transactions recorded." << std::endl;
        return;
    }

    std::cout << "Borrowing/Returning History:" << std::endl;
    for (const Transaction &t : transactions)
    {
        std::cout << t.memberName << " " << t.action << " \"" << t.bookTitle << "\"" << std::endl;
    }
}

// Display all registered members
void Library::displayMembers()
{
    if (members.empty())
    {
        std::cout << "No members registered in the library." << std::endl;
        return;
    }
    std::cout << "Library Members:" << std::endl;
    for (Member *member : members)
    {
        std::cout << "Member: " << member->name << ", ID: " << member->membershipID << std::endl;
    }
}