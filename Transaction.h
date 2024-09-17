#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "includes.h"

// Class to track transactions
class Transaction
{
public:
    std::string memberName;
    std::string bookTitle;
    std::string action; // Borrowed or Returned

    Transaction(std::string name, std::string title, std::string Action);
};

#endif