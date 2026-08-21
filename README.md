# C++ Learning Journey

My growing C++ portfolio, from first console exercises to larger games and software projects.

I am Rain E. Vicente, a student building practical projects while moving deeper into C++. This repository keeps the work in one place so the progress is visible: early experiments stay part of the story, while newer projects can become more ambitious and polished over time.

## Project Portfolio

| Project | Stage | What It Shows | Links |
| --- | --- | --- | --- |
| Movement Simulator | Beginner, current | Console input, collision rules, map file loading, score, enemy AI | [Source](game2.0.cpp) · [Map](map.txt) · [v2.0 release](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases/tag/v2.0) |
| Rock, Paper, Scissors | Beginner exercise | Functions, loops, validation, random choices, and score tracking | [Source](rock.cpp) |

The portfolio will grow as new projects are completed. A project can start small; the important part is recording what was learned, what changed, and what should improve next.

## Current Project: Movement Simulator

The current game is a Windows console movement simulator. It loads a 30 by 10 level from `map.txt` and includes:

- Player movement with wall collision checks
- A score system and random enemy respawning
- A second chaser with cooldown-based movement
- Enemy and chaser respawning rules
- Map row and width validation before gameplay
- Screen redraws and a visible score

### Version 2.0 Improvements

- Moved the level layout into an editable map file
- Added map validation and safer spawn handling
- Added a second chaser and cooldown-based pressure
- Added respawning for both moving threats
- Fixed the build task and map loading from different launch directories

Download the Windows build from the [v2.0 release](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases/tag/v2.0). The [v1.0 release](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases/tag/v1.0) preserves the original game for comparison.

## Learning Progression

### Beginner

- C++ syntax, variables, functions, loops, and conditionals
- Console input and output
- Random values and basic game rules
- Arrays, strings, and simple file input

### Building Next

- Classes and data ownership
- Standard library containers and algorithms
- Better randomization with `<random>`
- Automated tests for game rules
- Portable builds with CMake

### Long-Term Goals

- Modular game architecture
- More advanced enemy behavior
- Save data and configuration systems
- Cross-platform builds
- Larger projects with documented design decisions

## How To Run

The published executable targets Windows and MinGW g++.

```powershell
cd output
.\game.exe
```

The game can also be launched from the repository root because the loader searches the working directory, the executable directory, and its parent directory for `map.txt`.

To build the current project from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra -g3 game2.0.cpp -o output\game.exe
```

In VS Code, use `Ctrl+Shift+B` to run the tracked `Build movement simulator` task.

## Repository Structure

```text
game2.0.cpp          Current movement simulator
map.txt              Current level data
rock.cpp             Earlier console exercise
.vscode/             Reproducible build and debug configuration
output/game.exe      Current Windows build
```

As the portfolio grows, larger projects will be grouped into their own folders. Each project should include its source, a short README, build instructions, and a release when a runnable build is useful.

## Honest Next Steps

- Add an in-game quit key and stronger invalid-input handling
- Replace `rand()` with `<random>`
- Separate input, rendering, and game state into modules
- Add tests for map loading, collisions, spawning, and scoring
- Add a portable CMake build
- Add screenshots or short gameplay recordings to future project pages

## Releases

Use the [Releases page](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases) to compare runnable milestones. Source history remains available through Git commits and tags.
