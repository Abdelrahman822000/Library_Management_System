#include "Member.h"

// Constructor to initialize a Member object with given details
Member::Member(std::string n, std::string id, std::string contact)
    : name(n), membershipID(id), contactInfo(contact) {}

// Destructor to clean up any resources held by the Member
// In this case, we clear the list of borrowed books, but we do not delete them,
// as the library manages the lifecycle of the Book objects.
Member::~Member()
{
    borrowedBooks.clear(); // Clear the list of borrowed books
}

// Function to borrow a book from the library
void Member::borrowBook(Book *book)
{
    // Check if the book is available
    if (book->isAvailable)
    {
        // Add the book to the list of borrowed books
        borrowedBooks.push_back(book);
        // Mark the book as unavailable
        book->isAvailable = false;
        std::cout << name << " borrowed \"" << book->title << "\"." << std::endl;
    }
    else
    {
        std::cout << "The book \"" << book->title << "\" is currently unavailable." << std::endl;
    }
}

// Function to return a borrowed book to the library
void Member::returnBook(Book *book)
{
    // Find the book in the list of borrowed books
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end())
    {
        // Remove the book from the list of borrowed books
        borrowedBooks.erase(it);
        // Mark the book as available
        book->isAvailable = true;
        std::cout << name << " returned \"" << book->title << "\"." << std::endl;
    }
    else
    {
        std::cout << "This book was not borrowed by " << name << "." << std::endl;
    }
}

// Function to display a list of books borrowed by the member
bool Member::displayBorrowedBooks()
{
    // Check if the member has any borrowed books
    if (borrowedBooks.empty())
    {
        std::cout << name << " has no borrowed books." << std::endl;
        return false;
    }
    // Display the list of borrowed books
    std::cout << "Books you have borrowed:" << std::endl;
    for (Book *book : borrowedBooks)
    {
        std::cout << "- " << book->title << std::endl;
    }
    return true;
}