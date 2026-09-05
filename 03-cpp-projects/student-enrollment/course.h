#pragma once
#include "Student.h"
#include <string>
#include <vector>


class Course{
    private:   

    std::string courseCode;
    std:: string courseTitle;
    int maxSeats;
    double minGPA;
    std::vector<std::string> prerequisites;
    std:: vector<Student> studentList;

public:
// constructor
Course(std:: string subCourseCode, std:: string subCourseTitle, int subMaxSeats, double subMinGPA);



// getters
//===================
std::string getCourseCode()const;
std:: string getCourseTitle()const;
int getMaxSeats()const;
double getMinGPA()const;
std::vector<std::string> getPrerequisites()const;
std::vector<Student> getStudentList()const;


//setters
void setCourseCode(std::string newCourseCode);
void setMinGPA(double newMinGPA);




// methods
void addPrerequisite(std::string prerequisite);
bool checkPrerequisites(Student student) const;

void addStudent(Student student);
bool hasAvailableSeat()const;
void displayRoster()const;


};