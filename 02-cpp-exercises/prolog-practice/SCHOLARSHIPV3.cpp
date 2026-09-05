#include <iostream>
#include <string>
#include <vector>
class StudentApplication{
    private:

    int studentId;  
    int examScore; 
    int generalAverage;
    int attendancePercent;
    int courseCode;
    int familyIncome; 
    int interviewScore; 

public:
    StudentApplication(
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

int getStudentId() {
    return studentId;
}

int getExamScore() {
    return examScore;
}

int getGeneralAverage() {
    return generalAverage;
}

int getAttendancePercent() {
    return attendancePercent;
}

int getCourseCode() {
    return courseCode;
}

int getFamilyIncome() {
    return familyIncome;
}

int getInterviewScore() {
    return interviewScore;
}

// ============================
//          METHODS
//============================

    
    std:: string calcAverage(){
         // general average 
    // 1 = EXCELLENT 2 = VERY GOOD 3 = GOOD 
    // 4 = SATISFACTORY 5 = NEEDS IMPROVEMENT 

    if(generalAverage >= 95){ 
        return "EXCELLENT"; 
    } 
    else if(generalAverage >= 90){ 
        return "VERY GOOD"; 
    } 
    else if(generalAverage >= 85){ 
        return "GOOD"; 
    } 
    else if(generalAverage >= 80){ 
        return "SATISFACTORY"; 
    } 
    else{ 
        return "NEEDS IMPROVEMENT"; 
    } 

    }

    std:: string attendanceResults(){ 
    // attendance 
    // 1 = Excellent Attendance 

    if(attendancePercent >= 95){ 
        return "EXCELLENT ATTENDANCE"; 
    } 
    else{
        return "REGULAR ATTENDANCE";
    }
} 



    
    std:: string courseResults(){ 

    // course 
    // 1 = Computer 2 = Civil 3 = Electrical 
    // 4 = Mechanical 5 = Electronics 0 = Invalid 

    switch(courseCode) 
    { 
        case 1: 
            return "Computer Engineering"; 

        case 2: 
            return "Civil Engineering"; 

        case 3: 
            return "Electrical Engineering"; 

        case 4: 
            return "Mechanical Engineering"; 

        case 5: 
            return "Electronics Engineering"; 

        default: 
            return "Invalid Course"; 
    } 
} 


std:: string admissionResults(){ 

 // admission 
    // 1 = ADMITTED 2 = WAITLISTESD 3 = REJECTED 

    if(generalAverage >= 85 && examScore >= 75 && attendancePercent >= 90){ 
        return "ADMITTED"; 
    } 
    else if(generalAverage >= 75){ 
        return "WAITLISTED"; 
    } 
    else{ 
        return "REJECTED"; 
    }

} 

std:: string examResults(){ 

    if(examScore >= 75){ 
        return "PASSED"; 
    } 
    else{ 
        return "FAILED"; 
    } 
} 


std:: string scholarshipState(){ 
      // scholarship 
    // 1 = FULL 2 = PARTIAL 3 = NO SCHOLARSHIP 4 = NOT QUALIFIED 


if (generalAverage >= 90 && examScore >= 85) { 
    if (familyIncome <= 20000) { 
        return "FULL SCHOLARSHIP"; 
    } else if (familyIncome <= 40000) { 
        return "PARTIAL SCHOLARSHIP"; 
    } else { 
        return "NO SCHOLARSHIP"; 
    } 
} else { 
    return "NOT QUALIFIED"; 
} 

} 


std:: string recommendationState(){ 
std:: string currentAdmissionStatus = admissionResults();
// recommendation 
// 1 = HIGHLY RECOMMENDED 
// 2 = RECOMMENDED 
// 3 = ADMITTED 
// 4 = FOR FURTHER EVALUATION 
// 5 = NOT RECOMMENDED 


if(currentAdmissionStatus == "ADMITTED"){ 
        if(generalAverage >= 90 && examScore >= 85 && interviewScore >= 85){ 
            if(familyIncome <= 20000){ 
                return "HIGHLY RECOMMENDED"; 
            }else if(familyIncome <= 40000){ 
                return "RECOMMENDED"; 
            }else{ 
                return "ADMITTED"; 
            } 

        } 
    else{ 
        return "ADMITTED"; 
    } 

} 
else if(currentAdmissionStatus == "WAITLISTED"){
    return "FOR FURTHER EVALUATION";
}
else{
    return "NOT RECOMMENDED";
}
} 

void printEvaluation() {
        std::cout << "=============== STUDENT EVALUATION ===============\n\n";
        std::cout << "Student ID: " << studentId << '\n';

        // course
        std::cout << "Course: " << courseResults() << "\n\n";

        // entrance exam score
        std::cout << "Entrance Exam: " << examScore << '\n';
        std::cout << "Status: " << examResults() << "\n\n";

        // average
        std::cout << "General Average: " << generalAverage << '\n';
        std::cout << "Classification: " << calcAverage() << "\n\n";

        // attendance
        std::cout << "Attendance: " << attendancePercent << "%\n";
        std::cout << "Status: " << attendanceResults() << "\n\n";

        // interview score
        std::cout << "Interview Score: " << interviewScore << "\n\n";

        // admission status
        std::cout << "Admission Status: " << admissionResults() << "\n\n";

        // scholarship status
        std::cout << "Scholarship Status: " << scholarshipState() << "\n\n";

        // recommendation
        std::cout << "Recommendation: " << recommendationState() << "\n\n";

        std::cout << "=============== END OF EVALUATION ===============\n";
    }

};



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

    // The return MUST go at the very end, after all variables are filled!
    return StudentApplication(tempId, tempExam, tempAvg, tempAtt, tempCourse, tempIncome, tempInterview);

};


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




