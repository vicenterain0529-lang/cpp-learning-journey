#include <iostream>
using namespace std;

int main(){

    int month;
    double average, english, math, science, biology;
    int userChoice;
    

    cout <<"Do you want to know your grade or type your birth month (Choose 1 or 2)?\n";
    cin >> userChoice;

    if(userChoice == 1){
        cout << "You chose to calculate your grade: \n";
        cout << " English Grade: \n";
        cin >> english;
        cout << "Math: \n";
        cin >> math;
        cout << "Science: \n";
        cin >> science;
        cout << "Biology:";
        cin >> biology;

        average = (english + math + science + biology) / 4;
        cout << "Your general average is: " << average << '\n';
    }
    





    

}