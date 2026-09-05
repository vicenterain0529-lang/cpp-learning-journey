#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string name;
    bool isvalid = false;
// input amount checker
    while(!isvalid){
        cout<< "Enter your name:"<< endl;
        getline(cin, name);
    // Characters amount checker
        if (name.empty()){
            cout<< "Name cannot be empty";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (name.length() > 12){
            cout << "Name cant exceed 12 letters:" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        // valid name since it passed the checking
        isvalid = true;
        for(char letters : name){
            if (!isalpha(letters) && letters != ' '){
                isvalid = false;
                break;

            }
        }
        if (!isvalid){
            cout <<  "Invalid characters: Enter letters only (space included)" << endl;
        }
        else{
            cout << "Welcome "<< name;
        }
    }
    }
