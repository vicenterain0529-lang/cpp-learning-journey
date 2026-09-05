import json
from .student import Student

class StudentManager:

    def __init__(self):
        self.students = []


    def add_student(self, student):
        self.students.append(student)


    def show_students(self):
        for student in self.students:
            student.show_info()

    def create_student(self):

        student_id = input('ID: ')
        student_name = input('Name: ')
        age = int(input("Age: "))
        course = input('Course: ')
        new_student = Student(student_id, student_name, age, course)
        self.add_student(new_student)
        print(f"Student: {student_name} has been added successfully")

    def search_students(self):
        student_id = input("Enter student ID: ")

        student = self.find_student(student_id)

        if student:
            student.show_info()
        else:
            print("Student not found.")
    
    
    def update_students(self):
        student_id = input("Enter student ID: ")

        student = self.find_student(student_id)

        if not student:
            print("Student not found.")
            return

        while True:
            print("""
    1. Name
    2. ID
    3. Age
    4. Course
    5. Exit
    """)

            choice = input("What would you like to update? ")

            if choice == "1":
                student.name = input("New Name: ")
                print("Name updated successfully!")

            elif choice == "2":
                student.student_id = input("New ID: ")
                print("ID updated successfully!")

            elif choice == "3":
                student.age = int(input("New Age: "))
                print("Age updated successfully!")

            elif choice == "4":
                student.course = input("New Course: ")
                print("Course updated successfully!")

            elif choice == "5":
                return

            else:
                print("Invalid choice.")


    def find_student(self, student_id):
        for student in self.students:
            if student.student_id == student_id:
                return student

        return None
    

    def remove_student(self):
        student_id = input("Enter the id of the student")
        student = self.find_student(student_id)
        
        
        if not student:
            print("Student not found.")
            return
        

        self.students.remove(student)
        print(f"Student '{student.name}' (ID: {student.student_id}) removed successfully!")

    def update_grade(self):
        student_id = input("Enter the id of the student")
        student = self.find_student(student_id)
        
        
        if not student:
            print("Student not found.")
            return
        
        answer = input("Update grade? (Y/N)").lower()
        if answer == "y":
            subject = input("Subject: ")
            grade = int(input("Grade: "))
            student.add_grades(subject, grade)
            print(f"{student.name}'s grade in {subject} has been updated to {grade}.")
        elif answer == "n":
            return
    
    def inspect_student(self):
        student_id = input("Enter the id of the student")
        student = self.find_student(student_id)
        
        
        if not student:
            print("Student not found.")
            return
        if not student.grades:
            print("This student has no grades yet.")
            return
        
        print(f"\nGrades for {student.name}")
        print("-" * 25)

        for subject, grade in student.grades.items():
            print(f"{subject:<15}: {grade}")
    
    
    def save_student(self):
        student_data = []
        for student in self.students:
            student_data.append(student.to_dict())
        

        with open("student_master_list.json", "w", encoding="utf-8") as file:
            json.dump(student_data, file, indent=4)
        
        print("Students saved successfully!")

    def load_student(self):
        try:
            with open("student_master_list.json", "r", encoding="utf-8") as file:
                student_data = json.load(file)

            self.students.clear()

            for data in student_data:
                student = Student(
                    data["student_id"],
                    data["name"],
                    data["age"],
                    data["course"]
                )

                student.grades = data["grades"]

                self.students.append(student)

            print("Students loaded successfully!")

        except FileNotFoundError:
            print("No saved student data found.")