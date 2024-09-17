#ifndef BOOK_H
#define BOOK_H

// Include the necessary standard libraries and headers
#include "includes.h"

// Class to represent a Book in the library
class Book
{
public:
    // Member variables to store book details
    std::string title;               // Title of the book
    std::string author;              // Author of the book
    std::string publicationDate;     // Publication date of the book
    bool isAvailable;                // Availability status of the book

    // Constructor to initialize a Book object with given details
    Book(std::string t, std::string a, std::string pd);

    // Member function to display book information
    void displayInfo();
};

#endif // BOOK_H