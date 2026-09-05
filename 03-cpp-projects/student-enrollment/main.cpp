#include "RegistrationSystem.h"
#include <iostream>
#include <limits>

int main()
{
    RegistrationSystem system;

    int choice;

    do
    {
        std::cout << "\n===== REGISTRATION SYSTEM =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Course\n";
        std::cout << "3. Add Prerequisite\n";
        std::cout << "4. Register Student\n";
        std::cout << "5. Display Course Roster\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                // Add Student

                int studentID;
                std::string studentName;
                double GPA;
                int completedCredits;

                std::cout << "Enter Student ID: ";
                std::cin >> studentID;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter Student Name: ";
                std::getline(std::cin, studentName);

                std::cout << "Enter GPA: ";
                std::cin >> GPA;

                std::cout << "Enter Completed Credits: ";
                std::cin >> completedCredits;

                Student student(studentID, studentName, GPA, completedCredits);

                system.addStudent(student);

                std::cout << "STUDENT ADDED SUCCESSFULLY!\n";

                break;
            }

            case 2:
            {
                // Add Course

                std::string courseCode;
                std::string courseTitle;
                int maxSeats;
                double minGPA;

                std::cout << "Enter Course Code: ";
                std::cin >> courseCode;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter Course Title: ";
                std::getline(std::cin, courseTitle);

                std::cout << "Enter Maximum Seats: ";
                std::cin >> maxSeats;

                std::cout << "Enter Minimum GPA: ";
                std::cin >> minGPA;

                Course course(courseCode, courseTitle, maxSeats, minGPA);

                system.addCourse(course);

                std::cout << "COURSE ADDED SUCCESSFULLY!\n";

                break;
            }

            case 3:
            {    // Add Prerequisite

            std::string courseCode;
            std::string prerequisite;

            std::cout << "Enter Course Code: ";
            std::cin >> courseCode;

            std::cout << "Enter Prerequisite Course Code: ";
            std::cin >> prerequisite;

            Course* courseAddress = system.findCourse(courseCode);

            if (courseAddress == nullptr)
            {
                std::cout << "ERROR! COURSE NOT FOUND\n";
            }
            else
            {
                courseAddress->addPrerequisite(prerequisite);
                std::cout << "PREREQUISITE ADDED SUCCESSFULLY!\n";
            }

            break;
            }

            case 4:
            {
                // Register Student

                int studentID;
                std::string courseCode;

                std::cout << "Enter Student ID: ";
                std::cin >> studentID;

                std::cout << "Enter Course Code: ";
                std::cin >> courseCode;

                system.registerStudent(studentID, courseCode);

                break;
            }

            case 5:
            {
                // Display Course Roster

                std::string courseCode;

                std::cout << "Enter Course Code: ";
                std::cin >> courseCode;

                Course* courseAddress = system.findCourse(courseCode);

                if (courseAddress == nullptr)
                {
                    std::cout << "ERROR! COURSE NOT FOUND\n";
                }
                else
                {
                    courseAddress->displayRoster();
                }

                break;
            }

            case 6:
            {
                // Exit

                std::cout << "Exiting...\n";

                break;
            }

            default:
            {
                // Invalid choice

                std::cout << "INVALID CHOICE!\n";

                break;
            }
        }

    } while (choice != 6);

    return 0;
}