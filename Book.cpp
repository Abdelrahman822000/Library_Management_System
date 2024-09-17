#include "Book.h"

Book::Book(std::string t, std::string a, std::string i, std::string pd)
    : title(t), author(a), publicationDate(pd), isAvailable(true) {}

void Book::displayInfo()
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Publication Date: " << publicationDate << std::endl;
    std::cout << "Status: " << (isAvailable ? "Available" : "Checked Out") << std::endl;
}