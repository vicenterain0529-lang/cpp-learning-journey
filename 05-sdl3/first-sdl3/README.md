# SDL3 Prototype

## Overview

An early SDL3 keyboard-input prototype that creates a window, processes events,
and updates an integer position.

## How it works

```text
Initialize SDL -> create window -> poll events
        -> update x/y for W/A/S/D -> print position -> quit SDL
```

## Features demonstrated

- SDL initialization and shutdown
- Resizable borderless window creation
- Quit and keyboard events
- `W`, `A`, `S`, and `D` movement
- Escape key exit
- Position state updated inside the event loop

The other files in this folder (`practice.cpp`, `practice2.cpp`, and
`practice3.cpp`) are related experiments from the same SDL3 learning stage.

## Current status

**Prototype.** The code demonstrates event handling and state updates but does
not yet form a complete rendered game.

## Next steps

- Create an SDL renderer.
- Draw the position as a visible object.
- Add a structured game loop and timing.
- Add collision or world boundaries.
