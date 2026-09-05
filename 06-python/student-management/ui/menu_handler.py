from .menu import display_menu


def run(manager):

    display_menu()

    choice = input("Enter your choice: ")

    if choice == "1":
        manager.create_student()

    elif choice == "2":
        manager.show_students()

    elif choice == "3":
        manager.search_students()

    elif choice == "4":
        manager.update_students()

    elif choice == "5":
        manager.remove_student()

    elif choice == "6":
        manager.update_grade()

    elif choice == "7":
        manager.inspect_student()

    elif choice == "8":
        manager.save_student()

    elif choice == "9":
        manager.load_student()

    elif choice == "0":
        print("\nThank you for using the Student Management System!")
        return False

    else:
        print("\nInvalid choice. Please try again.")

    return True