# C++ Learning Journey

This repository is Rain E. Vicente's programming portfolio. It records the progression from small console exercises to a larger C++ terminal game, including the concepts practiced, implementation challenges, and next steps.

## About Me

My name is Rain E. Vicente. I am learning C++ for college and personal projects. I use this repository to keep my older work, understand how my code evolves, and document what I learn while building.

## Learning Progression

### 1. First console project: Rock, Paper, Scissors

[`rock.cpp`](rock.cpp) is an early console game with:

- Keyboard input and validation
- `if` statements and `switch` statements
- Loops for repeated rounds
- Functions and function prototypes
- Reference parameters for updating scores
- Random number generation
- Score tracking and game-state decisions

This project established the basics of decomposing a program into functions and controlling a complete interactive loop.

### 2. Current project: Maze Chase

[`game2.0.cpp`](game2.0.cpp) is a Windows terminal game that expands those ideas into a larger program:

- A 30 by 10 map loaded from [`map.txt`](map.txt)
- Player movement with `W`, `A`, `S`, and `D`
- Walls, hazards, collectible enemies, and a pursuing chaser
- Collision detection, score updates, and respawning
- A chaser cooldown and movement logic
- Map validation and file-error handling
- `std::filesystem` for finding the map relative to the executable
- A VS Code build and debug workflow in [`.vscode/`](.vscode/)

The game demonstrates the transition from isolated functions to a multi-step game loop with shared state, file input, and platform-specific terminal input.

## Run the Maze Chase Game

### Requirements

- Windows
- MinGW-w64 with `g++`
- C++17 support

Build from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra -g3 game2.0.cpp -o output\game.exe
```

Run the game:

```powershell
cd output
.\game.exe
```

Keep `map.txt` in the repository root. The program also searches locations relative to the executable when it is launched from `output`.

## Maze Controls

| Input | Action |
| --- | --- |
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `N` | Exit from the start screen |

| Symbol | Meaning |
| --- | --- |
| `@` | Player |
| `E` | Collectible enemy |
| `C` | Chaser |
| `#` | Wall |
| `x` | Reset hazard |
| Space | Walkable floor |

## Repository Map

```text
rock.cpp              Early Rock, Paper, Scissors project
game2.0.cpp           Current Maze Chase source code
map.txt               Editable maze layout
output/game.exe       Published Windows build
.vscode/tasks.json    VS Code build task
.vscode/launch.json   VS Code debugger configuration
```

## What I Am Learning Next

- Replace `rand()` with the modern `<random>` library.
- Separate input, rendering, and game state into classes or modules.
- Improve invalid-input and quit handling during gameplay.
- Add automated tests for map loading, collisions, spawning, and scoring.
- Learn a portable CMake build and non-Windows input approach.
- Add levels, difficulty settings, and a high-score system.

## Version History

- **v2.0:** External map loading, validation, respawning, a chaser cooldown, and improved build configuration.
- **v1.0:** Original movement simulator.
