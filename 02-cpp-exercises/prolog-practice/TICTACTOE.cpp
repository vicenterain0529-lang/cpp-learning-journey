#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(){
  srand(time(NULL));
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    srand(time(0));

    while(running){

        drawBoard(spaces);

        playerMove(spaces, player);

        if(checkWinner(spaces, player, computer)){
            drawBoard(spaces);
            std::cout << "You win!\n";
            running = false;
            break;
        }

        if(checkTie(spaces)){
            drawBoard(spaces);
            std::cout << "It's a tie!\n";
            running = false;
            break;
        }

        computerMove(spaces, computer);

        if(checkWinner(spaces, player, computer)){
            drawBoard(spaces);
            std::cout << "Computer wins!\n";
            running = false;
            break;
        }

        if(checkTie(spaces)){
            drawBoard(spaces);
            std::cout << "It's a tie!\n";
            running = false;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces){

    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    std::cout << "_____|_____|_____\n";

    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    std::cout << "_____|_____|_____\n";

    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    std::cout << "     |     |     \n";
}

void playerMove(char *spaces, char player){

    int number;

    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;

        if(number < 1 || number > 9){
            std::cout << "Invalid spot!\n";
        }
        else{

            number--;

            if(spaces[number] == ' '){
                spaces[number] = player;
                break;
            }
            else{
                std::cout << "That spot is already taken!\n";
            }
        }

    }while(true);
}

void computerMove(char *spaces, char computer){
int random_value = rand() % 9;
if(spaces[random_value] == ' '){
    spaces[random_value] = 'computer';
    
}
}

bool checkWinner(char *spaces, char player, char computer){

}

bool checkTie(char *spaces){

    for(int i = 0; i < 9; i++){

        if(spaces[i] == ' '){
            return false;
        }
    }

    return true;
}