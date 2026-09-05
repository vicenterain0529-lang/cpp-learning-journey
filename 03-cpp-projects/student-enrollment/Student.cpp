#include "Student.h"
#include <iostream>

// Constructor
Student::Student(
    int studId,
    std::string studName,
    double studGPA,
    int compCreds
)
{
    studentID = studId;
    studentName = studName;
    GPA = studGPA;
    completedCreds = compCreds;
}


// Getters
int Student::getStudentID() const
{
    return studentID;
}

std::string Student::getStudentName() const
{
    return studentName;
}

double Student::getGPA() const
{
    return GPA;
}

int Student::getCompleteCreds() const
{
    return completedCreds;
}

std::vector<std::string> Student::getCompletedCourse() const
{
    return completedCourse;
}

std::vector<std::string> Student::getCurrentCourse() const
{
    return currentCourse;
}


// Setters
void Student::setStudentGPA(double newGPA)
{
    GPA = newGPA;
}

void Student::setStudentName(std::string newName)
{
    studentName = newName;
}

void Student::setCredits(int newCompCreds)
{
    completedCreds = newCompCreds;
}


// Course methods
void Student::addCompletedCourse(std::string courseCode)
{
    completedCourse.emplace_back(courseCode);

}

void Student::addCurrentEnroll(std::string enrolledSubs)
{
    currentCourse.emplace_back(enrolledSubs);
}


// Checkers / validators
bool Student::courseChecker(std::string courseCode) const
{
    for (std::string course : completedCourse)
    {
        if (course == courseCode)
        {
            return true;
        }
    }

    return false;
}

bool Student::enrollmentChecker(std::string enrolledCourse) const
{
for(std:: string course : currentCourse){
    if(course == enrolledCourse){return true;}
}
return false;
}