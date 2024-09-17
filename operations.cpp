#include "operations.h" // Include the header file for operation-related declarations

// Function to handle user operations, providing a menu for various game-related actions.
void Operations()
{
    Library myLibrary;

    // Pre-defined books for the library
    Book *book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "1925");
    Book *book2 = new Book("1984", "George Orwell", "1949");
    Book *book3 = new Book("To Kill a Mockingbird", "Harper Lee", "1960");
    Book *book4 = new Book("Moby Dick", "Herman Melville", "1851");
    Book *book5 = new Book("Pride and Prejudice", "Jane Austen", "1813");
    Book *book6 = new Book("War and Peace", "Leo Tolstoy", "1869");
    Book *book7 = new Book("The Catcher in the Rye", "J.D. Salinger", "1951");
    Book *book8 = new Book("The Hobbit", "J.R.R. Tolkien", "1937");
    Book *book9 = new Book("Crime and Punishment", "Fyodor Dostoevsky", "1866");
    Book *book10 = new Book("The Odyssey", "Homer", "8th Century BC");
    Book *book11 = new Book("Jane Eyre", "Charlotte Bronte", "1847");
    Book *book12 = new Book("Brave New World", "Aldous Huxley", "1932");
    Book *book13 = new Book("The Lord of the Rings", "J.R.R. Tolkien", "1954");
    Book *book14 = new Book("Animal Farm", "George Orwell", "1945");
    Book *book15 = new Book("Les Misérables", "Victor Hugo", "1862");
    Book *book16 = new Book("The Divine Comedy", "Dante Alighieri", "1320");
    Book *book17 = new Book("Ulysses", "James Joyce", "1922");
    Book *book18 = new Book("One Hundred Years of Solitude", "Gabriel Garcia Marquez", "1967");
    Book *book19 = new Book("The Brothers Karamazov", "Fyodor Dostoevsky", "1880");
    Book *book20 = new Book("Don Quixote", "Miguel de Cervantes", "1605");
    Book *book21 = new Book("Wuthering Heights", "Emily Bronte", "1847");
    Book *book22 = new Book("A Tale of Two Cities", "Charles Dickens", "1859");

    // Adding books to the library
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);
    myLibrary.addBook(book4);
    myLibrary.addBook(book5);
    myLibrary.addBook(book6);
    myLibrary.addBook(book7);
    myLibrary.addBook(book8);
    myLibrary.addBook(book9);
    myLibrary.addBook(book10);
    myLibrary.addBook(book11);
    myLibrary.addBook(book12);
    myLibrary.addBook(book13);
    myLibrary.addBook(book14);
    myLibrary.addBook(book15);
    myLibrary.addBook(book16);
    myLibrary.addBook(book17);
    myLibrary.addBook(book18);
    myLibrary.addBook(book19);
    myLibrary.addBook(book20);
    myLibrary.addBook(book21);
    myLibrary.addBook(book22);

    Member *currentMember = nullptr;

    // User chooses to sign in or sign up
    currentMember = loginMenu(myLibrary);

    int choice = 0;

    while (choice != 7)
    {
        do
        {
            showMenu();
            cin >> choice;
            cin.ignore(); // Ignore leftover newline character in input buffer

            switch (choice)
            {
            case 1: // Show all books in the library
                myLibrary.displayBooks();
                break;
            case 2:
            { // Borrow a book
                cout << "Available books to borrow:" << endl;
                myLibrary.displayBooks(); // Display all books
                string bookTitle;
                cout << "Enter the title of the book you want to borrow: ";
                getline(cin, bookTitle);
                Book *bookToBorrow = myLibrary.findBookByTitle(bookTitle);
                if (bookToBorrow && bookToBorrow->isAvailable)
                {
                    myLibrary.borrowBook(bookToBorrow, currentMember);
                }
                else
                {
                    cout << "Book not available or not found." << endl;
                }
                break;
            }
            case 3: // Show Borrowed/Returned Books
                myLibrary.displayTransactions();
                break;
            case 4:
            {                                                          // Return a book
                bool hasBooks = currentMember->displayBorrowedBooks(); // Display borrowed books
                string bookTitle;
                if (hasBooks)
                {
                    cout << "Enter the title of the book you want to return: ";
                    getline(cin, bookTitle);
                    Book *bookToReturn = myLibrary.findBookByTitle(bookTitle);
                    if (bookToReturn && !bookToReturn->isAvailable)
                    {
                        myLibrary.returnBook(bookToReturn, currentMember);
                    }
                    else
                    {
                        cout << "Book not found or not borrowed." << endl;
                    }
                }
                break;
            }
            case 5: // View Library Members
                myLibrary.displayMembers();
                break;
            case 6: // Sign out
                cout << "Signing out " << currentMember->name << "..." << endl;
                currentMember = loginMenu(myLibrary);
                break;
            case 7: // Exit
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 6 && choice != 7);
    }
}