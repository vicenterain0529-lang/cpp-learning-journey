#include <iostream>
#include <cctype>
using namespace std;


void textAnalyzer(
    int& wordCount,
    int& spaceCount,
    int& letterCount,
    int& numberCount,
    int& punctuationCount,
    bool& inWord,
    char c
) {
    if (isalpha(c)) {
        letterCount++;
    }

    if (isdigit(c)) {
        numberCount++;
    }

    if (ispunct(c)) {
        punctuationCount++;
    }

    if (isspace(c)) {
        spaceCount++;
        inWord = false;
    }
    else if (!inWord) {
        wordCount++;
        inWord = true;
    }
}



int main(){
bool inWord = false;
char c;
int wordCount = 0;
int spaceCount = 0;
int letterCount = 0;
int numberCount = 0;
int punctuationCount = 0;




    cout <<"Enter your paragraph: \n";
    cout << "Press ctrl + z to enter after pasting";


    while(cin.get(c)){
    textAnalyzer(
        wordCount,
        spaceCount,
        letterCount,
        numberCount,
        punctuationCount,
        inWord,
        c
    );

    }
    cout << "Spaces: " << spaceCount<< '\n';
    cout<< "Words: " << wordCount<< '\n';
    cout << "Letters: " << letterCount<< '\n';
    cout<< "Numbers: " << numberCount<< '\n';
    cout<< "Punctuations: " << punctuationCount<< '\n';




}





