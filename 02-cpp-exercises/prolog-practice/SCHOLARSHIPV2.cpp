#include <iostream>
#include <string>
using namespace std;
// function declarations 

void userInputs(int& studentId, int& generalAverage, int& examScore, int& attendancePercent, int& courseCode, int& familyIncome, int& interviewScore); 
void finalOutput(
    int studentId,
    string courseResult,
    int examScore,
    string examResult,
    int generalAverage,
    string averageClass,
    int attendancePercent,
    string attendanceResult,
    int interviewScore,
    string admissionResult,
    string scholarshipStatus,
    string recommendationStatus
);
string averageResults(int generalAverage);
string examResults(int examScore); 
string attendanceResults(int attendancePercent); 
string courseResults(int courseCode); 
string admissionResults(int generalAverage, int examScore, int attendancePercent); 
string scholarshipState(int generalAverage, int examScore, int familyIncome, int interviewScore); 
string recommendationState(int generalAverage, int examScore, int familyIncome, int interviewScore, string admissionResult); 




int main(){ 
// Variables  

    int studentId;  
    int examScore; 
    string examResult; 

    int generalAverage; 
    string averageClass; 

    int attendancePercent; 
    string attendanceResult; 

    int courseCode; 
    string courseResult; 

    string admissionResult; 

    string scholarshipStatus; 

    int familyIncome; 
    int interviewScore; 

    string recommendationStatus; 
    while(true){
        
        userInputs(studentId, generalAverage, examScore, attendancePercent, courseCode, familyIncome, interviewScore); 

    examResult = examResults(examScore); 
    averageClass = averageResults(generalAverage); 
    attendanceResult = attendanceResults(attendancePercent); 
    courseResult = courseResults(courseCode); 
    admissionResult = admissionResults(generalAverage, examScore, attendancePercent); 
    scholarshipStatus = scholarshipState(generalAverage, examScore, familyIncome, interviewScore); 
    recommendationStatus = recommendationState(generalAverage, examScore, familyIncome, interviewScore, admissionResult); 


finalOutput(
    studentId,
    courseResult,
    examScore,
    examResult,
    generalAverage,
    averageClass,
    attendancePercent,
    attendanceResult,
    interviewScore,
    admissionResult,
    scholarshipStatus,
    recommendationStatus
);
    }

return 0;
} 

string examResults(int examScore){ 

    if(examScore >= 75){ 
        return "PASSED"; 
    } 
    else{ 
        return "FAILED"; 
    } 
} 

string averageResults(int generalAverage){ 
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


string attendanceResults(int attendancePercent){ 
    // attendance 
    // 1 = Excellent Attendance 

    if(attendancePercent >= 95){ 
        return "EXCELLENT ATTENDANCE"; 
    } 
    else{
        return "REGULAR ATTENDANCE";
    }
} 


string courseResults(int courseCode){ 

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

string admissionResults(int generalAverage, int examScore, int attendancePercent){ 

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

string scholarshipState(int generalAverage, int examScore, int familyIncome, int interviewScore){ 
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


string recommendationState(int generalAverage, int examScore, int familyIncome, int interviewScore, string admissionResult){ 

// recommendation 
// 1 = HIGHLY RECOMMENDED 
// 2 = RECOMMENDED 
// 3 = ADMITTED 
// 4 = FOR FURTHER EVALUATION 
// 5 = NOT RECOMMENDED 


if(admissionResult == "ADMITTED"){ 
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
else if(admissionResult == "WAITLISTED"){
    return "FOR FURTHER EVALUATION";
}
else{
    return "NOT RECOMMENDED";
}
} 


void userInputs(int& studentId, int& generalAverage, int& examScore, int& attendancePercent, int& courseCode, int& familyIncome, int& interviewScore){ 
// input section 

    cout << "Enter student ID: "; 
    cin >> studentId; 

    cout << "Enter student exam score (0-100): "; 
    cin >> examScore; 

    cout << "Enter student General Average(0-100): "; 
    cin >> generalAverage; 

    cout << "Enter student attendance percentage (0-100): "; 
    cin >> attendancePercent; 

    cout << "Enter family monthly income: "; 
    cin >> familyIncome; 
    cout << "Courses: \n"; 

    //============================= 
//============================= 

cout << "\n"; 
cout << "==================================================\n"; 
cout << "||              SELECT YOUR COURSE             ||\n"; 
cout << "==================================================\n"; 
cout << "||  [1]  Computer Engineering                  ||\n"; 
cout << "||  [2]  Civil Engineering                     ||\n"; 
cout << "||  [3]  Electrical Engineering                ||\n"; 
cout << "||  [4]  Mechanical Engineering                ||\n"; 
cout << "||  [5]  Electronics Engineering               ||\n"; 
cout << "==================================================\n"; 
cout << "\n"; 

//============================= 
//======================================== 

    cout << "Enter course code (1-5): "; 
    cin >> courseCode; 

    cout << "Enter interview score (0-100): "; 
    cin >> interviewScore; 

}
void finalOutput(
    int studentId,
    string courseResult,
    int examScore,
    string examResult,
    int generalAverage,
    string averageClass,
    int attendancePercent,
    string attendanceResult,
    int interviewScore,
    string admissionResult,
    string scholarshipStatus,
    string recommendationStatus
){
    cout << "=============== STUDENT EVALUATION ===============\n\n\n";
    cout << "Student ID: " << studentId << '\n';

// course
    cout << "Course: " << courseResult << "\n\n";

// entrance exam score

    cout << "Entrance Exam: " << examScore << '\n';
    cout << "Status: " << examResult << "\n\n";

// average

    cout << "General Average: " << generalAverage << '\n';
    cout << "Classification: " << averageClass << "\n\n";

// attendance

    cout << "Attendance: " << attendancePercent << "%\n";
    cout << "Status: " << attendanceResult << "\n\n";

// interview score

    cout << "Interview Score: " << interviewScore << '\n' << '\n';

// admission status

    cout << "Admission Status: " << admissionResult << "\n\n";

// scholarship status

    cout << "Scholarship Status: " << scholarshipStatus << "\n\n";

// recommendation

    cout << "Recommendation: " << recommendationStatus << "\n\n";

    cout << "=============== END OF EVALUATION ===============";
}