# Snake Game with Raylib

## Overview

This is a classic Snake game built using C++ and the Raylib graphics library. The game features a finite state machine (FSM) to handle different game states, including the main menu, gameplay, and game over screen. The project is structured to allow easy modification and extension.

## Features

- **Finite State Machine (FSM)** for managing game states efficiently.
- **Smooth Snake Movement** using a deque-based body structure.
- **Collision Detection** for walls and the snake's own body.
- **Collectables** to increase the snake's length and score.
- **Keyboard Controls** for navigation and game interaction.
- **Sound Effects** for collectables, game over, and background music.
- **Graphical UI Elements** for menus and score display.

## Installation & Setup (LINUX)

### Prerequisites

- C++ Compiler (e.g., g++)
- Raylib installed on your system
- Make for build

### Cloning the Repository

```sh
git clone https://github.com/xeenoh/Snake-Game
cd Snake-Game
```

### Compiling the Game

Using Makefile:

```sh
make
```

### Running the Game

```sh
./game
```

## Controls

- **Arrow Keys** - Move the snake
- **Left Shift** - Speed boost
- **Q** - Return to main menu
- **ESC** - Exit the game

## Project Structure

```
├── include/		# Header files
├── src/			# Source files
├── assets/		# Textures & Sounds
├── styles/		# UI Stylesheets
├── Makefile	# Build script
└── README.md		# Project documentation
```

## License

This project is licensed under the MIT License. Feel free to modify and distribute it.

## Acknowledgments

- Developed using **Raylib** for graphics.
- Inspired by the classic **Snake game** mechanics.

---
