import json

tasks = []



def main_program():
    while True:
        display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            view_tasks()
        elif choice == '2':
            add_task()
        elif choice == '3':
            complete_task()
        elif choice == '4':
            delete_task()
        elif choice == '5':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")


def view_tasks():
        if not tasks:
            print("To do list: No tasks available.")
            answer = input('Do you want to add a task? (yes/no): ')
            if answer == 'yes':
                add_task()
            else:
                print("Returning to the main menu.")
                return

        for index, task in enumerate(tasks, start=1):
            if task.get("completed"):
                status = "[✓]" 
            else:
                status = "[ ]" 
            print(f'{index}. {status} {task.get("task")}') 


def add_task():
    if not tasks:
        print("To do list: No tasks available.")
    answer = input('Enter what do you want to do: ')
    task = ({
        "task": answer,
        "completed": False
    })
    tasks.append(task)
    print(f"Task added: {answer}")
    print(f'Current tasks: {len(tasks)} ')
    save_tasks()

def complete_task():
    if not tasks:
        print("To do list: No tasks available.")
        return
    view_tasks()
    print("Enter the number of the task you want to mark as completed:")
    task_number = int(input('Task number: ')) -1

    if 0 <= task_number < len(tasks):
        tasks[task_number]['completed'] = True
        print(f'Task {tasks[task_number]["task"]} marked as completed.')
        save_tasks()

def delete_task():
    if not tasks:
        print("To do list: No tasks available.")
        return
    
    view_tasks()
    print("Enter the number of the task you want to delete:")
    task_number = int(input('Task number: ')) -1
    if 0 <= task_number < len(tasks):
        deleted_task = tasks.pop(task_number)
        print(f'Task {deleted_task["task"]} deleted.')
        save_tasks()

def display_menu():
    print("""
        1. View tasks
        2. Add task
        3. Complete task
        4. Delete task
        5. Exit
        """)
def save_tasks():
    with open("tasks.json", 'w') as saved_file:
        json.dump(tasks, saved_file)

def load_tasks():
    try:
        with open("tasks.json", 'r') as saved_file:
            global tasks
            tasks = json.load(saved_file)
    except FileNotFoundError:
        print("No saved tasks found. Starting with an empty to-do list.")
        tasks = []
load_tasks()

main_program()