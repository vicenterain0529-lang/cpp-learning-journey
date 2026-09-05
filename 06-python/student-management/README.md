# Student Management System

This project is a modular Python console application for creating, searching,
updating, grading, removing, saving, and loading student records.

## Features

- Add new students
- View student information
- Search for a student by ID
- Update student details
- Add and inspect grades
- Remove students
- Save and load student data from a JSON file

## Technologies used

- Python
- Object-oriented programming
- JSON file storage

## How It Works

```text
main.py -> menu_handler -> StudentManager
                         ├── Student objects
                         └── student_master_list.json
```

`StudentManager` keeps a list of `Student` objects, routes menu operations,
searches by ID, updates fields and grades, and serializes records with
`json.dump`.

## Current Status

**In Progress.** Stronger input validation, data-file handling, and testing
remain future work.

## How to run

1. Open the project folder.
2. Run the program:

```bash
python main.py
```

## Project structure

```text
main.py
models/
ui/
```

## What I learned

Through this project, I learned how to:
- organize a small Python project into modules
- use classes to represent real-world objects
- create simple menu-based programs
- save and load data between runs

## Future improvements

I want to improve this project by:
- adding better input validation
- making the menu easier to use
- adding more persistent storage options
- cleaning up the code structure further

This repository is part of my learning journey and shows the kind of beginner Python projects I am practicing.
