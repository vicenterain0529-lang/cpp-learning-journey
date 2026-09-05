#include <iostream>
#include <limits>
#include <cctype>
#include <string>

class Human{
    private:
    std:: string name;
    std:: string occupation;
    int age;
    public:
    
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
    std::string getName(){
        return name;
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
    public:

Warrior(std:: string n, std:: string oc, int a) : Human(n, oc, a){

}
    void warriorSlash(){
        std::cout << "The warrior " << getName() << " has attacked with his sword\n";
    }


};


int main(){
    Warrior warrior1("Rain", "Warrior", 18);
    warrior1.eat();
    warrior1.statusShow();
    warrior1.warriorSlash();
}