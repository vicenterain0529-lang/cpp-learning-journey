#include "Student.h"
#include <string>
#include <vector>
#include "course.h"
#include <iostream>

Course::Course(
    std::string subCourseCode,
    std::string subCourseTitle,
    int subMaxSeats,
    double subMinGPA
)
{
    courseCode = subCourseCode;
    courseTitle = subCourseTitle;
    maxSeats = subMaxSeats;
    minGPA = subMinGPA;
}



// Getters
// ===================

std::string Course::getCourseCode() const
{
    return courseCode;
}

std::string Course::getCourseTitle() const
{
    return courseTitle;
}

int Course::getMaxSeats() const
{
    return maxSeats;
}

double Course::getMinGPA() const
{
    return minGPA;
}

std::vector<std::string> Course::getPrerequisites() const
{
    return prerequisites;
}

std::vector<Student> Course::getStudentList() const
{
    return studentList;
}



//setters
void Course:: setCourseCode(std::string newCourseCode)
{
    courseCode = newCourseCode;


};
void Course:: setMinGPA(double newMinGPA)
{
    minGPA = newMinGPA;
}

// Methods

void Course::addPrerequisite(std::string prerequisite)
{
    prerequisites.emplace_back(prerequisite);
}

bool Course::checkPrerequisites(Student student) const
{
   for(std::string prerequisite : prerequisites){
    if(!student.courseChecker(prerequisite)){
        return false;
    }
}return true;
}

void Course::addStudent(Student student)
{
    studentList.emplace_back(student);
}

bool Course::hasAvailableSeat() const
{
    if(studentList.size() >=  maxSeats){
        return false;
    }else{
        return true;
    }
}

void Course::displayRoster() const
{
    for(auto i = 0u; i < studentList.size(); i++ ){
        std:: cout<< i+1<< ". "<< studentList[i].getStudentName() << '\n';
        
    }
}