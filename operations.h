#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "includes.h"
#include "Library.h"

// Function to handle the main logic of the program
void Operations();

// Function to display menu options to the user
void showMenu();

// Function to check if a membership ID exists in the library
// Returns true if the ID is valid, false otherwise
bool checkID(Library &library, std::string membershipID);

// Function to register a new member and return the member object
Member *signUp(Library &library);

// Function to sign in an existing user and return the member object
Member *signIn(Library &library);

// Function to handle user login or signup process
// Displays the appropriate menu and returns the logged-in or signed-up member
Member *loginMenu(Library &library);

#endif