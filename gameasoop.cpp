#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAP_WIDTH = 25;
const int MAP_HEIGHT = 10;


// =========================
// PLAYER
// =========================

class Player {

public:

    int row;
    int column;
    int score;

    Player(int startRow, int startColumn) {
        row = startRow;
        column = startColumn;
        score = 0;
    }

    void move() {

        char input = _getch();

        switch(input) {

            case 'W':
            case 'w':
                if(row > 1)
                    row--;
                break;

            case 'S':
            case 's':
                if(row < MAP_HEIGHT - 2)
                    row++;
                break;

            case 'A':
            case 'a':
                if(column > 1)
                    column--;
                break;

            case 'D':
            case 'd':
                if(column < MAP_WIDTH - 2)
                    column++;
                break;
        }
    }
};


// =========================
// ENEMY
// =========================

class Enemy {

public:

    int row;
    int column;

    Enemy() {
        respawn();
    }

    void respawn() {

        row = rand() % (MAP_HEIGHT - 2) + 1;
        column = rand() % (MAP_WIDTH - 2) + 1;
    }
};


// =========================
// MAP GENERATION
// =========================

void mapGeneration(Player& player, Enemy& enemy) {

    for(int row = 0; row < MAP_HEIGHT; row++) {

        for(int column = 0; column < MAP_WIDTH; column++) {

            // Player
            if(row == player.row && column == player.column) {
                cout << "@";
            }

            // Enemy
            else if(row == enemy.row && column == enemy.column) {
                cout << "E";
            }

            // Walls
            else if(row == 0 || row == MAP_HEIGHT - 1 ||
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


// =========================
// MAIN
// =========================

int main() {

    srand(time(NULL));

    Player player(2, 5);
    Enemy enemy;


    while(true) {

        // Clear terminal
        cout << "\033[2J\033[H";

        // Check if player eats enemy
        if(player.row == enemy.row &&
           player.column == enemy.column) {

            player.score++;

            enemy.respawn();
        }

        cout << "Score: " << player.score << "\n\n";

        // Draw map
        mapGeneration(player, enemy);

        // Move player
        player.move();
    }

    return 0;
}