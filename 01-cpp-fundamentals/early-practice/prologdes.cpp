#include <iostream>
using namespace std;

int main(){
    int mynum1;
    int mynum2;
    int remainder;
    cout << "Enter number 1: ";
    cin >> mynum1;
    cout << "Enter number 2 ";
    cin >> mynum2;

    remainder = mynum1 % mynum2;
    cout << "The remainder is: "<< remainder << "\n";
    
    if(remainder == 0){
        cout << "Even";
    }
    else{
        cout << "odd";
    }









}



