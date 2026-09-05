#include <iostream>
#include <ctime>
using namespace std;

int main()
{
int guess;
int randNum;
int chances = 3;
int tries = 0;
int chanceLeft;
bool tryAgain = false;


srand(time(NULL));
randNum = rand() % 10 + 1;
cout << "============== NUMBER GUESSING GAME===============" << endl;

do{
    cout << "Guess the number: "<< endl;
    cin >>  guess;

    if(guess == randNum){
            cout << "You are correct!\n";
            cout << "You guessed " << guess << '\n';
            cout << "The random number is: " << randNum << '\n';
            break;
    }
    tries++;
    chanceLeft = chances - tries;

    cout << "Your guess is: " << guess << '\n';
    cout << "You have " << chanceLeft << "/ " << chances << endl;
    if (chanceLeft == 0){
        cout << "You lost!" << endl;
        cout << "The number is: " << randNum << endl;
        break;
    }
    cout << "==============================================" << endl;
}while(guess != randNum);


}