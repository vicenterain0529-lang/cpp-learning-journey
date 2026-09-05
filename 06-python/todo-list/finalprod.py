import tkinter as tk
from tkinter import messagebox
import json

TASKS_FILE = "tasks.json"


class TodoApp:
    def __init__(self, root):
        self.root = root
        self.root.title("To-Do List")
        self.root.geometry("500x400")

        self.tasks = []

        # ---------- Input ----------
        self.entry = tk.Entry(root, width=40)
        self.entry.pack(pady=10)

        self.add_button = tk.Button(
            root,
            text="Add Task",
            command=self.add_task
        )
        self.add_button.pack()

        # ---------- Task List ----------
        self.listbox = tk.Listbox(root, width=50, height=12)
        self.listbox.pack(pady=15)

        # ---------- Buttons ----------
        button_frame = tk.Frame(root)
        button_frame.pack()

        tk.Button(
            button_frame,
            text="Complete",
            command=self.complete_task
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            button_frame,
            text="Delete",
            command=self.delete_task
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            button_frame,
            text="Refresh",
            command=self.refresh_listbox
        ).grid(row=0, column=2, padx=5)

        self.load_tasks()
        self.refresh_listbox()

    # -----------------------------
    # Task Functions
    # -----------------------------

    def add_task(self):
        task_name = self.entry.get().strip()

        if not task_name:
            messagebox.showwarning("Warning", "Please enter a task.")
            return

        self.tasks.append({
            "task": task_name,
            "completed": False
        })

        self.entry.delete(0, tk.END)

        self.save_tasks()
        self.refresh_listbox()

    def complete_task(self):
        selected = self.listbox.curselection()

        if not selected:
            messagebox.showwarning(
                "Warning",
                "Select a task first."
            )
            return

        index = selected[0]
        self.tasks[index]["completed"] = True

        self.save_tasks()
        self.refresh_listbox()

    def delete_task(self):
        selected = self.listbox.curselection()

        if not selected:
            messagebox.showwarning(
                "Warning",
                "Select a task first."
            )
            return

        index = selected[0]

        self.tasks.pop(index)

        self.save_tasks()
        self.refresh_listbox()

    # -----------------------------
    # Display
    # -----------------------------

    def refresh_listbox(self):
        self.listbox.delete(0, tk.END)

        for task in self.tasks:
            status = "✓" if task["completed"] else "☐"
            self.listbox.insert(
                tk.END,
                f"{status} {task['task']}"
            )

    # -----------------------------
    # File Handling
    # -----------------------------

    def save_tasks(self):
        with open(TASKS_FILE, "w") as file:
            json.dump(self.tasks, file, indent=4)

    def load_tasks(self):
        try:
            with open(TASKS_FILE, "r") as file:
                self.tasks = json.load(file)
        except FileNotFoundError:
            self.tasks = []


root = tk.Tk()
app = TodoApp(root)
root.mainloop()