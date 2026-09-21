#include <iostream>
using namespace std;

// Abstract Base Class

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    // Constructor
    LibraryItem()
    {
        this->title = "";
        this->author = "";
        this->dueDate = "";
    }

    LibraryItem(string title, string author)
    {
        this->title = title;
        this->author = author;
        this->dueDate = "";
    }

    // Destructor
    virtual ~LibraryItem()
    {
    }

    // Getters
    string getTitle()
    {
        return this->title;
    }

    string getAuthor()
    {
        return this->author;
    }

    string getDueDate()
    {
        return this->dueDate;
    }

    // Setters
    void setTitle(string title)
    {
        this->title = title;
    }

    void setAuthor(string author)
    {
        this->author = author;
    }

    void setDueDate(string dueDate)
    {
        this->dueDate = dueDate;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;

    virtual void returnItem() = 0;

    virtual void displayDetails() = 0;
};

// Book

class Book : public LibraryItem
{
private:
    string ISBN;
    int quantity;
    bool checkedOut;

public:
    // Constructor
    Book(
        string title,
        string author,
        string isbn,
        int quantity)
        : LibraryItem(title, author)
    {
        if (quantity < 0)
        {
            throw "Quantity cannot be negative!";
        }

        if (isbn.length() != 10 &&
            isbn.length() != 13)
        {
            throw "Invalid ISBN!";
        }

        this->ISBN = isbn;
        this->quantity = quantity;
        this->checkedOut = false;
    }

    // Destructor
    ~Book()
    {
    }

    // Check Out
    void checkOut() override
    {
        if (this->checkedOut)
        {
            cout << "Book is already checked out!"
                 << endl;

            return;
        }

        if (this->quantity <= 0)
        {
            throw "No copy available!";
        }

        this->quantity--;

        this->checkedOut = true;

        setDueDate("30 Days");

        cout << "Book Checked Out Successfully!"
             << endl;
    }

    // Return
    void returnItem() override
    {
        if (!this->checkedOut)
        {
            cout << "Book is not checked out!"
                 << endl;

            return;
        }

        this->quantity++;

        this->checkedOut = false;

        setDueDate("");

        cout << "Book Returned Successfully!"
             << endl;
    }

    // Display
    void displayDetails() override
    {
        cout << endl;
        cout << "----- BOOK DETAILS -----" << endl;

        cout << "Title : "
             << getTitle() << endl;

        cout << "Author : "
             << getAuthor() << endl;

        cout << "ISBN : "
             << this->ISBN << endl;

        cout << "Quantity : "
             << this->quantity << endl;

        cout << "Status : "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;

        if (!getDueDate().empty())
        {
            cout << "Due Date : "
                 << getDueDate() << endl;
        }
    }
};

// DVD

class DVD : public LibraryItem
{
private:
    int duration;
    bool checkedOut;

public:
    // Constructor
    DVD(
        string title,
        string author,
        int duration)
        : LibraryItem(title, author)
    {
        if (duration <= 0)
        {
            throw "Invalid DVD Duration!";
        }

        this->duration = duration;
        this->checkedOut = false;
    }

    // Destructor
    ~DVD()
    {
    }

    // Check Out
    void checkOut() override
    {
        if (this->checkedOut)
        {
            cout << "DVD is already checked out!"
                 << endl;

            return;
        }

        this->checkedOut = true;

        setDueDate("15 Days");

        cout << "DVD Checked Out Successfully!"
             << endl;
    }

    // Return
    void returnItem() override
    {
        if (!this->checkedOut)
        {
            cout << "DVD is not checked out!"
                 << endl;

            return;
        }

        this->checkedOut = false;

        setDueDate("");

        cout << "DVD Returned Successfully!"
             << endl;
    }

    // Display
    void displayDetails() override
    {
        cout << endl;
        cout << "----- DVD DETAILS -----" << endl;

        cout << "Title : "
             << getTitle() << endl;

        cout << "Director : "
             << getAuthor() << endl;

        cout << "Duration : "
             << this->duration << " Minutes"
             << endl;

        cout << "Status : "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;

        if (!getDueDate().empty())
        {
            cout << "Due Date : "
                 << getDueDate() << endl;
        }
    }
};

// Magazine

class Magazine : public LibraryItem
{
private:
    int issueNumber;
    bool checkedOut;

public:
    // Constructor
    Magazine(
        string title,
        string author,
        int issueNumber)
        : LibraryItem(title, author)
    {
        if (issueNumber <= 0)
        {
            throw "Invalid Issue Number!";
        }

        this->issueNumber = issueNumber;
        this->checkedOut = false;
    }

    // Destructor
    ~Magazine()
    {
    }

    // Check Out
    void checkOut() override
    {
        if (this->checkedOut)
        {
            cout << "Magazine is already checked out!"
                 << endl;

            return;
        }

        this->checkedOut = true;

        setDueDate("7 Days");

        cout << "Magazine Checked Out Successfully!"
             << endl;
    }

    // Return
    void returnItem() override
    {
        if (!this->checkedOut)
        {
            cout << "Magazine is not checked out!"
                 << endl;

            return;
        }

        this->checkedOut = false;

        setDueDate("");

        cout << "Magazine Returned Successfully!"
             << endl;
    }

    // Display
    void displayDetails() override
    {
        cout << endl;
        cout << "----- MAGAZINE DETAILS -----"
             << endl;

        cout << "Title : "
             << getTitle() << endl;

        cout << "Publisher : "
             << getAuthor() << endl;

        cout << "Issue Number : "
             << this->issueNumber << endl;

        cout << "Status : "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;

        if (!getDueDate().empty())
        {
            cout << "Due Date : "
                 << getDueDate() << endl;
        }
    }
};

// Main

int main()
{
    LibraryItem *libraryItems[100];

    int itemCount = 0;

    bool isRunning = true;

    while (isRunning)
    {
        int input;

        cout << endl;
        cout << "====================================" << endl;
        cout << "     LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "====================================" << endl;

        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. View All Items" << endl;
        cout << "5. Search Item" << endl;
        cout << "6. Check Out Item" << endl;
        cout << "7. Return Item" << endl;
        cout << "8. Exit" << endl;

        cout << endl;
        cout << "Enter your input : ";
        cin >> input;

        try
        {
            switch (input)
            {

                // Add Book

            case 1:
            {
                string title;
                string author;
                string isbn;
                int quantity;

                cout << "Enter Book Title : ";
                cin >> title;

                cout << "Enter Author : ";
                cin >> author;

                cout << "Enter ISBN : ";
                cin >> isbn;

                cout << "Enter Quantity : ";
                cin >> quantity;

                libraryItems[itemCount] =
                    new Book(
                        title,
                        author,
                        isbn,
                        quantity);

                itemCount++;

                cout << "Book Added Successfully!"
                     << endl;

                break;
            }

                // Add DVD

            case 2:
            {
                string title;
                string director;
                int duration;

                cout << "Enter DVD Title : ";
                cin >> title;

                cout << "Enter Director : ";
                cin >> director;

                cout << "Enter Duration : ";
                cin >> duration;

                libraryItems[itemCount] =
                    new DVD(
                        title,
                        director,
                        duration);

                itemCount++;

                cout << "DVD Added Successfully!"
                     << endl;

                break;
            }

                // Add Magazine

            case 3:
            {
                string title;
                string publisher;
                int issueNumber;

                cout << "Enter Magazine Title : ";
                cin >> title;

                cout << "Enter Publisher : ";
                cin >> publisher;

                cout << "Enter Issue Number : ";
                cin >> issueNumber;

                libraryItems[itemCount] =
                    new Magazine(
                        title,
                        publisher,
                        issueNumber);

                itemCount++;

                cout << "Magazine Added Successfully!"
                     << endl;

                break;
            }

                // View All

            case 4:
            {
                for (int i = 0; i < itemCount; i++)
                {
                    libraryItems[i]->displayDetails();

                    cout << "------------------------"
                         << endl;
                }

                break;
            }

                // Search

            case 5:
            {
                string searchTitle;
                bool found = false;

                cout << "Enter Title : ";
                cin >> searchTitle;

                for (int i = 0; i < itemCount; i++)
                {
                    if (libraryItems[i]->getTitle() == searchTitle)
                    {
                        libraryItems[i]->displayDetails();

                        found = true;

                        break;
                    }
                }

                if (!found)
                {
                    cout << "Item Not Found!"
                         << endl;
                }

                break;
            }

                // Check Out

            case 6:
            {
                string searchTitle;
                bool found = false;

                cout << "Enter Title : ";
                cin >> searchTitle;

                for (int i = 0; i < itemCount; i++)
                {
                    if (libraryItems[i]->getTitle() == searchTitle)
                    {
                        libraryItems[i]->checkOut();

                        found = true;

                        break;
                    }
                }

                if (!found)
                {
                    cout << "Item Not Found!"
                         << endl;
                }

                break;
            }

                // Return

            case 7:
            {
                string searchTitle;
                bool found = false;

                cout << "Enter Title : ";
                cin >> searchTitle;

                for (int i = 0; i < itemCount; i++)
                {
                    if (libraryItems[i]->getTitle() == searchTitle)
                    {
                        libraryItems[i]->returnItem();

                        found = true;

                        break;
                    }
                }

                if (!found){
                    cout << "Item Not Found!"
                         << endl;
                }

                break;
            }
            case 8:
            {
                isRunning = false;

                cout << "Thank You For Visiting!"
                     << endl;

                break;
            }

            default:
            {
                cout << "Invalid Input!" << endl;
            }
            }
        }    
        catch (const char *error)
        {
            cout << "Error : "
                 << error << endl;
        }
    catch (...)
        {
            cout << "Something went wrong!"
                 << endl;
        }
    }

    for (int i = 0; i < itemCount; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}