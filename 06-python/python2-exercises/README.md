# Business System

This project is a small Python inventory system that I built to learn how to work with SQLite in a practical way. I wanted to practice connecting Python to a database, storing product data, and creating simple CRUD-style actions through a console menu.

## What this project does

The program lets a user:
- view products in the database
- add new products
- search for a product by code
- use a simple menu-based interface

## Features

- Console-based inventory menu
- SQLite database connection
- Product search by product code
- Product code generation based on category
- Basic beginner-friendly structure for learning database programming

## Technologies used

- Python
- SQLite3
- Standard input/output console interface

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/vicenterain0529-lang/business-system.git
   cd business-system
   ```
2. Create and activate a virtual environment (optional but recommended):
   ```bash
   python -m venv .venv
   .venv\Scripts\activate
   ```
3. Run the program:
   ```bash
   python business_system.py
   ```

## Project structure

```text
business_system.py
README.md
.gitignore
```

## Example usage

When you run the program, you will see a menu with options such as:
- view all products
- add a product
- search for a product
- exit the program

You can use option 2 to add a product and the program will save it into the SQLite database.

## What I learned

Through this project, I learned:
- how Python connects to SQLite
- how SQL queries are used to insert and read data
- how to structure a small console application
- how to think about simple data flow in a beginner project

## Future improvements

I would like to improve this project by:
- completing the update and delete functions
- adding better input validation
- creating a proper database schema file
- adding sample data for testing
- improving the code organization into smaller functions or classes

## Why I am sharing this

This repository is part of my learning journey. It is not meant to be a perfect project yet. I am sharing it to show my progress, practice GitHub workflow, and document what I am learning as I grow as a developer.
