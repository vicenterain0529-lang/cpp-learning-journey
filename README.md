# C++ Learning Journey

This repository documents my first steps into C++ and game development. The projects are intentionally small: they show my progress as I learn programming fundamentals, console interaction, and game logic.

## About Me

My name is Rain E. Vicente. I am switching into C++ for my college class while also working on side projects to keep improving my programming skills. This repository reflects my early learning process and is meant to document what I am building and practicing as I grow.

## Project Focus

The current game project is:

- `gameorig.cpp` — a console movement simulator with a player, enemy, score tracking, random enemy respawning, and a drawn map

Other beginner exercises in this repository include:

- `rock.cpp` — a Rock, Paper, Scissors game
- `arrays.cpp`, `hance.cpp`, `rain.cpp`, `randomEvent.cpp`, `sinendniron.cpp` — practice programs exploring C++ fundamentals
- `word analyzer.cpp`, `wordcounter.cpp` — text and word-counting exercises

## Standard GitHub Procedure

```bash
git init
git add README.md *.cpp
git commit -m "Add C++ learning project"
gh repo create cpp-learning-journey --public --source=. --remote=origin --push
git push -u origin main
```

## How to Run

```bash
g++ gameorig.cpp -o gameorig
./gameorig
```

The game uses `conio.h` for keyboard input, so it is currently intended for a Windows compiler such as MinGW g++.

## Notes

This project serves as a lightweight record of my early C++ learning journey for school, personal development, and future game projects.
