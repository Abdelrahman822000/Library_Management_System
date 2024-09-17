#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Class to represent a Book
class Book
{
public:
    string title;
    string author;
    string publicationDate;
    bool isAvailable;

    Book(string t, string a, string i, string pd)
        : title(t), author(a), publicationDate(pd), isAvailable(true) {}

    void displayInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Checked Out") << endl;
    }
};

// Class to represent a Member
class Member
{
public:
    string name;
    string membershipID;
    string contactInfo;
    vector<Book *> borrowedBooks;

    Member(string n, string id, string contact)
        : name(n), membershipID(id), contactInfo(contact) {}

    ~Member()
    {
        borrowedBooks.clear(); // No need to delete borrowed books; Library manages them.
    }
    void borrowBook(Book *book)
    {
        if (book->isAvailable)
        {
            borrowedBooks.push_back(book);
            book->isAvailable = false;
            cout << name << " borrowed \"" << book->title << "\"." << endl;
        }
        else
        {
            cout << "The book \"" << book->title << "\" is currently unavailable." << endl;
        }
    }

    void returnBook(Book *book)
    {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end())
        {
            borrowedBooks.erase(it);
            book->isAvailable = true;
            cout << name << " returned \"" << book->title << "\"." << endl;
        }
        else
        {
            cout << "This book was not borrowed by " << name << "." << endl;
        }
    }

    bool displayBorrowedBooks()
    {
        if (borrowedBooks.empty())
        {
            cout << name << " has no borrowed books." << endl;
            return false;
        }
        cout << "Books you have borrowed:" << endl;
        for (Book *book : borrowedBooks)
        {
            cout << "- " << book->title << endl;
        }
        return true;
    }
};

// Class to track transactions
class Transaction
{
public:
    string memberName;
    string bookTitle;
    string action; // Borrowed or Returned

    Transaction(string m, string b, string a) : memberName(m), bookTitle(b), action(a) {}
};

// Class to represent the Library
class Library
{
public:
    vector<Book *> books;
    vector<Member *> members;
    vector<Transaction> transactions;
    unordered_map<string, Book *> bookLookup; // Mapping book titles to books

    ~Library()
    {
        for (auto book : books)
        {
            delete book;
        }
        for (auto member : members)
        {
            delete member;
        }
    }

    void addBook(Book *book)
    {
        books.push_back(book);
        bookLookup[book->title] = book;
        cout << "Book \"" << book->title << "\" added to the library." << endl;
    }

    void registerMember(Member *member)
    {
        members.push_back(member);
        cout << "Member \"" << member->name << "\" registered." << endl;
    }

    void borrowBook(Book *book, Member *member)
    {
        member->borrowBook(book);
        transactions.emplace_back(member->name, book->title, "borrowed");
    }

    void returnBook(Book *book, Member *member)
    {
        member->returnBook(book);
        transactions.emplace_back(member->name, book->title, "returned");
    }

    void displayBooks()
    {
        if (books.empty())
        {
            cout << "No books in the library." << endl;
            return;
        }
        cout << "Library books:" << endl;
        for (Book *book : books)
        {
            cout << book->title << " by " << book->author
                 << " - "
                 << (book->isAvailable ? "Available" : "Checked Out") << endl;
        }
    }

    Member *findMember(string membershipID)
    {
        for (Member *member : members)
        {
            if (member->membershipID == membershipID)
            {
                return member;
            }
        }
        return nullptr;
    }

    Book *findBookByTitle(string title)
    {
        auto it = bookLookup.find(title);
        return (it != bookLookup.end()) ? it->second : nullptr;
    }

    void displayTransactions()
    {
        if (transactions.empty())
        {
            cout << "No transactions recorded." << endl;
            return;
        }

        cout << "Borrowing/Returning History:" << endl;
        for (const Transaction &t : transactions)
        {
            cout << t.memberName << " " << t.action << " \"" << t.bookTitle << "\"" << endl;
        }
    }

    void displayMembers()
    {
        if (members.empty())
        {
            cout << "No members registered in the library." << endl;
            return;
        }
        cout << "Library Members:" << endl;
        for (Member *member : members)
        {
            cout << "Member: " << member->name << ", ID: " << member->membershipID << endl;
        }
    }
};

// Function to display the menu options
void showMenu()
{
    cout << endl
         << "Choose an option:" << endl;
    cout << "1. Show Available Books" << endl;
    cout << "2. Borrow a Book" << endl;
    cout << "3. Show Borrowed/Returned Books" << endl;
    cout << "4. Return a Book" << endl;
    cout << "5. View Library Members" << endl;
    cout << "6. Sign Out" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

bool checkID(Library &library, string membershipID)
{
    Member *member = library.findMember(membershipID);

    if (member)
    {
        cout << "ID is taken!" << endl;
        return false;
    }
    else
    {
        cout << "ID " << membershipID << " is available." << endl;
        return true;
    }
}

// Function to register a new member
Member *signUp(Library &library)
{
    string name, membershipID, contactInfo;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter a membership ID: ";
    getline(cin, membershipID);
    while (true)
    {
        bool idAvailable = checkID(library, membershipID);
        if (idAvailable)
        {
            break;
        }
        else
        {
            cout << "Enter a membership ID again: ";
            getline(cin, membershipID);
        }
    }
    cout << "Enter your contact information: ";
    getline(cin, contactInfo);

    Member *newMember = new Member(name, membershipID, contactInfo);
    library.registerMember(newMember);
    return newMember;
}

// Function to sign in an existing user
Member *signIn(Library &library)
{
    string membershipID;
    cout << "Enter your membership ID to sign in: ";
    getline(cin, membershipID);

    Member *member = library.findMember(membershipID);

    if (member)
    {
        cout << "Welcome back, " << member->name << "!" << endl;
        return member;
    }
    else
    {
        cout << "No member found with ID " << membershipID << "." << endl;
        return nullptr;
    }
}

// Function to handle user login/signup
Member *loginMenu(Library &library)
{
    int choice;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    if (choice == 1)
    {
        Member *member = signIn(library);
        if (member != nullptr)
        {
            return member;
        }
        cout << "Please sign up if you don't have an account." << endl;
        return loginMenu(library); // Retry login/signup
    }
    else if (choice == 2)
    {
        return signUp(library);
    }
    else
    {
        cout << "Invalid choice. Please try again." << endl;
        return loginMenu(library); // Retry login/signup
    }
}

int main()
{
    Library myLibrary;

    // Pre-defined books for the library
    Book *book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "123456789", "1925");
    Book *book2 = new Book("1984", "George Orwell", "987654321", "1949");
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);

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

    return 0;
}