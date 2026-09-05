#include <iostream>
#include <string>
#include <vector>
#include "StudentApplication.h"


StudentApplication userInputs() { 
    int tempId, tempExam, tempAvg, tempAtt, tempCourse, tempIncome, tempInterview;

    std::cout << "Enter student ID: "; 
    std::cin >> tempId; 

    std::cout << "Enter student exam score (0-100): "; 
    std::cin >> tempExam; 

    std::cout << "Enter student General Average(0-100): "; 
    std::cin >> tempAvg; 

    std::cout << "Enter student attendance percentage (0-100): "; 
    std::cin >> tempAtt; 

    std::cout << "Enter family monthly income: "; 
    std::cin >> tempIncome; 

    std::cout << "\n"; 
    std::cout << "==================================================\n"; 
    std::cout << "||            SELECT YOUR COURSE                ||\n"; 
    std::cout << "==================================================\n"; 
    std::cout << "||  [1]  Computer Engineering                  ||\n"; 
    std::cout << "||  [2]  Civil Engineering                     ||\n"; 
    std::cout << "||  [3]  Electrical Engineering                ||\n"; 
    std::cout << "||  [4]  Mechanical Engineering                ||\n"; 
    std::cout << "||  [5]  Electronics Engineering               ||\n"; 
    std::cout << "==================================================\n\n"; 

    std::cout << "Enter course code (1-5): "; 
    std::cin >> tempCourse; 

    std::cout << "Enter interview score (0-100): "; 
    std::cin >> tempInterview; 


    return StudentApplication(tempId, tempExam, tempAvg, tempAtt, tempCourse, tempIncome, tempInterview);

}


int main() {
    std::vector<StudentApplication> allStudents;

    char userChoice;

    while (true) {

        StudentApplication currentStudent = userInputs();

        currentStudent.printEvaluation();

        // Store the student we just created
        allStudents.push_back(currentStudent);

        std::cout << "\n\n";
        std::cout << "Do you want to evaluate another student? (Y/N): ";
        std::cin >> userChoice;

        if (userChoice == 'Y' || userChoice == 'y') {
            continue;
        }
        else if (userChoice == 'N' || userChoice == 'n') {
            break;
        }
    }

    std::cout << "\n==================================================\n";
    std::cout << "               END OF DAY SUMMARY                 \n";
    std::cout << "==================================================\n";

    std::cout << "Total Students Evaluated: "
              << allStudents.size() << "\n\n";

    for (std::size_t i = 0; i < allStudents.size(); i++) {
        std::cout << "ID: " << allStudents[i].getStudentId()
                  << " | Status: " << allStudents[i].admissionResults()
                  << "\n";
    }

    std::cout << "\nGOOD BYE!\n";
}




