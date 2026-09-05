# Maze Chase: A C++ Terminal Game

A beginner-friendly Windows terminal game built in C++. Move through a hand-designed maze, collect enemies to increase your score, and avoid hazards while a chaser tracks your position.

This project is part of my [C++ Learning Journey](https://github.com/vicenterain0529-lang/cpp-learning-journey), a growing portfolio that records my progress from first programming exercises to more advanced software projects.

## Gameplay

You control the player character `@` inside a 30 by 10 maze loaded from `map.txt`.

### Rules

- Move with `W`, `A`, `S`, and `D`.
- Walls marked `#` block movement.
- Touch `E` to collect the enemy and increase your score.
- The `C` chaser moves toward you every three turns.
- Touching the chaser resets your position and score.
- Touching an `x` hazard also resets your position and score.
- Enemy and chaser positions are regenerated to avoid unsafe starting locations.
- Press `N` at the start screen to exit.

### Symbols

| Symbol | Meaning |
| --- | --- |
| `@` | Player |
| `E` | Collectible enemy |
| `C` | Chaser |
| `#` | Wall |
| `x` | Reset hazard |
| Space | Walkable floor |

## Features

- Real-time single-key terminal movement
- Wall collision detection
- Score tracking and enemy respawning
- Chaser movement with a cooldown
- Map loading from an external text file
- Map size and row validation before gameplay
- Launch-directory-independent map discovery
- Screen redraws and a visible score counter

## Download And Run

The easiest option is to download `game.exe` from the [v2.0 release](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases/tag/v2.0).

Keep `map.txt` in the repository root, then run the executable from the `output` directory:

```powershell
cd output
.\game.exe
```

The original version is available in the [v1.0 release](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases/tag/v1.0).

## Build From Source

### Requirements

- Windows
- MinGW-w64 with `g++`
- C++17 support

From the repository root, compile the game with:

```powershell
g++ -std=c++17 -Wall -Wextra -g3 game2.0.cpp -o output\game.exe
```

Then run it:

```powershell
cd output
.\game.exe
```

The game uses the Windows-specific `conio.h` library for single-key input. In VS Code, `Ctrl+Shift+B` runs the tracked `Build movement simulator` task.

## Project Files

```text
game2.0.cpp          Game source code
map.txt              Editable maze layout
output/game.exe      Published Windows build
.vscode/             Build and debug configuration
rock.cpp             Earlier Rock, Paper, Scissors exercise
```

## Rock, Paper, Scissors

[`rock.cpp`](rock.cpp) is a terminal-based Rock, Paper, Scissors game. The player chooses rock, paper, or scissors while the computer makes a random move. The game displays ASCII art for both choices, reports the result, and keeps score across rounds.

Build and run it from the repository root with:

```powershell
g++ -std=c++17 -Wall -Wextra -g3 rock.cpp -o output\rock.exe
.\output\rock.exe
```

## Future Improvements

- Add a quit key during gameplay.
- Improve invalid-input handling.
- Replace `rand()` with the modern `<random>` library.
- Separate input, rendering, and game state into modules or classes.
- Add automated tests for map loading, collisions, spawning, and scoring.
- Add a portable CMake build and non-Windows support.
- Add more levels, difficulty settings, and a high-score system.
- Add screenshots or gameplay recordings to the release page.

## Version History

- **v2.0:** External map loading, map validation, a second chaser, respawning, and improved build configuration.
- **v1.0:** Original movement simulator release.

See the [full Releases page](https://github.com/vicenterain0529-lang/cpp-learning-journey/releases) to download milestone builds and compare versions.
