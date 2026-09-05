
class Student:
    def __init__(self, student_id, name, age, course):
        self.student_id = student_id
        self.name = name
        self.age = age
        self.course = course
        self.grades = {}


    def add_grades(self, subject, grade):
        self.grades[subject] = grade
        return self.grades

    def show_info(self):
        print(F"=" *20)
        print(f"Name: {self.name} ")
        print(f'ID: {self.student_id}')
        print(f"Age: {self.age}")
        print(f"Course: {self.course}")

        print("Grades: ")

        for subject, grade in self.grades.items():
            print(f"Subject: {subject}",
                f"Grades: {grade}")
            
    def to_dict(self):
        dictionary = {
            "student_id": self.student_id,
            "name": self.name,
            "age": self.age,
            "course": self.course,
            "grades": self.grades
        }
    
        return dictionary