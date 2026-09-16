#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    int accountNumber;
    int balance;
    string name;

public:
    void setAccount(int a, int b, string n) {
        this->accountNumber = a;
        this->balance = b;
        this->name = n;
    }

    void credit(int amount) {
        balance = balance + amount;
        cout << "Amount credited successfully." << endl;
    }

  
    void debit(int amount) { 
        if (amount <= balance) {
            balance = balance - amount;
            cout << "Amount debited successfully." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

   
    void getBalance() { 
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount a1;
    a1.setAccount(1, 5000, "hero");
    
    a1.getBalance(); 
    a1.credit(4000);
    a1.getBalance();
    a1.debit(1000);
    a1.getBalance();
    return 0;
}
