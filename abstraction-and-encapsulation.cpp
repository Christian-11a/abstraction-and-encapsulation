#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// Base Class: BankAccount
class BankAccount {
protected:
    double balance;

public:
    BankAccount(double initial_balance) {
        balance = initial_balance;
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposit successful!" << endl;
        } else {
            cout << "\nInvalid amount. Deposit must be greater than 0." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "\nWithdrawal successful!" << endl;
        } else if (amount <= 0) {
            cout << "\nInvalid amount. Withdrawal must be greater than 0." << endl;
        } else {
            cout << "\nInsufficient funds!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    virtual void displayMenu() = 0;  // Pure virtual function for abstraction

    // Helper function to validate numeric input
    bool validInput(string input, double &amount) {
        bool decimalPoint = false;  // Track if a decimal point has been seen
        for (char c : input) {
            if (!isdigit(c)) {
                if (c == '.' && !decimalPoint) {
                    decimalPoint = true;  // Allow one decimal point
                } else {
                    cout << "\nInvalid input. Please enter a valid number." << endl;
                    return false;
                }
            }
        }

        try {
            amount = stod(input);  // Convert the valid numeric string to a double
            return true;
        } catch (...) {
            cout << "\nInvalid input. Please enter a valid number." << endl;
            return false;
        }
    }

    // Helper function to validate menu choice
    bool validMenuInput(string input, char &choice) {
        if (input.length() == 1 && isdigit(input[0])) {
            choice = input[0];
            return true;
        }
        cout << "\nInvalid input. Please enter a valid menu option." << endl;
        system("pause");
        system("cls");
        return false;
    }
};

// Derived Class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    const double min_balance = 1000;

public:
    SavingsAccount(double initial_balance) : BankAccount(initial_balance) {}

    void withdraw(double amount) override {
        if (balance - amount >= min_balance && amount > 0) {
            BankAccount::withdraw(amount);
        } else if (amount <= 0) {
            cout << "\nInvalid amount. Withdrawal must be greater than 0." << endl;
        } else {
            cout << "\nWithdrawal denied! Minimum balance of 1000 required." << endl;
        }
    }

    void displayMenu() override {
        string input;
        char choice;
        double amount;
        do {
            cout << "\n--- Savings Account Menu ---" << endl;
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back to Main Menu" << endl;
            cout << "\nEnter your choice: ";
            cin >> input;

            if (validMenuInput(input, choice)) {
                switch (choice) {
                    case '1':
                        cout << "\nEnter amount to deposit: ";
                        cin >> input;
                        if (validInput(input, amount)) deposit(amount);
                        system("pause");
                        system("cls");
                        break;
                    case '2':
                        cout << "\nEnter amount to withdraw: ";
                        cin >> input;
                        if (validInput(input, amount)) withdraw(amount);
                        system("pause");
                        system("cls");
                        break;
                    case '3':
                        cout << "\nCurrent Balance: " << fixed << setprecision(2) << getBalance() << endl;
                        system("pause");
                        system("cls");
                        break;
                    case '4':
                        system("cls");
                        break;
                    default:
                        cout << "\nInvalid choice! Please try again." << endl;
                        system("pause");
                        system("cls");
                }
            }
        } while (choice != '4');
    }
};

// Derived Class: CurrentAccount
class CurrentAccount : public BankAccount {
public:
    CurrentAccount(double initial_balance) : BankAccount(initial_balance) {}

    void displayMenu() override {
        string input;
        char choice;
        double amount;
        do {
            cout << "\n--- Current Account Menu ---" << endl;
            cout << "1 - Deposit" << endl;
            cout << "2 - Withdraw" << endl;
            cout << "3 - Check Balance" << endl;
            cout << "4 - Back to Main Menu" << endl;
            cout << "\nEnter your choice: ";
            cin >> input;

            if (validMenuInput(input, choice)) {
                switch (choice) {
                    case '1':
                        cout << "\nEnter amount to deposit: ";
                        cin >> input;
                        if (validInput(input, amount)) deposit(amount);
                        system("pause");
                        system("cls");
                        break;
                    case '2':
                        cout << "\nEnter amount to withdraw: ";
                        cin >> input;
                        if (validInput(input, amount)) withdraw(amount);
                        system("pause");
                        system("cls");
                        break;
                    case '3':
                        cout << "\nCurrent Balance: " << fixed << setprecision(2) << getBalance() << endl;
                        system("pause");
                        system("cls");
                        break;
                    case '4':
                        system("cls");
                        break;
                    default:
                        cout << "\nInvalid choice! Please try again." << endl;
                        system("pause");
                        system("cls");
                }
            }
        } while (choice != '4');
    }
};

// Main Menu Function
void MainMenu() {
    string input;
    char choice;
    SavingsAccount savings(1000);  // Initial balance for Savings Account
    CurrentAccount current(500);   // Initial balance for Current Account
    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1 - Savings Account" << endl;
        cout << "2 - Current Account" << endl;
        cout << "3 - Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> input;

        if (savings.validMenuInput(input, choice)) {
            switch (choice) {
                case '1':
                    system("cls");
                    savings.displayMenu();
                    break;
                case '2':
                    system("cls");
                    current.displayMenu();
                    break;
                case '3':
                    cout << "\nExiting the system. Goodbye!" << endl;
                    system("pause");
                    break;
                default:
                    cout << "\nInvalid choice! Please try again." << endl;
                    system("pause");
                    system("cls");
            }
        }
    } while (choice != '3');
}

// Main Function
int main() {
    MainMenu();
    return 0;
}
