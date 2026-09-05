#include <iostream> 
#include <vector>
#include <limits>


struct Student{
    std:: string name;
    double gpa;
    bool isEnrolled;

    Student(std::string n, double g, bool enrolled){
        name = n;
        gpa = g;
        isEnrolled = enrolled;
    }


    void studentData(){
        std::string enrollmentState = (isEnrolled) ? "ENROLLED\n" : "NOT ENROLLED\n";
        std:: cout << "Student Name: " << name << '\n';
        std:: cout << "GPA: "<< gpa << '\n';
        std:: cout << "ENROLLMENT STATUS: "<< enrollmentState;
    }
};


void gpaValidator(double& gpa);
void studentCreate(std::vector<Student>& studentList);
void showMenu(std::vector<Student>& studentList);
void menuHandler(std::vector<Student>& studentList, int choice);
void mainMenu(std::vector<Student>& studentList);


int main(){
    std::vector<Student> studentList;

    mainMenu(studentList);
}


void gpaValidator(double& gpa){

    do{ 
        std:: cin >> gpa;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid GPA. Try again: \n";
        }
    
    }while(std:: cin.fail());
}


void studentCreate(std::vector<Student>& studentList){

    int numofStudents;

    std:: cout << "Student List Size: "<< '\n';
    std:: cin >> numofStudents;
    std:: cin.ignore();

    for(int i = 0; i < numofStudents; i++){
        std:: string name;
        double gpa;
        bool isEnrolled;

        std:: cout << "Enter Student Name: \n";
        std:: getline(std::cin, name);

        std:: cout << "Enter Student GPA: \n";
        gpaValidator(gpa);

        std:: cout <<"Enrollment Status: (1/0) ";
        std::cin >> isEnrolled;
        std:: cin.ignore();

        studentList.emplace_back(name,gpa,isEnrolled);
    }
}


void showMenu(std::vector<Student>& studentList){

    std::cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Show Students\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}


void menuHandler(std::vector<Student>& studentList, int choice){

    switch(choice){

        case 1: 
            studentCreate(studentList);
            break;

        case 2:
            for(Student& student : studentList){
                student.studentData();
                std::cout << '\n';
            }
            break;

        case 3:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
    }
}


void mainMenu(std::vector<Student>& studentList){

    int choice;

    while(true){

        showMenu(studentList);

        std::cin >> choice;

        menuHandler(studentList, choice);

        if(choice == 3){
            break;
        }
    }
}