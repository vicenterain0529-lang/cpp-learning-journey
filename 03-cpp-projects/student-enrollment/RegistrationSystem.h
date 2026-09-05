#pragma once

#include "Student.h"
#include "Course.h"
#include <vector>
#include <string>

class RegistrationSystem
{
private:

    std:: vector<Student> students;
    std::vector<Course> courses;

public:

    // constructor
    RegistrationSystem();
    // methods
    void addStudent(Student student);
    void addCourse(Course course);
    Student* findStudent(int studentID);
    Course* findCourse(std::string courseCode);
    void registerStudent(int studentID, std:: string courseCode);
};