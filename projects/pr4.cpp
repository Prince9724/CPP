#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

protected:
    double getAccountBalance()
    {
        return balance;
    }

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual ~BankAccount() {}

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else
        {
            cout << "Insufficient balance.\n";
        }
    }

    double getBalance()
    {
        return balance;
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation is not available for this account.\n";
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number     : " << accountNumber << endl;
        cout << "Account Holder     : " << accountHolderName << endl;
        cout << "Balance            : Rs. " << fixed << setprecision(2) << balance << endl;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getAccountBalance() * interestRate / 100;

        cout << "Interest Rate      : " << interestRate << "%" << endl;
        cout << "Calculated Interest: Rs. "
             << fixed << setprecision(2) << interest << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n--- Savings Account ---\n";
        BankAccount::displayAccountInfo();
        cout << "Interest Rate      : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount <= getAccountBalance() + overdraftLimit)
        {
            BankAccount::withdraw(amount);

            if (amount > getAccountBalance())
            {
                cout << "Overdraft facility used.\n";
            }
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit.\n";
        }
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit    : Rs. "
             << fixed << setprecision(2) << overdraftLimit << endl;

        cout << "Available Amount   : Rs. "
             << fixed << setprecision(2)
             << getAccountBalance() + overdraftLimit << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n--- Checking Account ---\n";
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit    : Rs. "
             << fixed << setprecision(2) << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int months, double rate)
        : BankAccount(accNo, name, bal)
    {
        term = months;
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getAccountBalance() * interestRate * term / (12 * 100);

        cout << "Interest Rate      : " << interestRate << "%" << endl;
        cout << "Term               : " << term << " months" << endl;
        cout << "Calculated Interest: Rs. "
             << fixed << setprecision(2) << interest << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n--- Fixed Deposit Account ---\n";
        BankAccount::displayAccountInfo();
        cout << "Interest Rate      : " << interestRate << "%" << endl;
        cout << "Term               : " << term << " months" << endl;
    }
};

int findAccount(vector<unique_ptr<BankAccount>>& accounts, int accountNumber)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i]->getAccountNumber() == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<unique_ptr<BankAccount>> accounts;

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "        BANKING SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Display Account Information\n";
        cout << "7. Check Balance\n";
        cout << "8. Calculate Interest\n";
        cout << "9. Check Overdraft\n";
        cout << "10. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int accNo;
            string name;
            double balance, rate;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            if (findAccount(accounts, accNo) != -1)
            {
                cout << "Account number already exists.\n";
                continue;
            }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Interest Rate (%): ";
            cin >> rate;

            accounts.push_back(
                make_unique<SavingsAccount>(accNo, name, balance, rate)
            );

            cout << "Savings account created successfully.\n";
        }

        else if (choice == 2)
        {
            int accNo;
            string name;
            double balance, limit;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            if (findAccount(accounts, accNo) != -1)
            {
                cout << "Account number already exists.\n";
                continue;
            }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            accounts.push_back(
                make_unique<CheckingAccount>(accNo, name, balance, limit)
            );

            cout << "Checking account created successfully.\n";
        }

        else if (choice == 3)
        {
            int accNo;
            string name;
            double balance, rate;
            int term;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            if (findAccount(accounts, accNo) != -1)
            {
                cout << "Account number already exists.\n";
                continue;
            }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Deposit: ";
            cin >> balance;

            cout << "Enter Term in Months: ";
            cin >> term;

            cout << "Enter Interest Rate (%): ";
            cin >> rate;

            accounts.push_back(
                make_unique<FixedDepositAccount>(
                    accNo, name, balance, term, rate
                )
            );

            cout << "Fixed deposit account created successfully.\n";
        }

        else if (choice == 4)
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, accNo);

            if (index == -1)
            {
                cout << "Account not found.\n";
            }
            else
            {
                cout << "Enter Deposit Amount: ";
                cin >> amount;

                accounts[index]->deposit(amount);
            }
        }

        else if (choice == 5)
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, accNo);

            if (index == -1)
            {
                cout << "Account not found.\n";
            }
            else
            {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;

                accounts[index]->withdraw(amount);
            }
        }

        else if (choice == 6)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, accNo);

            if (index == -1)
            {
                cout << "Account not found.\n";
            }
            else
            {
                accounts[index]->displayAccountInfo();
            }
        }

        else if (choice == 7)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, accNo);

            if (index == -1)
            {
                cout << "Account not found.\n";
            }
            else
            {
                cout << "Current Balance: Rs. "
                     << fixed << setprecision(2)
                     << accounts[index]->getBalance() << endl;
            }
        }

        else if (choice == 8)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, accNo);

            if (index == -1)
            {
                cout << "Account not found.\n";
            }
            else
            {
                accounts[index]->calculateInterest();
            }
        }

        else if (choice == 9)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            int index = findAccount(accounts, accNo);

            if (index == -1)
            {
                cout << "Account not found.\n";
            }
            else
            {
                CheckingAccount* checking =
                    dynamic_cast<CheckingAccount*>(accounts[index].get());

                if (checking != nullptr)
                {
                    checking->checkOverdraft();
                }
                else
                {
                    cout << "This is not a checking account.\n";
                }
            }
        }

        else if (choice == 10)
        {
            cout << "\nThank you for using Banking System.\n";
        }

        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 10);

    return 0;
}