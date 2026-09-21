#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d = "Not Set")
    {
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
    }

    virtual ~LibraryItem() {}

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    void setTitle(string newTitle)
    {
        if (newTitle.empty())
            throw invalid_argument("Title cannot be empty.");

        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        if (newAuthor.empty())
            throw invalid_argument("Author cannot be empty.");

        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem
{
private:
    string isbn;
    bool available;

public:
    Book(string title, string author, string dueDate, string isbn)
        : LibraryItem(title, author, dueDate)
    {
        if (isbn.length() < 10)
            throw invalid_argument("Invalid ISBN format.");

        this->isbn = isbn;
        available = true;
    }

    void checkOut() override
    {
        if (!available)
        {
            cout << "Book is already checked out.\n";
            return;
        }

        available = false;
        setDueDate("30 Days");
        cout << "Book checked out successfully.\n";
    }

    void returnItem() override
    {
        if (available)
        {
            cout << "Book is already available.\n";
            return;
        }

        available = true;
        setDueDate("Not Set");
        cout << "Book returned successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\nType       : Book\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Author     : " << getAuthor() << endl;
        cout << "ISBN       : " << isbn << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Status     : " << (available ? "Available" : "Checked Out") << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;
    bool available;

public:
    DVD(string title, string author, string dueDate, int duration)
        : LibraryItem(title, author, dueDate)
    {
        if (duration <= 0)
            throw invalid_argument("Duration must be greater than zero.");

        this->duration = duration;
        available = true;
    }

    void checkOut() override
    {
        if (!available)
        {
            cout << "DVD is already checked out.\n";
            return;
        }

        available = false;
        setDueDate("15 Days");
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override
    {
        if (available)
        {
            cout << "DVD is already available.\n";
            return;
        }

        available = true;
        setDueDate("Not Set");
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\nType       : DVD\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Author     : " << getAuthor() << endl;
        cout << "Duration   : " << duration << " minutes" << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Status     : " << (available ? "Available" : "Checked Out") << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;
    bool available;

public:
    Magazine(string title, string author, string dueDate, int issueNumber)
        : LibraryItem(title, author, dueDate)
    {
        if (issueNumber <= 0)
            throw invalid_argument("Issue number must be greater than zero.");

        this->issueNumber = issueNumber;
        available = true;
    }

    void checkOut() override
    {
        if (!available)
        {
            cout << "Magazine is already checked out.\n";
            return;
        }

        available = false;
        setDueDate("7 Days");
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override
    {
        if (available)
        {
            cout << "Magazine is already available.\n";
            return;
        }

        available = true;
        setDueDate("Not Set");
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\nType         : Magazine\n";
        cout << "Title        : " << getTitle() << endl;
        cout << "Author       : " << getAuthor() << endl;
        cout << "Issue Number : " << issueNumber << endl;
        cout << "Due Date     : " << getDueDate() << endl;
        cout << "Status       : " << (available ? "Available" : "Checked Out") << endl;
    }
};

int searchItem(LibraryItem* libraryItems[], int itemCount, string title)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (libraryItems[i]->getTitle() == title)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    LibraryItem* libraryItems[MAX_ITEMS];

    int itemCount = 0;
    int choice;

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        libraryItems[i] = nullptr;
    }

    do
    {
        cout << "\n====================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Search Item\n";
        cout << "6. Check Out Item\n";
        cout << "7. Return Item\n";
        cout << "8. Remove Item\n";
        cout << "9. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                if (itemCount >= MAX_ITEMS)
                {
                    throw runtime_error("Library catalog is full.");
                }

                string title, author, isbn;

                cout << "\nEnter Book Title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                cout << "Enter Author Name: ";
                getline(cin, author);

                cout << "Enter ISBN: ";
                getline(cin, isbn);

                libraryItems[itemCount] =
                    new Book(title, author, "Not Set", isbn);

                itemCount++;

                cout << "Book added successfully.\n";
            }

            else if (choice == 2)
            {
                if (itemCount >= MAX_ITEMS)
                {
                    throw runtime_error("Library catalog is full.");
                }

                string title, author;
                int duration;

                cout << "\nEnter DVD Title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                cout << "Enter Author/Director Name: ";
                getline(cin, author);

                cout << "Enter Duration in Minutes: ";
                cin >> duration;

                if (duration <= 0)
                {
                    throw invalid_argument("Duration cannot be negative or zero.");
                }

                libraryItems[itemCount] =
                    new DVD(title, author, "Not Set", duration);

                itemCount++;

                cout << "DVD added successfully.\n";
            }

            else if (choice == 3)
            {
                if (itemCount >= MAX_ITEMS)
                {
                    throw runtime_error("Library catalog is full.");
                }

                string title, author;
                int issueNumber;

                cout << "\nEnter Magazine Title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                cout << "Enter Author Name: ";
                getline(cin, author);

                cout << "Enter Issue Number: ";
                cin >> issueNumber;

                if (issueNumber <= 0)
                {
                    throw invalid_argument("Issue number must be positive.");
                }

                libraryItems[itemCount] =
                    new Magazine(title, author, "Not Set", issueNumber);

                itemCount++;

                cout << "Magazine added successfully.\n";
            }

            else if (choice == 4)
            {
                if (itemCount == 0)
                {
                    cout << "\nNo items available in library.\n";
                }
                else
                {
                    cout << "\n========== ALL LIBRARY ITEMS ==========\n";

                    for (int i = 0; i < itemCount; i++)
                    {
                        cout << "\nItem " << i + 1 << endl;
                        libraryItems[i]->displayDetails();
                    }
                }
            }

            else if (choice == 5)
            {
                string title;

                cout << "\nEnter Title to Search: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                int index = searchItem(libraryItems, itemCount, title);

                if (index == -1)
                {
                    cout << "Item not found.\n";
                }
                else
                {
                    cout << "\nItem found successfully.\n";
                    libraryItems[index]->displayDetails();
                }
            }

            else if (choice == 6)
            {
                string title;

                cout << "\nEnter Title to Check Out: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                int index = searchItem(libraryItems, itemCount, title);

                if (index == -1)
                {
                    cout << "Item not found.\n";
                }
                else
                {
                    libraryItems[index]->checkOut();
                }
            }

            else if (choice == 7)
            {
                string title;

                cout << "\nEnter Title to Return: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                int index = searchItem(libraryItems, itemCount, title);

                if (index == -1)
                {
                    cout << "Item not found.\n";
                }
                else
                {
                    libraryItems[index]->returnItem();
                }
            }

            else if (choice == 8)
            {
                string title;

                cout << "\nEnter Title to Remove: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);

                int index = searchItem(libraryItems, itemCount, title);

                if (index == -1)
                {
                    cout << "Item not found.\n";
                }
                else
                {
                    delete libraryItems[index];

                    for (int i = index; i < itemCount - 1; i++)
                    {
                        libraryItems[i] = libraryItems[i + 1];
                    }

                    libraryItems[itemCount - 1] = nullptr;

                    itemCount--;

                    cout << "Item removed successfully.\n";
                }
            }

            else if (choice == 9)
            {
                cout << "\nThank you for using Library Management System.\n";
            }

            else
            {
                cout << "\nInvalid choice. Please try again.\n";
            }
        }
        catch (const exception& e)
        {
            cout << "\nError: " << e.what() << endl;
        }

    } while (choice != 9);

    for (int i = 0; i < itemCount; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}