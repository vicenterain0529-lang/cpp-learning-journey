#include <iostream>
using namespace std;

int searchArray(string array[], int size, string element);

int main() {
    string students[] = {"Rain", "Gab", "Ashley", "Issabel", "Jose"};
    
    int size = sizeof(students) / sizeof(students[0]);
    int index;
    string myStudent;
while (true){
    cout << "Enter the name of the student to search for: ";
    cin >> myStudent;

    index = searchArray(students, size, myStudent);

    if (index != -1) {
        cout << myStudent << " is at index " << index;
    }
    else {
        cout << "Can't be found";
    }

    
}}

int searchArray(string array[], int size, string element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }

    return -1;
}