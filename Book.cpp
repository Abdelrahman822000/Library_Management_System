#include "Book.h"

// Constructor to initialize a Book object with given details
Book::Book(std::string t, std::string a, std::string pd)
    : title(t), author(a), publicationDate(pd), isAvailable(true) 
{
    // Initialize member variables with provided values
    // `title` is set to `t`
    // `author` is set to `a`
    // `publicationDate` is set to `pd`
    // `isAvailable` is set to `true` by default
}

// Member function to display the book's information
void Book::displayInfo()
{
    // Output the title of the book
    std::cout << "Title: " << title << std::endl;
    // Output the author of the book
    std::cout << "Author: " << author << std::endl;
    // Output the publication date of the book
    std::cout << "Publication Date: " << publicationDate << std::endl;
    // Output the availability status of the book
    std::cout << "Status: " << (isAvailable ? "Available" : "Checked Out") << std::endl;
}