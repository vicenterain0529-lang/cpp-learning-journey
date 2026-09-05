# C++ Learning Journey

My programming portfolio as I learn C++, Python, SDL3, and embedded programming.
The repository preserves exercises, experiments, prototypes, and larger applications
so the code shows how my skills developed over time.

## About Me

My name is Rain E. Vicente. I am learning programming for college and personal
projects. I keep older code because it records what I practiced, what challenged
me, and how my designs changed.

## Languages and Technologies Found

- **C++:** console exercises, OOP applications, terminal games, and SDL3 prototypes
- **Python:** fundamentals, console applications, OOP projects, JSON persistence, and Tkinter
- **Arduino / C++:** PlatformIO LED experiments
- **SDL3:** window creation, events, keyboard input, and early rendering experiments

## Evidence-Based C++ Progress

### Fundamentals

- [x] Variables and data types
- [x] Operators and arithmetic
- [x] Input and output
- [x] Conditional and switch statements
- [x] Loops
- [x] Input validation
- [x] Functions, parameters, and return values
- [x] Scope
- [x] References
- [x] Pointers (SDL window pointers and pointer-based APIs)

### Data Structures and Files

- [x] C-style arrays and character arrays
- [x] `std::string`
- [x] `std::vector`
- [x] `struct`
- [x] Text-file input and validation
- [ ] `std::map`
- [ ] `std::set`
- [ ] JSON persistence in C++

### Object-Oriented Programming

- [x] Classes and objects
- [x] Access modifiers and encapsulation
- [x] Constructors
- [x] Getters and setters
- [x] Composition
- [x] Inheritance
- [ ] Polymorphism and virtual functions
- [x] Header/source separation
- [x] Multi-file projects

### Modern C++ and Architecture

- [x] `const`
- [x] `std::filesystem`
- [x] Error handling and validation
- [ ] Smart pointers and RAII
- [ ] Move semantics
- [ ] Templates and STL algorithms
- [ ] Automated tests

## Project Inventory

| Project | Language / technology | Status | Evidence and concepts |
| --- | --- | --- | --- |
| Early practice files | C++ | Exercise | Input/output, loops, strings, character handling, random numbers |
| Rock, Paper, Scissors | C++ | Completed exercise | Functions, validation, switch statements, references, score state |
| Maze Chase | C++ / Windows terminal | Completed and published | File loading, map validation, movement, collision, respawning, game loop |
| Scholarship application | C++ | Completed project | Class design, encapsulation, constructors, vectors, multi-file structure |
| Student enrollment portal | C++ | In progress | `Student`, `Course`, and `RegistrationSystem` classes, prerequisites, GPA and seat checks |
| OOP and terminal exercises | C++ | Exercises | Arrays, structs, classes, inheritance, constructors, Tic-Tac-Toe |
| SDL3 prototypes | C++ / SDL3 | Prototype | SDL initialization, windows, events, keyboard input, position state |
| Creature Battle variants | Python | In progress / experiments | Modules, classes, inheritance, turn-based battle logic |
| Library Management | Python | In progress | Modules, classes, books, borrowers, and library organization |
| Student Management | Python | In progress | Classes, menus, JSON save/load, student records |
| To-do list applications | Python / Tkinter | Prototype | GUI widgets, JSON persistence, task operations |
| Python small projects | Python | Exercises | Calculators, conversions, guessing games, shopping cart, RPG |
| Python 2 exercises | Python | Exercises | Banking, encryption, dice, and small console programs |
| YouTube downloader experiment | Python | Experiment | A small downloader script; dependencies and completion need review |
| LED experiments | Arduino / C++ / PlatformIO | Experiment | Arduino setup/loop and digital output |

## Repository Structure

```text
01-cpp-fundamentals/       Early C++ practice files
02-cpp-exercises/          OOP, algorithms, and terminal exercises
03-cpp-projects/           Scholarship and student enrollment applications
04-cpp-games/              Rock, Paper, Scissors and Maze Chase
05-sdl3/                   SDL3 prototypes
06-python/                 Python exercises and multi-file projects
07-arduino-platformio/     PlatformIO LED experiments
notes/                     Inventory and progress evidence
```

## Current Focus

The most recently modified files are the SDL3 practice programs from September
4, 2026. That makes SDL3 keyboard input, event handling, window management,
and the next rendering step the clearest current focus. Student Enrollment was
the next most recently modified multi-file application, so its validation and
registration rules are also active practice areas.

## Run Selected Projects

### Maze Chase

On Windows with MinGW-w64 and C++17:

```powershell
g++ -std=c++17 -Wall -Wextra -g3 04-cpp-games\maze-chase\game2.0.cpp -o output\game.exe
.\output\game.exe
```

The game uses `map.txt` from the repository root and supports `W`, `A`, `S`,
and `D` movement.

### Python projects

Run a project from its own directory, for example:

```powershell
python 06-python\student-management\main.py
```

Project-specific READMEs are preserved where they exist.

## Learning Assessment

### Demonstrated

Console control flow, functions, validation, references, arrays, strings,
vectors, classes, inheritance, multi-file C++, text-file input, Python
modules/classes, JSON persistence in Python, SDL event handling, and Arduino
digital output.

### Practiced

Larger application organization, reusable models, game loops, collision
handling, persistence workflows, and separating UI from program logic.

### Explored

SDL3 rendering, Tkinter GUI design, PlatformIO workflows, and multiple
versions of the Python creature battle project.

### Not Yet Demonstrated in the collected files

C++ JSON persistence, `std::map`, `std::set`, smart pointers, move semantics,
templates, automated tests, completed SDL3 rendering, and a complete embedded
application.

See [`notes/inventory.md`](notes/inventory.md) and
[`notes/progress-log.md`](notes/progress-log.md) for the detailed evidence.
