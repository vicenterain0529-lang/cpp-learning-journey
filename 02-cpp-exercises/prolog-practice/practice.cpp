#include <iostream>
#include <limits>
#include <cctype>
#include <string>

class Human{
    public:
    std:: string name;
    std:: string occupation;
    int age;

    Human(){
        name = "";
        occupation = "";
        age = 0;
    }

    Human(std:: string n, std:: string oc, int a){
        name = n;
        occupation = oc;
        age = a;
    }

    void eat(){
        std::cout << "This person is eating\n";
    }
    void drink(){
    std::cout << "This person is drinking\n";
    }

    void statusShow(){
        std:: cout << "Name: "<< name << '\n';
        std:: cout << "Occupation: "<< occupation << '\n';
        std:: cout << "Age: "<< age << '\n';
        
    }
};
class Warrior: public Human{

};


void showCharacters(Human characters[], int characterCount);
void characterCreate(Human characters[], int& characterCount);

int main(){
    Human characters[5];
    int characterCount = 0;
    characterCreate(characters, characterCount);
    showCharacters(characters, characterCount);


}
void characterCreate(Human characters[], int& characterCount){
    std:: string name;
    std:: string occupation;
    int age = 0;
std:: cout << "============= HUMAN CREATION ===============\n";
std:: cout << "What is the name of the human? ";
std:: getline(std::cin, name);


std:: cout << "Whats the occupation? ";
std:: getline(std::cin, occupation);


std:: cout << "How old is the Human? ";
std:: cin >> age;



characters[characterCount] = Human(name, occupation, age);
characterCount++;
}

void showCharacters(Human characters[], int characterCount){
    for(int i = 0; i < characterCount; i++){
        std:: cout << i + 1<< '.'<< " "<<  "Name: " << characters[i].name << '\n';
    }
}