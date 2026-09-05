# Student Enrollment Portal

## Overview

A multi-file console enrollment system for managing students, courses,
prerequisites, GPA requirements, seat capacity, and course rosters.

## What it does

The menu allows a user to add a student, add a course, add a prerequisite,
register a student, and display a course roster.

## How it works

```text
Menu choice -> RegistrationSystem
                  ├── Student records
                  ├── Course records
                  └── Registration checks
                              ↓
                       Roster or error message
```

`main.cpp` gathers input and delegates operations to `RegistrationSystem`.
`Student` stores identity, GPA, credits, and course lists. `Course` stores
course details, prerequisites, capacity, and enrolled students.

## Program structure

- `main.cpp` — menu and console input
- `RegistrationSystem.h/.cpp` — lookup and registration flow
- `Student.h/.cpp` — student data and enrollment state
- `course.h/.cpp` — course data, prerequisites, capacity, and roster output

## Concepts demonstrated

- Classes, constructors, private data, getters, and setters
- Composition between registration, student, and course objects
- Header/source separation
- `std::vector`
- Pointers returned by lookup functions
- GPA, prerequisite, duplicate-enrollment, and seat checks

## Current status

**In Progress.** The core menu and registration model are implemented, but the
project remains an active application rather than a documented release.

## Possible improvements

- Add robust handling for non-numeric input.
- Add automated tests for every registration rule.
- Separate menu presentation from domain operations.
- Add a persistent storage format.
