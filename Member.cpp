#include "Member.h"

Member::Member(std::string n, std::string id, std::string contact)
    : name(n), membershipID(id), contactInfo(contact) {}

Member::~Member()
{
    borrowedBooks.clear(); // No need to delete borrowed books; Library manages them.
}
void Member::borrowBook(Book *book)
{
    if (book->isAvailable)
    {
        borrowedBooks.push_back(book);
        book->isAvailable = false;
        std::cout << name << " borrowed \"" << book->title << "\"." << std::endl;
    }
    else
    {
        std::cout << "The book \"" << book->title << "\" is currently unavailable." << std::endl;
    }
}

void Member::returnBook(Book *book)
{
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end())
    {
        borrowedBooks.erase(it);
        book->isAvailable = true;
        std::cout << name << " returned \"" << book->title << "\"." << std::endl;
    }
    else
    {
        std::cout << "This book was not borrowed by " << name << "." << std::endl;
    }
}

bool Member::displayBorrowedBooks()
{
    if (borrowedBooks.empty())
    {
        std::cout << name << " has no borrowed books." << std::endl;
        return false;
    }
    std::cout << "Books you have borrowed:" << std::endl;
    for (Book *book : borrowedBooks)
    {
        std::cout << "- " << book->title << std::endl;
    }
    return true;
}