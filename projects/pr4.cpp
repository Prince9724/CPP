#include <iostream>
using namespace std;

// Base Class

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount()
    {
        this->accountNumber = 0;
        this->accountHolderName = "";
        this->balance = 0;
    }

    BankAccount(
        int number,
        string name,
        double balance)
    {
        this->accountNumber = number;
        this->accountHolderName = name;
        this->balance = balance;
    }

    // Destructor
    virtual ~BankAccount()
    {
    }

    // Getters
    int getAccountNumber()
    {
        return this->accountNumber;
    }

    string getAccountHolderName()
    {
        return this->accountHolderName;
    }

    double getBalance()
    {
        return this->balance;
    }

    // Setters
    void setAccountNumber(int number)
    {
        this->accountNumber = number;
    }

    void setAccountHolderName(string name)
    {
        this->accountHolderName = name;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    // Deposit
    virtual void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid Amount!" << endl;
            return;
        }

        this->balance += amount;

        cout << "Deposit Successful!" << endl;
        cout << "New Balance : "
             << this->balance << endl;
    }

    // Withdraw
    virtual void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid Amount!" << endl;
            return;
        }

        if (amount > this->balance)
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }

        this->balance -= amount;

        cout << "Withdraw Successful!" << endl;
        cout << "New Balance : "
             << this->balance << endl;
    }

    // Display
    virtual void displayAccountInfo()
    {
        cout << endl;
        cout << "Account Number : "
             << this->accountNumber << endl;

        cout << "Account Holder : "
             << this->accountHolderName << endl;

        cout << "Balance : "
             << this->balance << endl;
    }

    // Virtual Interest
    virtual void calculateInterest()
    {
        cout << "Interest is not available." << endl;
    }
};

// Savings Account

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount()
        : BankAccount()
    {
        this->interestRate = 0;
    }

    SavingsAccount(
        int number,
        string name,
        double balance,
        double rate)
        : BankAccount(number, name, balance)
    {
        this->interestRate = rate;
    }

    ~SavingsAccount()
    {
    }

    // Getter
    double getInterestRate()
    {
        return this->interestRate;
    }

    // Setter
    void setInterestRate(double rate)
    {
        this->interestRate = rate;
    }

    // Interest
    void calculateInterest() override
    {
        double interest =
            getBalance() * this->interestRate / 100;

        cout << "Savings Interest : "
             << interest << endl;
    }

    // Display
    void displayAccountInfo() override
    {
        cout << endl;
        cout << "----- SAVINGS ACCOUNT -----" << endl;

        BankAccount::displayAccountInfo();

        cout << "Interest Rate : "
             << this->interestRate << "%" << endl;
    }
};

// Checking Account

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount()
        : BankAccount()
    {
        this->overdraftLimit = 0;
    }

    CheckingAccount(
        int number,
        string name,
        double balance,
        double limit)
        : BankAccount(number, name, balance)
    {
        this->overdraftLimit = limit;
    }

    ~CheckingAccount()
    {
    }

    // Getter
    double getOverdraftLimit()
    {
        return this->overdraftLimit;
    }

    // Setter
    void setOverdraftLimit(double limit)
    {
        this->overdraftLimit = limit;
    }

    // Withdraw
    void withdraw(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Invalid Amount!" << endl;
            return;
        }

        if (amount > getBalance() + this->overdraftLimit)
        {
            cout << "Overdraft Limit Exceeded!" << endl;
            return;
        }

        setBalance(getBalance() - amount);

        cout << "Withdraw Successful!" << endl;
        cout << "New Balance : "
             << getBalance() << endl;
    }

    // Check overdraft
    void checkOverdraft()
    {
        if (getBalance() < 0)
        {
            cout << "Overdraft is being used." << endl;
        }
        else
        {
            cout << "No Overdraft Used." << endl;
        }
    }

    // Display
    void displayAccountInfo() override
    {
        cout << endl;
        cout << "----- CHECKING ACCOUNT -----" << endl;

        BankAccount::displayAccountInfo();

        cout << "Overdraft Limit : "
             << this->overdraftLimit << endl;
    }
};

// Fixed Deposit Account

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount()
        : BankAccount()
    {
        this->term = 0;
        this->interestRate = 0;
    }

    FixedDepositAccount(
        int number,
        string name,
        double balance,
        int term,
        double rate)
        : BankAccount(number, name, balance)
    {
        this->term = term;
        this->interestRate = rate;
    }

    ~FixedDepositAccount()
    {
    }

    // Calculate Interest
    void calculateInterest() override
    {
        double interest =
            getBalance() *
            this->interestRate *
            this->term / (100 * 12);

        cout << "Fixed Deposit Interest : "
             << interest << endl;

        cout << "Maturity Amount : "
             << getBalance() + interest << endl;
    }

    // Withdraw
    void withdraw(double amount) override
    {
        cout << "Withdrawal is not allowed "
             << "from Fixed Deposit." << endl;
    }

    // Display
    void displayAccountInfo() override
    {
        cout << endl;
        cout << "----- FIXED DEPOSIT ACCOUNT -----"
             << endl;

        BankAccount::displayAccountInfo();

        cout << "Term : "
             << this->term << " Months" << endl;

        cout << "Interest Rate : "
             << this->interestRate << "%" << endl;
    }
};

// Main

int main()
{
    BankAccount *accounts[100];

    int accountCount = 0;

    bool isRunning = true;

    while (isRunning)
    {
        int input;

        cout << endl;
        cout << "================================" << endl;
        cout << "       BANKING SYSTEM" << endl;
        cout << "================================" << endl;

        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. View All Accounts" << endl;
        cout << "5. Deposit" << endl;
        cout << "6. Withdraw" << endl;
        cout << "7. Calculate Interest" << endl;
        cout << "8. Check Overdraft" << endl;
        cout << "9. Search Account By Number" << endl;
        cout << "10. Exit" << endl;

        cout << endl;
        cout << "Enter your input : ";
        cin >> input;

        switch (input)
        {

            // Savings

        case 1:
        {
            int number;
            string name;
            double balance;
            double rate;

            cout << "Enter Account Number : ";
            cin >> number;

            cout << "Enter Account Holder Name : ";
            cin >> name;

            cout << "Enter Balance : ";
            cin >> balance;

            cout << "Enter Interest Rate : ";
            cin >> rate;

            accounts[accountCount] =
                new SavingsAccount(
                    number,
                    name,
                    balance,
                    rate);

            accountCount++;

            cout << "Savings Account Created!" << endl;

            break;
        }

            // Checking

        case 2:
        {
            int number;
            string name;
            double balance;
            double limit;

            cout << "Enter Account Number : ";
            cin >> number;

            cout << "Enter Account Holder Name : ";
            cin >> name;

            cout << "Enter Balance : ";
            cin >> balance;

            cout << "Enter Overdraft Limit : ";
            cin >> limit;

            accounts[accountCount] =
                new CheckingAccount(
                    number,
                    name,
                    balance,
                    limit);

            accountCount++;

            cout << "Checking Account Created!" << endl;

            break;
        }

            // Fixed Deposit

        case 3:
        {
            int number;
            string name;
            double balance;
            int term;
            double rate;

            cout << "Enter Account Number : ";
            cin >> number;

            cout << "Enter Account Holder Name : ";
            cin >> name;

            cout << "Enter Balance : ";
            cin >> balance;

            cout << "Enter Term In Months : ";
            cin >> term;

            cout << "Enter Interest Rate : ";
            cin >> rate;

            accounts[accountCount] =
                new FixedDepositAccount(
                    number,
                    name,
                    balance,
                    term,
                    rate);

            accountCount++;

            cout << "Fixed Deposit Account Created!"
                 << endl;

            break;
        }

            // View All

        case 4:
        {
            for (int i = 0; i < accountCount; i++)
            {
                accounts[i]->displayAccountInfo();

                cout << "------------------------" << endl;
            }

            break;
        }

            // Deposit

        case 5:
        {
            int searchNo;
            double amount;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> searchNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == searchNo)
                {
                    cout << "Enter Amount : ";
                    cin >> amount;

                    accounts[i]->deposit(amount);

                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found!" << endl;
            }

            break;
        }

            // Withdraw

        case 6:
        {
            int searchNo;
            double amount;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> searchNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == searchNo)
                {
                    cout << "Enter Amount : ";
                    cin >> amount;

                    accounts[i]->withdraw(amount);

                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found!" << endl;
            }

            break;
        }

            // Interest

        case 7:
        {
            int searchNo;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> searchNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == searchNo)
                {
                    accounts[i]->calculateInterest();

                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found!" << endl;
            }

            break;
        }

            // Overdraft

        case 8:
        {
            int searchNo;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> searchNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == searchNo)
                {
                    CheckingAccount *checking =
                        dynamic_cast<CheckingAccount *>(
                            accounts[i]);

                    if (checking != nullptr)
                    {
                        checking->checkOverdraft();
                    }
                    else
                    {
                        cout << "This is not "
                             << "a Checking Account."
                             << endl;
                    }

                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found!" << endl;
            }

            break;
        }

            // Search

        case 9:
        {
            int searchNo;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> searchNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == searchNo)
                {
                    accounts[i]->displayAccountInfo();

                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found!" << endl;
            }

            break;
        }

            // Exit

        case 10:
        {
            isRunning = false;

            cout << "Thank You For Visiting!" << endl;

            break;
        }

        default:
        {
            cout << "Invalid Input!" << endl;
        }
        }
    }

    for (int i = 0; i < accountCount; i++)
    {
        delete accounts[i];
    }

    return 0;
}