#include "RegistrationSystem.h"
#include <iostream>

RegistrationSystem:: RegistrationSystem(){}

// methods
    

void RegistrationSystem::addStudent(Student student){
    students.emplace_back(student);
}
void RegistrationSystem::addCourse(Course course){
    courses.emplace_back(course);
}
Student* RegistrationSystem:: findStudent(int studentID){
    for(auto i = 0u; i < students.size(); i++){
        if(students[i].getStudentID() == studentID){
            return &students[i];
        }
        
    }
    return nullptr;
}
Course* RegistrationSystem:: findCourse(std::string courseCode){
for(auto i = 0u; i < courses.size(); i++){
    if(courses[i].getCourseCode() == courseCode){
        return &courses[i];
    }
}
return nullptr;
}

void RegistrationSystem:: registerStudent(int studentID, std:: string courseCode){
    Student* studentAddress = findStudent(studentID);
    if (studentAddress == nullptr){
        std::cout << "ERROR! STUDENT NOT FOUND\n";
        return;

}
Course* courseAddress = findCourse(courseCode);
    if (courseAddress == nullptr){
        std::cout << "ERROR! COURSE NOT FOUND\n";
        return;
}

if(studentAddress-> getGPA() < courseAddress -> getMinGPA()){
    std:: cout << "STUDENT FAILS TO MEET MINIMUM GPA STANDARD\n"<< "STUDENT REJECTED\n";
    return;
}
if(!courseAddress-> checkPrerequisites(*studentAddress)){
    std::cout << "PREREQUISITES NOT MET\n";
    return;
}
if(!courseAddress-> hasAvailableSeat()){
    std:: cout << "COURSE IS FULL\n";
    return;
}
if (studentAddress->enrollmentChecker(courseCode)){
    std::cout << "STUDENT ALREADY ENROLLED\n";
    return;
}
courseAddress -> addStudent(*studentAddress);
studentAddress -> addCurrentEnroll(courseCode);
std:: cout << "SUCCESSFULLY REGISTERED\n";
}