#include <iostream>


int main() {

    std::string questions[] = {
    "1. What is the correct extension for a C++ source file?",
    "2. Which symbol is used to end a C++ statement?",
    "3. Which data type is used to store whole numbers?",
    "4. Which keyword is used to create a variable that cannot be changed?",
    "5. Which operator is used for addition?"
};

std::string options[][4] = {
    {"A. .py", "B. .cpp", "C. .java", "D. .html"},
    {"A. :", "B. .", "C. ;", "D. ,"},
    {"A. double", "B. string", "C. int", "D. char"},
    {"A. fixed", "B. const", "C. static", "D. final"},
    {"A. +", "B. -", "C. *", "D. /"}
};
int size = sizeof(questions)/sizeof(questions[0]);
int optionSize = sizeof(options[0])/sizeof(options[0][0]);

char answerKey[] = {'B', 'C', 'C', 'B', 'A'};
char guess;
int score = 0;

for(int i = 0; i < size; i++){
    std:: cout << "===================================================\n";
    std:: cout << questions[i] << '\n';
    std:: cout << "===================================================\n";

        for (int j = 0; j < optionSize; j++)
        {   
            std::cout << options[i][j] << '\n';
            
        }
    std:: cout << "Choose a letter: ";
    std:: cin >> guess;
    if(guess == answerKey[i]){
        score++;
    }
}

std:: cout << "Your Score: " << score << "/ "<< size << '\n'; 
if(score == 5){
    std:: cout << "You got a perfect score!\n";
}

else{
std:: cout << "The correct answers are: \n";
for(int i = 0; i < size; i++){
    std :: cout << i + 1<< "." << answerKey[i]<< '\n';
}
}

return 0;
}
