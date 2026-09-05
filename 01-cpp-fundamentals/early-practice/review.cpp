#include <iostream>
using namespace std;

double temp(double num1, int conversion){
    double results;

    switch(conversion){
        case 1:
            results = (num1 * 9/5) + 32;

            break;
        case 2:
            results = (num1 - 32) * 5/9;
            break;
    }
    return results;
}

void display_menu() {
    cout << "========== TEMPERATURE CONVERTER ==========" << endl;
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Exit\n";
    cout << "=============================================" << endl;
    cout << "Enter your choice: (1-3) ";
}
int main() {
        int conversion;
        double num1;
        double results;
        char symbol;
    while (true)
    {
        display_menu();
        // input checker if the input is not of the same data type
        if (!(cin >> conversion)){
            cout << "Invalid number, please choose 1-3 only!";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
                // prints reminder in conversion

        if(conversion == 1){
            cout << "Convert Celsius to Fahrenheit:" << endl;
        }
        if(conversion == 2){
        cout << "Convert Fahrenheit to Celsius:" << endl;    
        }


        // values for temperature
        cout << "Enter the temperature: ";
        if(!(cin >> num1)){
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (conversion == 3){
            cout << " THANKS! ";
            break;
        }




        results = temp(num1, conversion);

    conversion == 1 ? symbol = 'F' : symbol ='C';

    cout << "Result: " << num1 << " " << "to " << " " << results << symbol << endl;
    }


    return 0;
}