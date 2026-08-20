#include <iostream>
using namespace std;
#include <conio.h>
#include <cstdlib> // Required for rand() and srand()
#include <ctime> 



// Function declarations
void playerMovement(int& playerRow, int& playerColumn);
void mapGeneration(int playerRow, int playerColumn, int enemyRow, int enemyColumn);
void randomPair(int& randnumX, int& randnumY);
void enemyRespawn(int& score, int playerRow, int playerColumn, int& enemyRow, int& enemyColumn);

// map constants
const int MAP_WIDTH = 25;
const int MAP_HEIGHT = 5;

int main() {
srand(time(NULL));

    int score = 0;

    int enemyRow;
    int enemyColumn;
    char userChoice;
    int playerRow = 2;
    int playerColumn = 5;

randomPair(enemyRow, enemyColumn);


    cout << "============================= MOVEMENT SIMULATOR =====================================\n";
cout << "Do you want to play a game? (y/n) \n";
cin >> userChoice;
if (userChoice == 'y'|| userChoice == 'Y'){
    while(true){

    //clears the terminal #jonhu x hance
    cout << "\033[2J\033[H";

    enemyRespawn(score, playerRow, playerColumn, enemyRow, enemyColumn);

    cout << "Score: " << score << '\n';

    // Draw the map
    mapGeneration(playerRow, playerColumn, enemyRow, enemyColumn);

    // Get player input and move
    playerMovement(playerRow, playerColumn);

    }
}
else{
    cout << "THANKS";
}



    return 0;
}


// =========================
// PLAYER MOVEMENT
// =========================

void playerMovement(int& playerRow, int& playerColumn) {
    char input = _getch();

    switch(input) {

        case 'W':
        case 'w':
        if(playerRow > 1) {
            playerRow--;
        }
            break;

        case 'S':
        case 's':
        if(playerRow < MAP_HEIGHT - 2){
            playerRow++;}
            break;

        case 'A':
        case 'a':
        if (playerColumn > 1){
            playerColumn--;}
            break;

        case 'D':
        case 'd':
        if (playerColumn < MAP_WIDTH - 2){
            playerColumn++;}
            break;

        default:
            cout << "Invalid Input";
    }
}


// =========================
// MAP GENERATION
// =========================

void mapGeneration(int playerRow, int playerColumn, int enemyRow, int enemyColumn) {

    for (int row = 0; row < MAP_HEIGHT; row++) {

        for (int column = 0; column < MAP_WIDTH; column++) {

            // Player
            if (row == playerRow && column == playerColumn) {
                cout << "@";
            }

            // Enemy
            else if (row == enemyRow && column == enemyColumn) {
                cout << "E";
            }

            // Walls
            else if (row == 0 || row == MAP_HEIGHT - 1 ||
                    column == 0 || column == MAP_WIDTH - 1) {
                cout << "#";
            }

            // Empty space
            else {
                cout << " ";
            }
        }

        cout << '\n';
    }
}


void enemyRespawn(int& score, int playerRow, int playerColumn, int& enemyRow, int& enemyColumn){

    if (playerRow == enemyRow && playerColumn == enemyColumn){
        score++;
        enemyRow = -1;
        enemyColumn = -1;
    }

    if (enemyRow == -1 && enemyColumn == -1){
        randomPair(enemyRow, enemyColumn);
    }
}


void randomPair(int& randnumX, int& randnumY){

    randnumX = rand() % (MAP_HEIGHT - 2) + 1;
    randnumY = rand() % (MAP_WIDTH - 2) + 1;
}