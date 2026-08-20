#include <iostream>
using namespace std;

double showBalance(double balance);
void displayMenu();
double deposit(double balance);
double withdraw(double balance);

int main() {
    double balance = 0;
    int operations;

    while (true)
    {
        displayMenu();
        cout << "What do you want to do? (choose 1-4): \n";
        if(!(cin >> operations)){
            cout << "Invalid input! Enter numbers only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if(operations < 1 || operations >4 ){
            cout << "Enter numbers (1-4) only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (operations)
        {
        case 1:
            showBalance(balance);
            break;

        case 2:
            balance = deposit(balance);
            break;

        case 3:
            balance = withdraw(balance);
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid option.\n";
        }
    }
}

double showBalance(double balance) {
    char peso = 'P';

    cout << "Your current balance is: " << peso << balance << endl;
    return balance;
}

void displayMenu() {
    cout << "================= BANKING PROGRAM =================\n";
    cout << "1. View Balance\n"
        << "2. Deposit\n"
        << "3. Withdraw\n"
        << "4. Exit\n";
}

double deposit(double balance) {
    char peso = 'P';
    double depositedMoney;

    cout << "Enter deposit amount: ";
    cin >> depositedMoney;

    balance = balance + depositedMoney;

    cout << "You added: " << peso << depositedMoney << '\n';

    showBalance(balance);

    return balance;
}



double withdraw(double balance) {
    char peso = 'P';
    double withdrawnMoney;
cout <<"Enter withdraw amount: ";
cin  >>withdrawnMoney;


if (withdrawnMoney > balance){
cout<< "Not enough balance!\n";
}
else{
    balance = balance - withdrawnMoney;
    cout << "You withdrew: " << peso << withdrawnMoney << '\n';
    showBalance(balance);
}


    return balance;
}