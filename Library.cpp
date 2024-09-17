#include "Library.h"

Library::~Library()
{
    for (auto book : books)
    {
        delete book;
    }
    for (auto member : members)
    {
        delete member;
    }
}

void Library::addBook(Book *book)
{
    books.push_back(book);
    bookLookup[book->title] = book;
    std::cout << "Book \"" << book->title << "\" added to the library." << std::endl;
}

void Library::registerMember(Member *member)
{
    members.push_back(member);
    std::cout << "Member \"" << member->name << "\" registered." << std::endl;
}

void Library::borrowBook(Book *book, Member *member)
{
    member->borrowBook(book);
    transactions.emplace_back(member->name, book->title, "borrowed");
}

void Library::returnBook(Book *book, Member *member)
{
    member->returnBook(book);
    transactions.emplace_back(member->name, book->title, "returned");
}

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

Member *Library::findMember(std::string membershipID)
{
    for (Member *member : members)
    {
        if (member->membershipID == membershipID)
        {
            return member;
        }
    }
    return nullptr;
}

Book *Library::findBookByTitle(std::string title)
{
    auto it = bookLookup.find(title);
    return (it != bookLookup.end()) ? it->second : nullptr;
}

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
