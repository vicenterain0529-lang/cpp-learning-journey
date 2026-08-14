#include <iostream>
using namespace std;

int main() {

    char answer;

    cout << "My name is Vicente, Rain E.!" << "\n";
    cout << "I am learning C++!" << "\n" << "\n";
    cout << "Are you also new to C++?" << "\n";
    cout << "'y'- yes" << "\n";
    cout << "'n' - no" << "\n";
    cout << "answer:  ";

    if (!(cin >> answer)) {
        cout << "Invalid choice";
    }

    else if (answer == 'y') {
        cout << "Great! Let's Learn Together!";
    }

    else if (answer == 'n') {
        cout << "Understood! Have a Nice Day!";
    }

    else {
        cout << "Invalid choice";
    }

    return 0;
}