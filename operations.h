#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "includes.h"
#include "Library.h"

// Declaration of the operations function that handles the main program's logic
void Operations();
// Function to display the menu options
void showMenu();

bool checkID(Library &library, std::string membershipID);

// Function to register a new member
Member *signUp(Library &library);

// Function to sign in an existing user
Member *signIn(Library &library);
// Function to handle user login/signup
Member *loginMenu(Library &library);

#endif