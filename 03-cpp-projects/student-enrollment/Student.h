#pragma once

#include <string>
#include <vector>

class Student
{
private:
    int studentID;
    std::string studentName;
    double GPA;
    int completedCreds;

    std::vector<std::string> completedCourse;
    std::vector<std::string> currentCourse;

public:

    // Constructor
    Student(
        int studId,
        std::string studName,
        double studGPA,
        int compCreds
    );

    // Getters
    int getStudentID() const;
    std::string getStudentName() const;
    double getGPA() const;
    int getCompleteCreds() const;

    std::vector<std::string> getCompletedCourse() const;
    std::vector<std::string> getCurrentCourse() const;

    // Setters
    void setStudentGPA(double newGPA);
    void setStudentName(std::string newName);
    void setCredits(int newCompCreds);


    // Course methods
    void addCompletedCourse(std::string courseCode);
    void addCurrentEnroll(std::string enrolledSubs);


    // Checkers / validators
    bool courseChecker(std::string courseCode) const;
    bool enrollmentChecker(std::string enrolledCourse) const;
};