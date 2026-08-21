#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
// =====================================================
// FUNCTION DECLARATIONS
// =====================================================

bool loadMap();

void chaserMovement(
    int& chaserRow,
    int& chaserColumn,
    int playerRow,
    int playerColumn
);

void playerReset(
    int& score,
    int& playerRow,
    int& playerColumn,
    int& chaserRow,
    int& chaserColumn
);

void mapGenerator(
    int playerRow,
    int playerColumn,
    int enemyRow,
    int enemyColumn,
    int chaserRow,
    int chaserColumn
);

void randomPair(
    int& randnumWidth,
    int& randnumHeight
);

void playerMovement(
    int& playerRow,
    int& playerColumn
);

void enemyRespawn(
    int& score,
    int& playerRow,
    int& playerColumn,
    int& enemyRow,
    int& enemyColumn
);

void chaserRespawn(
    int& chaserRow,
    int& chaserColumn,
    int playerRow,
    int playerColumn,
    int enemyRow,
    int enemyColumn
);

void chaserCooldown(
    int playerRow,
    int playerColumn,
    int& chaserRow,
    int& chaserColumn,
    int& chaserTimer
);


// constants

const int MAP_WIDTH = 30;
const int MAP_HEIGHT = 10;


// map generation

char map[MAP_HEIGHT][MAP_WIDTH + 1];


// main gameplay loop

int main() {

    srand(time(NULL));

    // Load map from text file
    if (!loadMap()) {
        return 1;
    }

    int score = 0;

    int chaserRow = 7;
    int chaserColumn = 20;

    int enemyRow;
    int enemyColumn;

    int chaserTimer = 0;

    int playerRow = 2;
    int playerColumn = 5;

    char userChoice;


// first spawn enemy

    randomPair(enemyColumn, enemyRow);


    // Prevent enemy from spawning on player
    while (
        enemyRow == playerRow &&
        enemyColumn == playerColumn
    ) {

        randomPair(enemyColumn, enemyRow);
    }


//display

    std::cout
        << "============================= MOVEMENT SIMULATOR =====================================\n";

    std::cout << "Press Y to play, N to exit: ";

    std::cin >> userChoice;


// the actual game loop

    if (userChoice == 'y' || userChoice == 'Y') {

        while (true) {

            // Hide cursor
            std::cout << "\033[?25l";

            // Clear screen
            std::cout << "\033[2J\033[H";


            // Display score
            std::cout << "Score: "
                    << score
                      << "\n\n";


            // Generate map
            mapGenerator(
                playerRow,
                playerColumn,
                enemyRow,
                enemyColumn,
                chaserRow,
                chaserColumn
            );


// player movement mechanics

            playerMovement(
                playerRow,
                playerColumn
            );


                // chaser cooldown

            chaserCooldown(
                playerRow,
                playerColumn,
                chaserRow,
                chaserColumn,
                chaserTimer
            );




            playerReset(
                score,
                playerRow,
                playerColumn,
                chaserRow,
                chaserColumn
            );




            chaserRespawn(
                chaserRow,
                chaserColumn,
                playerRow,
                playerColumn,
                enemyRow,
                enemyColumn
            );



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


// map loading

bool loadMap() {

    std::ifstream file("../map.txt");


    if (!file) {

        std::cout << "Could not open map.txt\n";

        return false;
    }


    for (int row = 0; row < MAP_HEIGHT; row++) {

        file.getline(
            map[row],
            MAP_WIDTH + 1
        );


        if (file.fail()) {

            std::cout << "Error reading map.txt\n";

            return false;
        }


        // Check map width
        if (std::strlen(map[row]) != MAP_WIDTH) {

            std::cout
                << "Error: Row "
                << row
                << " does not contain exactly "
                << MAP_WIDTH
                << " characters.\n";

            return false;
        }
    }


    file.close();

    return true;
}


// enemy spawner

void enemyRespawn(
    int& score,
    int& playerRow,
    int& playerColumn,
    int& enemyRow,
    int& enemyColumn
) {

    // Player touched enemy
    if (
        playerRow == enemyRow &&
        playerColumn == enemyColumn
    ) {

        score++;

        // Remove enemy temporarily
        enemyRow = -1;
        enemyColumn = -1;
    }


    // Spawn a new enemy
    if (
        enemyRow == -1 &&
        enemyColumn == -1
    ) {

        do {

            randomPair(
                enemyColumn,
                enemyRow
            );

        }

        while (
            enemyRow == playerRow &&
            enemyColumn == playerColumn
        );
    }
}


//player movement
void playerMovement(
    int& playerRow,
    int& playerColumn
) {

    char input = _getch();


    switch (input) {

        case 'W':
        case 'w':

            if (
                map[playerRow - 1][playerColumn] != '#'
            ) {

                playerRow--;
            }

            break;


        case 'S':
        case 's':

            if (
                map[playerRow + 1][playerColumn] != '#'
            ) {

                playerRow++;
            }

            break;


        case 'A':
        case 'a':

            if (
                map[playerRow][playerColumn - 1] != '#'
            ) {

                playerColumn--;
            }

            break;


        case 'D':
        case 'd':

            if (
                map[playerRow][playerColumn + 1] != '#'
            ) {

                playerColumn++;
            }

            break;


        default:

            break;
    }
}


// map generator

void mapGenerator(
    int playerRow,
    int playerColumn,
    int enemyRow,
    int enemyColumn,
    int chaserRow,
    int chaserColumn
) {

    for (int row = 0; row < MAP_HEIGHT; row++) {

        for (int column = 0; column < MAP_WIDTH; column++) {

            // Player
            if (
                row == playerRow &&
                column == playerColumn
            ) {

                std::cout << '@';
            }


            // Enemy
            else if (
                row == enemyRow &&
                column == enemyColumn
            ) {

                std::cout << 'E';
            }


            // Chaser
            else if (
                row == chaserRow &&
                column == chaserColumn
            ) {

                std::cout << 'C';
            }


            // Map
            else {

                std::cout << map[row][column];
            }
        }

        std::cout << '\n';
    }
}


// random coordinates generator

void randomPair(
    int& randnumWidth,
    int& randnumHeight
) {

    do {

        randnumWidth =
            rand() % (MAP_WIDTH - 2) + 1;

        randnumHeight =
            rand() % (MAP_HEIGHT - 2) + 1;

    }

    while (
        map[randnumHeight][randnumWidth] == '#'
    );
}


// resets the player

void playerReset(
    int& score,
    int& playerRow,
    int& playerColumn,
    int& chaserRow,
    int& chaserColumn
) {

    // Chaser touches player
    if (
        chaserRow == playerRow &&
        chaserColumn == playerColumn
    ) {

        score = 0;

        playerRow = 2;
        playerColumn = 5;
    }


    // Player touches x
    if (
        map[playerRow][playerColumn] == 'x'
    ) {

        score = 0;

        playerRow = 2;
        playerColumn = 5;
    }
}


//chaser movement

void chaserMovement(
    int& chaserRow,
    int& chaserColumn,
    int playerRow,
    int playerColumn
) {

    // Move vertically
    if (
        chaserRow < playerRow &&
        map[chaserRow + 1][chaserColumn] != '#'
    ) {

        chaserRow++;
    }

    else if (
        chaserRow > playerRow &&
        map[chaserRow - 1][chaserColumn] != '#'
    ) {

        chaserRow--;
    }


    // Move horizontally
    else if (
        chaserColumn < playerColumn &&
        map[chaserRow][chaserColumn + 1] != '#'
    ) {

        chaserColumn++;
    }

    else if (
        chaserColumn > playerColumn &&
        map[chaserRow][chaserColumn - 1] != '#'
    ) {

        chaserColumn--;
    }
}


// chaser respawner

void chaserRespawn(
    int& chaserRow,
    int& chaserColumn,
    int playerRow,
    int playerColumn,
    int enemyRow,
    int enemyColumn
) {

    // Chaser touches x
    if (
        map[chaserRow][chaserColumn] == 'x'
    ) {

        chaserRow = -1;
        chaserColumn = -1;
    }


    // Spawn new chaser
    if (
        chaserRow == -1 &&
        chaserColumn == -1
    ) {

        do {

            randomPair(
                chaserColumn,
                chaserRow
            );

        }

        while (

            (chaserRow == playerRow &&
             chaserColumn == playerColumn)

            ||

            (chaserRow == enemyRow &&
             chaserColumn == enemyColumn)
        );
    }
}


// gives time for players to rest
void chaserCooldown(
    int playerRow,
    int playerColumn,
    int& chaserRow,
    int& chaserColumn,
    int& chaserTimer
) {

    chaserTimer++;


    // Chaser moves every 3 turns
    if (chaserTimer >= 3) {

        chaserMovement(
            chaserRow,
            chaserColumn,
            playerRow,
            playerColumn
        );

        chaserTimer = 0;
    }
}
// shoutout to my baby josaine!