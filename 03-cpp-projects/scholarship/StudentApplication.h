#pragma once
#include <string>

class StudentApplication{
    private:

    int studentId;  
    int examScore; 
    int generalAverage;
    int attendancePercent;
    int courseCode;
    int familyIncome; 
    int interviewScore; 
//constructor variables
public:
    StudentApplication(
    int studentid,  
    int examscore,
    int Average,
    int attendance,
    int course,
    int famIncome, 
    int intScore );

    //getters
    int getStudentId();
    int getExamScore();
    int getGeneralAverage();
    int getAttendancePercent();
    int getCourseCode();
    int getFamilyIncome();
    int getInterviewScore();
    // methods;
    std::string calcAverage();
    std::string attendanceResults();
    std::string courseResults();
    std::string admissionResults();
    std::string examResults();
    std::string scholarshipState();
    std::string recommendationState();
    
    void printEvaluation();


};
