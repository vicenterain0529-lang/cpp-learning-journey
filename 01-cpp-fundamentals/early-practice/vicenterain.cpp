#include <iostream>
using namespace std;

int main(){

    // variable declarations
    int studentId;

    int examScore;
    int examResult;

    int generalAverage;
    int averageClass;

    int attendancePercent;
    int attendanceResult = 0;

    int courseCode;
    int courseResult;

    int admissionResult;

    int scholarshipStatus;

    int familyIncome;
    int interviewScore;

    int recommendationStatus;
cout << "==============================================\n";
cout << "       STUDENT ADMISSION & SCHOLARSHIP       \n";
cout << "               SCREENING SYSTEM              \n";
cout << "==============================================\n";
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


    // entrance exam
    // 1 = PASSED 2 = FAILED

    if(examScore >= 75){
        examResult = 1;
    }
    else{
        examResult = 2;
    }
    



    // general average
    // 1 = EXCELLENT 2 = VERY GOOD 3 = GOOD
    // 4 = SATISFACTORY 5 = NEEDS IMPROVEMENT

    if(generalAverage >= 95){
        averageClass = 1;
    }
    else if(generalAverage >= 90){
        averageClass = 2;
    }
    else if(generalAverage >= 85){
        averageClass = 3;
    }
    else if(generalAverage >= 80){
        averageClass = 4;
    }
    else{
        averageClass = 5;
    }


    // attendance
    // 1 = Excellent Attendance

    if(attendancePercent >= 95){
        attendanceResult = 1;
    }


    // course
    // 1 = Computer 2 = Civil 3 = Electrical
    // 4 = Mechanical 5 = Electronics 0 = Invalid

    switch(courseCode)
    {
        case 1:
            courseResult = 1;
            
            break;

        case 2:
            courseResult = 2;
            break;

        case 3:
            courseResult = 3;
            break;

        case 4:
            courseResult = 4;
            break;

        case 5:
            courseResult = 5;
            break;

        default:
            courseResult = 0;
            break;
    }


    // admission
    // 1 = ADMITTED 2 = WAITLISTED 3 = REJECTED

    if(examScore >= 75){

        if(generalAverage >= 85){

            if(attendancePercent >= 90){
                admissionResult = 1;
            }
            else{
                admissionResult = 2;
            }

        }
        else{
            admissionResult = 2;
        }

    }
    else{
        admissionResult = 3;
    }


    // scholarship
    // 1 = FULL 2 = PARTIAL 3 = NO SCHOLARSHIP 4 = NOT QUALIFIED

    if(generalAverage >= 90){

        if(examScore >= 85){

            if(interviewScore >= 85){

                if(familyIncome <= 20000){
                    scholarshipStatus = 1;
                }
                else if(familyIncome <= 40000){
                    scholarshipStatus = 2;
                }
                else{
                    scholarshipStatus = 3;
                }

            }
            else{
                scholarshipStatus = 4;
            }

        }
        else{
            scholarshipStatus = 4;
        }

    }
    else{
        scholarshipStatus = 4;
    }


// recommendation
// 1 = HIGHLY RECOMMENDED
// 2 = RECOMMENDED
// 3 = ADMITTED
// 4 = FOR FURTHER EVALUATION
// 5 = NOT RECOMMENDED

if(admissionResult == 1){

    if(generalAverage >= 90){

        if(examScore >= 85){

            if(interviewScore >= 85){

                if(familyIncome <= 20000){
                    recommendationStatus = 1;
                }
                else if(familyIncome <= 40000){
                    recommendationStatus = 2;
                }
                else{
                    recommendationStatus = 3;
                }

            }
            else{
                recommendationStatus = 3;
            }

        }
        else{
            recommendationStatus = 3;
        }

    }
    else{
        recommendationStatus = 3;
    }

}
else if(admissionResult == 2){
    recommendationStatus = 4;
}
else{
    recommendationStatus = 5;
}


cout << "=============== STUDENT EVALUATION ===============\n\n\n";
cout << "Student ID: "<< studentId << '\n';

// course
switch(courseResult){
    case 1: 
    cout << "Course: Computer Engineering \n\n";
    break;

    case 2: 
    cout << "Course: Civil Engineering \n\n";
    break;

    case 3: 
    cout << "Course: Electrical Engineering \n\n";
    break;

    case 4: 
    cout << "Course: Mechanical Engineering \n\n";
    break;


    case 5: 
    cout << "Course: Electronics Engineering \n\n";
    break;

    default:
    cout << "Invalid\n\n";
}
// entrance exam score

cout << "Entrance Exam: "<< examScore << '\n';
if(examResult == 1){
    cout << "Status: Passed\n\n";
}
else{
    cout << "Status: Failed\n\n";
}

// average

cout << "General Average: " << generalAverage << '\n';
cout << "Classification: ";

// 1 = EXCELLENT 2 = VERY GOOD 3 = GOOD
// 4 = SATISFACTORY 5 = NEEDS IMPROVEMENT

switch(averageClass){
    case 1:
    cout << "EXCELLENT\n\n";
    break;
    
    case 2:
    cout << "VERY GOOD\n\n";
    break;

    case 3:
    cout << "GOOD \n\n";
    break;

    case 4:
    cout << "SATISFACTORY\n\n";
    break;

    case 5:
    cout << "NEEDS IMPROVEMENT\n\n";
    break;
    

}

// attendance
cout << "Attendance: " << attendancePercent << "%\n";
if(attendanceResult == 1){
    cout << "Excellent Attendance\n\n";
}


// interview score

cout << "Interview Score: " << interviewScore << '\n'<< '\n';

// admission status
 // 1 = ADMITTED 2 = WAITLISTED 3 = REJECTED
cout << "Admission Status: ";
    if(admissionResult == 1){
        cout << "ADMITTED\n";
    }
    else if(admissionResult == 2){
        cout << "WAITLISTED\n";
    }
    else{
        cout <<"REJECTED\n";
    }

// 1 = FULL 2 = PARTIAL 3 = NO SCHOLARSHIP 4 = NOT QUALIFIED
//scholarship staetus
cout << "Scholarship Status: ";
switch(scholarshipStatus){
    case 1:
    cout << "FULL\n\n";
    break;
    case 2:
    cout << "PARTIAL\n\n";
    break;
    case 3:
    cout << "NO SCHOLARSHIP\n\n";
    break;
    case 4:
    cout << "NOT QUALIFIED\n\n";
    break;
    
}


// recommendation
// 1 = HIGHLY RECOMMENDED
// 2 = RECOMMENDED
// 3 = ADMITTED
// 4 = FOR FURTHER EVALUATION
// 5 = NOT RECOMMENDED
cout << "Recommendation: ";

switch(recommendationStatus)
{
    case 1:
        cout << "HIGHLY RECOMMENDED\n\n";
        break;

    case 2:
        cout << "RECOMMENDED\n\n";
        break;

    case 3:
        cout << "ADMITTED\n\n";
        break;

    case 4:
        cout << "FOR FURTHER EVALUATION\n\n";
        break;

    case 5:
        cout << "NOT RECOMMENDED\n\n";
        break;
}


cout << "=============== END OF EVALUATION ===============";


cout << "=============== END OF EVALUATION ===============\n";

cout << "PROGRAM FINISHED. PRESS ENTER.";
cin.ignore();
cin.get();

return 0;
}