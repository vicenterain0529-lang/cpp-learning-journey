#include <iostream>
#include <cctype>
using namespace std;

int main (){
    bool inWord = false;
    int wordCount = 0;


    cout << "Paste your essay below: \n";
    cout<< "Press ctrl + z after pasting the essay\n";

    char c;
    
    while(cin.get(c)){
        //kung may space sa words 
        if(isspace(c)){
            inWord = false;
        }
        else if(!inWord){
            wordCount++;
            inWord = true;
        } 
    }cout << "\nWord count: " << wordCount << endl;

    return 0;

    








}