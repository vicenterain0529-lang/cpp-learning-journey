#include "StudentApplication.h"
#include <iostream>

// CONSTRUCTORS
StudentApplication :: StudentApplication(
    int studentid,  
    int examscore,
    int Average,
    int attendance,
    int course,
    int famIncome, 
    int intScore ){

        studentId = studentid;
        examScore = examscore;
        generalAverage = Average;
        attendancePercent = attendance;
        courseCode = course;
        familyIncome = famIncome;
        interviewScore = intScore;
    }
//============================
//  GETTERS
// =========================

int StudentApplication::getStudentId() { return studentId; }
int StudentApplication::getExamScore() { return examScore; }
int StudentApplication::getGeneralAverage() { return generalAverage; }
int StudentApplication::getAttendancePercent() { return attendancePercent; }
int StudentApplication::getCourseCode() { return courseCode; }
int StudentApplication::getFamilyIncome() { return familyIncome; }
int StudentApplication::getInterviewScore() { return interviewScore; }

//          METHODS
std::string StudentApplication::calcAverage() {
    if (generalAverage >= 95) { return "EXCELLENT"; } 
    else if (generalAverage >= 90) { return "VERY GOOD"; } 
    else if (generalAverage >= 85) { return "GOOD"; } 
    else if (generalAverage >= 80) { return "SATISFACTORY"; } 
    else { return "NEEDS IMPROVEMENT"; } 
}

std::string StudentApplication::attendanceResults() { 
    if (attendancePercent >= 95) { return "EXCELLENT ATTENDANCE"; } 
    else { return "REGULAR ATTENDANCE"; }
}

std::string StudentApplication::courseResults() { 
    switch(courseCode) { 
        case 1: return "Computer Engineering"; 
        case 2: return "Civil Engineering"; 
        case 3: return "Electrical Engineering"; 
        case 4: return "Mechanical Engineering"; 
        case 5: return "Electronics Engineering"; 
        default: return "Invalid Course"; 
    } 
}

std::string StudentApplication::admissionResults() { 
    if (generalAverage >= 85 && examScore >= 75 && attendancePercent >= 90) { 
        return "ADMITTED"; 
    } else if (generalAverage >= 75) { 
        return "WAITLISTED"; 
    } else { 
        return "REJECTED"; 
    }
}

std::string StudentApplication::examResults() { 
    if (examScore >= 75) { return "PASSED"; } 
    else { return "FAILED"; } 
}

std::string StudentApplication::scholarshipState() { 
    if (generalAverage >= 90 && examScore >= 85) { 
        if (familyIncome <= 20000) { return "FULL SCHOLARSHIP"; } 
        else if (familyIncome <= 40000) { return "PARTIAL SCHOLARSHIP"; } 
        else { return "NO SCHOLARSHIP"; } 
    } else { return "NOT QUALIFIED"; } 
}

std::string StudentApplication::recommendationState() { 
    std::string currentAdmissionStatus = admissionResults();

    if (currentAdmissionStatus == "ADMITTED") { 
        if (generalAverage >= 90 && examScore >= 85 && interviewScore >= 85) { 
            if (familyIncome <= 20000) { return "HIGHLY RECOMMENDED"; }
            else if (familyIncome <= 40000) { return "RECOMMENDED"; }
            else { return "ADMITTED"; } 
        } else { return "ADMITTED"; } 
    } 
    else if (currentAdmissionStatus == "WAITLISTED") { return "FOR FURTHER EVALUATION"; }
    else { return "NOT RECOMMENDED"; }
}

void StudentApplication::printEvaluation() {
    std::cout << "=============== STUDENT EVALUATION ===============\n\n";
    std::cout << "Student ID: " << studentId << '\n';
    std::cout << "Course: " << courseResults() << "\n\n";
    std::cout << "Entrance Exam: " << examScore << '\n';
    std::cout << "Status: " << examResults() << "\n\n";
    std::cout << "General Average: " << generalAverage << '\n';
    std::cout << "Classification: " << calcAverage() << "\n\n";
    std::cout << "Attendance: " << attendancePercent << "%\n";
    std::cout << "Status: " << attendanceResults() << "\n\n";
    std::cout << "Interview Score: " << interviewScore << "\n\n";
    std::cout << "Admission Status: " << admissionResults() << "\n\n";
    std::cout << "Scholarship Status: " << scholarshipState() << "\n\n";
    std::cout << "Recommendation: " << recommendationState() << "\n\n";
    std::cout << "=============== END OF EVALUATION ===============\n";
}