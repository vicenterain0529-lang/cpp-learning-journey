#include <iostream>
using namespace std;
#include <cstdlib>

double calc_check(double num1, double num2, int op) {
    double result;

    switch (op) {
        case 1:
            result = num1 + num2;
            break;

        case 2:
            result = num1 - num2;
            break;

        case 3:
            result = num1 * num2;
            break;

        case 4:
            result = num1 / num2;
            break;

        default:
            return 0;
    }

    return result;
}


void display_menu() {
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "6. Others\n";
}

int main(){
    int op;
    double num1, num2;
    double result;
    char operation;

    while (true){
        cout << "========== CALCULATOR ==========" << endl;
        display_menu();
        cout<< "Enter your choice: (1-6)";

        if (!(cin >> op)) {
            cout << "Invalid input. Please enter a number from 1-6. \n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if(op ==5){
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }
        if (op == 6){
            cout << "MISS YOU SO MUCH MY BABY!!!! PA KISS PO " << endl;
            system("start https://www.youtube.com/watch?v=buU9clZzI-o");
            break;
        }
        
        if(op <1 || op >6){
            cout<< "Invalid choice. Please select a valid option (1-6)." << endl;
            continue;
        }

        cout << "Enter #1: ";
        if (!(cin >> num1)) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cout<< "Enter #2: ";
        if (!(cin >> num2)) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        result = calc_check(num1, num2, op);


        if (op == 1){
            operation = '+';
        }
        else if (op == 2){
            operation = '-';
        }
        else if (op == 3){
            operation = '*';
        }
        else if (op == 4){
            operation = '/';
        }
                cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    }
}
