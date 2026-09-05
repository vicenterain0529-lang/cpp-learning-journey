#include <iostream>
#include <ctime>
using namespace std;


// Function prototypes
int rockRoll();

void scoreCount(int userScore, int enemyScore);

void victoryCheck(int enemyRoll, int userChoice,
                  int& userScore, int& enemyScore);

void playerChoice(int userChoice);

void enemyChoice(int enemyRoll);


int main() {
    srand(time(NULL));

    int userChoice;
    int userScore = 0;
    int enemyScore = 0;
    char play;

    while (true) {

        cout << "Do you want to play rock, paper, scissors? (y/n): ";

        if (!(cin >> play)) {
            cout << "Use valid characters!";
            cin.clear();
            cin.ignore(100000, '\n');
            continue;
        }

        switch (play) {

            case 'Y':
            case 'y':

                while (true) {

                    int enemyRoll = rockRoll();

                    cout << "======================== ROCK PAPER SCISSORS ========================\n";
                    cout << "1. ROCK\n";
                    cout << "2. PAPER\n";
                    cout << "3. SCISSORS\n";
                    cout <<"4. Exit\n";
                    cout << "Choose your move! ";
                    cin >> userChoice;
                    if (userChoice < 1 || userChoice > 4) {
                        cout << "Invalid choice! Use 1-4.\n";
                                continue;
                                                            }
                    if(userChoice== 4){
                        break;
                    }
                    playerChoice(userChoice);
                    enemyChoice(enemyRoll);

                    victoryCheck(enemyRoll, userChoice,
                                userScore, enemyScore);

                    scoreCount(userScore, enemyScore);
                }

                break;


            case 'N':
            case 'n':
                cout << "Thanks! Play again next time.";
                return 0;


            default:
                cout << "Please enter Y or N.\n";
                break;
        }
    }

}

int rockRoll() {
    return rand() % 3 + 1;
}


void scoreCount(int userScore, int enemyScore) {
    cout << "Your Score: " << userScore << '\n';
    cout << "Enemy Score: " << enemyScore << '\n';
}


void victoryCheck(int enemyRoll, int userChoice,
        int& userScore, int& enemyScore) {

    // DRAW
    if (enemyRoll == 1 && userChoice == 1) {
        cout << "You both chose ROCK!\n";
        cout << "It's a DRAW!\n";
    }
    else if (enemyRoll == 2 && userChoice == 2) {
        cout << "You both chose PAPER!\n";
        cout << "It's a DRAW!\n";
    }
    else if (enemyRoll == 3 && userChoice == 3) {
        cout << "You both chose SCISSORS!\n";
        cout << "It's a DRAW!\n";
    }

    // PLAYER WINS
    else if (userChoice == 1 && enemyRoll == 3) {
        cout << "ROCK beats SCISSORS!\n";
        cout << "YOU WIN!\n";
        userScore++;
    }
    else if (userChoice == 2 && enemyRoll == 1) {
        cout << "PAPER beats ROCK!\n";
        cout << "YOU WIN!\n";
        userScore++;
    }
    else if (userChoice == 3 && enemyRoll == 2) {
        cout << "SCISSORS beats PAPER!\n";
        cout << "YOU WIN!\n";
        userScore++;
    }

    // PLAYER LOSES
    else if (enemyRoll == 1 && userChoice == 3) {
        cout << "ROCK beats SCISSORS!\n";
        cout << "YOU LOSE!\n";
        enemyScore++;
    }
    else if (enemyRoll == 2 && userChoice == 1) {
        cout << "PAPER beats ROCK!\n";
        cout << "YOU LOSE!\n";
        enemyScore++;
    }
    else if (enemyRoll == 3 && userChoice == 2) {
        cout << "SCISSORS beats PAPER!\n";
        cout << "YOU LOSE!\n";
        enemyScore++;
    }
}


void playerChoice(int userChoice) {

    switch (userChoice) {

        case 1:
            cout << "You chose ROCK!\n";
            cout << R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)";
            break;

        case 2:
            cout << "You chose PAPER!\n";
            cout << R"(
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
)";
            break;

        case 3:
            cout << "You chose SCISSORS!\n";
            cout << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)";
            break;

        default:
            cout << "Invalid Choice! Use only (1-3)\n";
    }
}


void enemyChoice(int enemyRoll) {

    switch (enemyRoll) {

        case 1:
            cout << "The enemy chose ROCK!\n";
            cout << R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)";
            break;

        case 2:
            cout << "The enemy chose PAPER!\n";
            cout << R"(
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
)";
            break;

        case 3:
            cout << "The enemy chose SCISSORS!\n";
            cout << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)";
            break;

        default:
            cout << "Invalid Choice! Use only (1-3)\n";
    }
}