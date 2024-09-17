#include "operations.h" // Include the header file for operation-related declarations

// Function to handle user operations, providing a menu for various library-related actions.
void Operations()
{
    // Create a Library instance
    Library myLibrary;

    // Pre-defined books for the library
    // Books are dynamically allocated and initialized with title, author, and publication date
    std::string titles[] = {
        "The Great Gatsby", "1984", "To Kill a Mockingbird", "Moby Dick",
        "Pride and Prejudice", "War and Peace", "The Catcher in the Rye", "The Hobbit",
        "Crime and Punishment", "The Odyssey", "Jane Eyre", "Brave New World",
        "The Lord of the Rings", "Animal Farm", "Les Misérables", "The Divine Comedy",
        "Ulysses", "One Hundred Years of Solitude", "The Brothers Karamazov",
        "Don Quixote", "Wuthering Heights", "A Tale of Two Cities"
    };

    std::string authors[] = {
        "F. Scott Fitzgerald", "George Orwell", "Harper Lee", "Herman Melville",
        "Jane Austen", "Leo Tolstoy", "J.D. Salinger", "J.R.R. Tolkien",
        "Fyodor Dostoevsky", "Homer", "Charlotte Bronte", "Aldous Huxley",
        "J.R.R. Tolkien", "George Orwell", "Victor Hugo", "Dante Alighieri",
        "James Joyce", "Gabriel Garcia Marquez", "Fyodor Dostoevsky",
        "Miguel de Cervantes", "Emily Bronte", "Charles Dickens"
    };

    std::string publicationDates[] = {
        "1925", "1949", "1960", "1851", "1813", "1869", "1951", "1937",
        "1866", "8th Century BC", "1847", "1932", "1954", "1945", "1862",
        "1320", "1922", "1967", "1880", "1605", "1847", "1859"
    };

    // Adding pre-defined books to the library
    for (size_t i = 0; i < 22; ++i) {
        Book* book = new Book(titles[i], authors[i], publicationDates[i]);
        myLibrary.addBook(book);
    }

    Member* currentMember = nullptr; // Pointer to keep track of the current logged-in member

    // User chooses to sign in or sign up
    currentMember = loginMenu(myLibrary);

    int choice = 0;

    // Main loop to handle user choices
    while (choice != 7) // Continue until the user chooses to exit (choice 7)
    {
        do
        {
            showMenu(); // Display menu options
            std::cin >> choice; // Get user input
            std::cin.ignore(); // Ignore leftover newline character in input buffer

            switch (choice)
            {
            case 1: // Show all books in the library
                myLibrary.displayBooks();
                break;
            case 2:
            { // Borrow a book
                std::cout << "Available books to borrow:" << std::endl;
                myLibrary.displayBooks(); // Display all books
                std::string bookTitle;
                std::cout << "Enter the title of the book you want to borrow: ";
                std::getline(std::cin, bookTitle); // Get book title from user
                Book* bookToBorrow = myLibrary.findBookByTitle(bookTitle); // Find the book by title
                if (bookToBorrow && bookToBorrow->isAvailable) // Check if the book is available
                {
                    myLibrary.borrowBook(bookToBorrow, currentMember); // Borrow the book
                }
                else
                {
                    std::cout << "Book not available or not found." << std::endl;
                }
                break;
            }
            case 3: // Show Borrowed/Returned Books
                myLibrary.displayTransactions();
                break;
            case 4:
            { // Return a book
                bool hasBooks = currentMember->displayBorrowedBooks(); // Display borrowed books
                std::string bookTitle;
                if (hasBooks)
                {
                    std::cout << "Enter the title of the book you want to return: ";
                    std::getline(std::cin, bookTitle); // Get book title from user
                    Book* bookToReturn = myLibrary.findBookByTitle(bookTitle); // Find the book by title
                    if (bookToReturn && !bookToReturn->isAvailable) // Check if the book is not available
                    {
                        myLibrary.returnBook(bookToReturn, currentMember); // Return the book
                    }
                    else
                    {
                        std::cout << "Book not found or not borrowed." << std::endl;
                    }
                }
                break;
            }
            case 5: // View Library Members
                myLibrary.displayMembers();
                break;
            case 6: // Sign out
                std::cout << "Signing out " << currentMember->name << "..." << std::endl;
                currentMember = loginMenu(myLibrary); // Show login menu again
                break;
            case 7: // Exit
                std::cout << "Goodbye!" << std::endl;
                break;
            default: // Handle invalid choices
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 6 && choice != 7); // Repeat until the user chooses to sign out or exit
    }
}
