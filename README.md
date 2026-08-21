# C++ Learning Journey

This repository documents my first steps into C++ and console game development. The projects are intentionally small and show my progress with programming fundamentals, input handling, file I/O, and game logic.

## About Me

My name is Rain E. Vicente. I am switching into C++ for my college class while also working on side projects to keep improving my programming skills. This repository reflects my early learning process and is meant to document what I am building and practicing as I grow.

## Current Version

The current project is `game2.0.cpp`, a Windows console movement simulator. It loads its level from `map.txt` and includes:

- Player movement through a 30 by 10 map with wall collision checks
- A score system for collecting or reaching the enemy
- Random enemy respawning that avoids the player
- A second chaser with cooldown-based movement and respawning
- Screen redraws, a visible score, and map validation for missing or incorrectly sized rows

The repository also includes `rock.cpp`, an earlier Rock, Paper, Scissors exercise. The current Windows executable is published at `output/game.exe`.

## Changes In Version 2.0

- Moved the level layout into the editable `map.txt` file instead of keeping it only in code
- Added map loading and row-width validation before gameplay starts
- Added a second chaser and a cooldown so the player has more pressure and strategy
- Added respawn handling for both the collectible enemy and chaser
- Added collision protection for walls and the initial enemy spawn
- Improved the gameplay loop with screen clearing, cursor hiding, and score display

## Areas For Improvement

- Replace `rand()` and `srand()` with `<random>` for better randomization
- Add a clean quit key and handle invalid keyboard input without relying on `conio.h`
- Make the map path independent of the working directory
- Separate rendering, input, and game state into classes or smaller modules
- Add automated tests for map loading, collision rules, spawning, and scoring
- Add a portable build system and support for non-Windows terminals

## How To Run The Published Build

From the repository root on Windows:

```powershell
cd output
.\game.exe
```

The executable expects `map.txt` one directory above it. To rebuild with MinGW g++:

```powershell
g++ -std=c++17 -Wall -Wextra -g3 ..\game2.0.cpp -o game.exe
```

The game uses `conio.h` for keyboard input, so it currently targets Windows and MinGW g++.

## Notes

This project serves as a lightweight record of my early C++ learning journey for school, personal development, and future game projects.
