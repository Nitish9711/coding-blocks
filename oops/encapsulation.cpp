#include <iostream>

class BankAccount {
public:
    BankAccount(int initial_balance) {
        balance = initial_balance;
    }

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    int get_balance() const {
        return balance;
    }

private:
    int balance;
};

int main() {
    BankAccount account(1000);
    account.deposit(500);
    account.withdraw(200);
    std::cout << "Current balance: " << account.get_balance() << std::endl;
    return 0;
}

/*In this program, we define a BankAccount class that represents a simple bank account. 
The class has three public member functions: deposit, withdraw, and get_balance, which provide a 
well-defined interface for interacting with the account. The deposit function allows money to be added 
to the account, the withdraw function allows money to be withdrawn (if sufficient funds are available), 
and the get_balance function returns the current balance of the account.

The balance data field, which represents the current balance of the account, is declared as private. 
This means that it is not visible to code outside of the class, and can only be accessed or modified 
through the public member functions. This ensures that the balance can only be changed in a controlled 
and consistent way, which helps to prevent bugs and maintain the integrity of the account.

Encapsulation is a powerful tool for building reliable and maintainable programs, as it allows us to 
hide the complexity of an object's internal workings and provide a clean, well-defined interface for 
interacting with it.*/