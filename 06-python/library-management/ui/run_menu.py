from display import display_menu
from models import Book, Borrower, Library

library = Library()
def display_structure():
    while True:
        
        display_menu()
        try:
            user_input = input("What would you like to do? ")
        except ValueError:
            print("Error! Invalid Value: (must be a number 1-6)")
            
        if user_input == "1":
            pass    # View books

        elif user_input == "2":
            pass    # Borrow books

        elif user_input == "3":
            pass    # Return books

        elif user_input == "4":
            title, author, genre, copies = book_question()


        elif user_input == "5":
            pass    # Remove books

        elif user_input == "6":
            print("Thank you for using the Library Management System!")
            break

        else:
            print("Invalid choice. Please try again.")


def book_question():
    title, author, genre, copies  = input(" Enter Title, Author, genre, copies (separated by space)").split()
    book_attributes = title, author, genre, copies
    return book_attributes