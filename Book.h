#ifndef BOOK_H
#define BOOK_H

#include "includes.h"

// Class to represent a Book
class Book
{
public:
    std::string title;
    std::string author;
    std::string publicationDate;
    bool isAvailable;

    Book(std::string t, std::string a, std::string i, std::string pd);

    void displayInfo();
};

#endif