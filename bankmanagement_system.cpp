/*
Bank Account Management System:-
Concepts: Classes, Inheritance, Encapsulation 
Details: Develop a system to manage bank accounts.
Include features like deposit, withdrawal, balance inquiry, and account details.
Use inheritance for different types of accounts like Savings and Current.
*/
#include <iostream>
using namespace std;
// Base class: Account
class Account {
public:
    string accountHolder_Name;
    int account_Number;
    double balance;
public:
    // Constructor to initialize account details
    Account(string name, int accNo, double bal)
    {
    accountHolder_Name=name;
    account_Number=accNo;
    balance=bal;
    }
    // Function to deposit amount
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited: " << amount << "\n";
        cout << "New balance: " << balance << "\n";
    }
    // Function to withdraw amount
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << "\n";
            cout << "Remaining balance: " << balance << "\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }
    // Function to display balance
    void balanceInquiry() const {
        cout << "Current balance: " << balance << "\n";
    }
    // Function to display account details
    void accountDetails() const {
        cout << "Account Holder: " << accountHolder_Name << "\n";
        cout << "Account Number: " << account_Number << "\n";
        cout << "Balance: " << balance << "\n";
    }
};
// Derived class: SavingsAccount (inherits from Account)
class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(string name, int accNo, double bal, double rate)
        : Account(name, accNo, bal), interestRate(rate) {}
    // Function to apply interest to balance
    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest applied: " << interest << "\n";
        cout << "New balance after interest: " << balance << "\n";
    }
};
// Derived class: CurrentAccount (inherits from Account)
class CurrentAccount : public Account {
public:
    CurrentAccount(string name, int accNo, double bal) : Account(name, accNo, bal) {}
    // Current accounts usually don't have interest, so no extra features here
};
int main() {
    // Create a Savings Account
    SavingsAccount savings("Ali", 2101, 5000.0, 3.0);
    cout << "Savings Account Details:\n";
    savings.accountDetails();
    savings.deposit(7000.0);
    savings.withdraw(5000.0);
    savings.balanceInquiry();
    savings.applyInterest();
    cout << "\n";
    // Create a Current Account
    CurrentAccount current("Azmat", 5102, 10000.0);
    cout << "Current Account Details:\n";
    current.accountDetails();
    current.deposit(20000.0);
    current.withdraw(3000.0);
    current.balanceInquiry();
    return 0;
}