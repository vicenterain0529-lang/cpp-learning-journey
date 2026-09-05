# Scholarship Application

## Overview

A console application that evaluates student scholarship applications from
entered scores and personal application values.

## What it does

The program collects a student ID, exam score, general average, attendance,
family income, course choice, and interview score. It evaluates each
`StudentApplication`, stores the result in a vector, and prints an end-of-day
summary for all evaluated students.

## How it works

```text
Collect application input
        ↓
Construct StudentApplication
        ↓
Print evaluation
        ↓
Store application in vector
        ↓
Repeat or print summary
```

## Program structure

- `SCHOLARSHIPV3.cpp` contains input collection and the main loop.
- `StudentApplication.h` declares the class and methods.
- `StudentApplication.cpp` implements evaluation and output behavior.

## Concepts demonstrated

- Header/source separation
- Classes and encapsulation
- Constructors and getters
- `std::vector`
- Functions returning objects
- Menu-style input and repeated processing

## Current status

**Completed project** according to the implemented evaluation and summary flow.
Input validation and the exact evaluation policy could still be expanded.

## Possible improvements

- Validate every score range and course selection.
- Separate evaluation rules from console output.
- Add tests for acceptance and rejection cases.
