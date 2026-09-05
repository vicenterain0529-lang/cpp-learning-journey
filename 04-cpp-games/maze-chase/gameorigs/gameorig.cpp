#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>

void mapGenerator(int playerRow, int playerColumn, int enemyRow, int enemyColumn);
void randomPair(int& randnumWidth, int& randnumHeight);
void playerMovement(int& playerRow, int& playerColumn);
void enemyRespawn(
    int& score,
    int& playerRow,
    int& playerColumn,
    int& enemyRow,
    int& enemyColumn
);

const int MAP_WIDTH = 30;
const int MAP_HEIGHT = 10;

int main() {

    srand(time(NULL));

    int score = 0;

    int enemyRow;
    int enemyColumn;

    int playerRow = 2;
    int playerColumn = 5;

    char userChoice;

    // Initial enemy spawn
    randomPair(enemyColumn, enemyRow);

    // Prevent enemy from spawning on player
    while (enemyRow == playerRow && enemyColumn == playerColumn) {
        randomPair(enemyColumn, enemyRow);
    }

    std::cout << "============================= MOVEMENT SIMULATOR =====================================\n";
    std::cout << "Press Y to play, N to exit: ";
    std::cin >> userChoice;

    if (userChoice == 'y' || userChoice == 'Y') {

        while (true) {

            // Clear screen
            std::cout << "\033[2J\033[H";

            // Display score
            std::cout << "Score: " << score << "\n\n";

            // Generate map
            mapGenerator(
                playerRow,
                playerColumn,
                enemyRow,
                enemyColumn
            );

            // Player movement
            playerMovement(playerRow, playerColumn);

            // Check collision and respawn enemy
            enemyRespawn(
                score,
                playerRow,
                playerColumn,
                enemyRow,
                enemyColumn
            );
        }
    }
    else {
        std::cout << "Thanks for playing!\n";
    }

    return 0;
}


// =====================================================
// ENEMY RESPAWN
// =====================================================

void enemyRespawn(
    int& score,
    int& playerRow,
    int& playerColumn,
    int& enemyRow,
    int& enemyColumn
) {

    // Player touched enemy
    if (playerRow == enemyRow && playerColumn == enemyColumn) {

        score++;

        // Remove enemy temporarily
        enemyRow = -1;
        enemyColumn = -1;
    }

    // Spawn a new enemy
    if (enemyRow == -1 && enemyColumn == -1) {

        do {
            randomPair(enemyColumn, enemyRow);

        } while (
            enemyRow == playerRow &&
            enemyColumn == playerColumn
        );
    }
}


// =====================================================
// PLAYER MOVEMENT
// =====================================================

void playerMovement(int& playerRow, int& playerColumn) {

    char input = _getch();

    switch (input) {

        case 'W':
        case 'w':

            if (playerRow > 1) {
                playerRow--;
            }

            break;


        case 'S':
        case 's':

            if (playerRow < MAP_HEIGHT - 2) {
                playerRow++;
            }

            break;


        case 'A':
        case 'a':

            if (playerColumn > 1) {
                playerColumn--;
            }

            break;


        case 'D':
        case 'd':

            if (playerColumn < MAP_WIDTH - 2) {
                playerColumn++;
            }

            break;


        default:

            break;
    }
}


// =====================================================
// MAP GENERATOR
// =====================================================

void mapGenerator(
    int playerRow,
    int playerColumn,
    int enemyRow,
    int enemyColumn
) {

    for (int row = 0; row < MAP_HEIGHT; row++) {

        for (int column = 0; column < MAP_WIDTH; column++) {

            // Player
            if (
                row == playerRow &&
                column == playerColumn
            ) {

                std::cout << "@";
            }

            // Enemy
            else if (
                row == enemyRow &&
                column == enemyColumn
            ) {

                std::cout << "E";
            }

            // Border
            else if (
                row == 0 ||
                row == MAP_HEIGHT - 1 ||
                column == 0 ||
                column == MAP_WIDTH - 1
            ) {

                std::cout << "#";
            }

            // Empty space
            else {

                std::cout << " ";
            }
        }

        std::cout << "\n";
    }
}


// =====================================================
// RANDOM POSITION GENERATOR
// =====================================================

void randomPair(
    int& randnumWidth,
    int& randnumHeight
) {

    randnumWidth =
        rand() % (MAP_WIDTH - 2) + 1;

    randnumHeight =
        rand() % (MAP_HEIGHT - 2) + 1;
}