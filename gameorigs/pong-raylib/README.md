# Pong Raylib

A graphical Pong-style arcade game written in C++ with [Raylib](https://www.raylib.com/).
The player controls the left paddle while an automated opponent controls the right
paddle. The first side to reach three points wins the round.

## Features

- 1200 x 800 Raylib game window
- Player movement with `W` and `S`
- Automated opponent paddle
- Paddle and screen-edge collision detection
- Score display and three-point rounds
- Background image, paddle-hit sound, and background music

## Requirements

- Windows
- MinGW-w64 with `g++`
- Raylib installed at `C:\raylib`

The source currently uses the Raylib headers and static library from:

```text
C:\raylib\include
C:\raylib\lib
```

## Build and run

From this module's directory, compile the source into an `output` directory:

```powershell
New-Item -ItemType Directory -Force output
g++ -Wall -Wextra -g3 pongv1.cpp `
  -IC:\raylib\include `
  -LC:\raylib\lib `
  -l:libraylib.a -lopengl32 -lgdi32 -lwinmm `
  -o output\pongv1.exe
```

Run the executable from the `output` directory so the relative asset path resolves:

```powershell
Set-Location output
.\pongv1.exe
```

## Controls

| Key | Action |
| --- | --- |
| `W` | Move the player paddle up |
| `S` | Move the player paddle down |
| Close the window | Exit the game |

## Project files

```text
pongv1.cpp       Game source
assets/          Background image and audio assets
```
