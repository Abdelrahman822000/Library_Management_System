#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "includes.h"

// Class to track transactions in the library system
class Transaction
{
public:
    std::string memberName;   // Name of the member involved in the transaction
    std::string bookTitle;    // Title of the book involved in the transaction
    std::string action;       // Action taken: "Borrowed" or "Returned"

    // Constructor to initialize a Transaction object with member name, book title, and action
    Transaction(std::string name, std::string title, std::string Action);
};

#endif