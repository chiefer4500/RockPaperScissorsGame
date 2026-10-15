# C++ Rock, Paper, Scissors Game

An interactive, console-based Rock, Paper, Scissors game built in C++ where a player competes against the computer across a customizable number of rounds.

## 🚀 Key Features
* **Configurable Rounds:** Choose how many rounds you want to play per match (1 to 10).
* **Randomized Computer AI:** The computer makes independent, randomized choices every round.
* **Dynamic Visual & Audio Cues:** Changes console colors based on round outcomes (Green for User Win, Red for Computer Win, Yellow for Draw) along with audio alerts.
* **Comprehensive Match Summary:** Tracks total player wins, computer wins, and draws, and declares an overall match winner.
* **Replay Functionality:** Option to restart and play multiple games consecutively without closing the application.

## 🛠️ Tech Stack & Concepts Applied
* **Language:** C++
* **IDE & Toolchain:** Microsoft Visual Studio (MSVC) or any standard C++ compiler
* **Core Concepts:** 
  * Custom `structs` (`stHowManyWin`) for tracking game scores and state.
  * `enum` types (`enRPS`, `enRoundResult`) for clean choices and round evaluation.
  * Modular procedural functions for input validation, random generation, and score formatting.
  * Pseudo-random number generation (`rand`, `srand`, `time`).
  * System utilities for console color styling and audio alerts.

## 💻 How to Run
1. Create a new C++ project or open a solution in **Visual Studio**.
2. Paste the source code into your `main.cpp` file.
3. Build and run the program by pressing `Ctrl + F5`.
