#include "Transaction.h"

// Constructor to initialize a Transaction object
Transaction::Transaction(std::string name, std::string title, std::string Action)
    : memberName(name), bookTitle(title), action(Action) {}
