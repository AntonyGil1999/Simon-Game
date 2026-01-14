
```markdown
# Arduino-Simon-Game
Projet Arduino Platform pour Politechnika Krakowska

# 🎮 Simon Game - Memory Challenge

An Arduino-based implementation of the classic electronic memory game, featuring dynamic difficulty, LCD feedback, and speed control.

![System Diagram](Wokwi%20System%20Diagram.png)

## 📋 Project Description

This project implements a Simon Game on Arduino Uno. It creates an interactive sequence of lights and sounds that the player must memorize and reproduce. The system includes:
- **Pattern Generation**: Random sequences increasing in length.
- **User Interface**: LCD screen displaying score, round number, and speed.
- **Input System**: 4 buttons corresponding to 4 colored LEDs.
- **Analog Control**: Real-time speed adjustment using a potentiometer.

## 🎯 Features

- [cite_start]**Progressive Difficulty**: Pattern length increases after every successful round[cite: 269].
- [cite_start]**Scoring System**: Points are awarded based on pattern length; penalties for mistakes [cite: 196-198].
- **Live Feedback**: 
  - [cite_start]LCD displays "Score", "Pattern Length" (P), and "Delay" (D) [cite: 219-221].
  - [cite_start]Visual error alarm (all LEDs flashing) upon mistake[cite: 277].
- [cite_start]**Speed Control**: Adjustable delay between signals (200ms - 1000ms) via potentiometer [cite: 300-301].
- [cite_start]**Game Over Conditions**: Triggered by completing 10 rounds or reaching a negative score [cite: 207-209].

## 🛠️ Technologies Used

This project demonstrates the following Embedded System concepts:
- **Hardware Interfacing**: Control of Digital I/O (LEDs, Buttons) and Analog Inputs.
- [cite_start]**LiquidCrystal Library**: Management of a 16x2 LCD display in 4-bit mode[cite: 41].
- **State Management**: Handling game phases (Start, Display, Input, Feedback).
- [cite_start]**Array Manipulation**: Storing and iterating through random sequences (`pattern[]`)[cite: 55].
- [cite_start]**Timing Control**: Using `millis()` and `delay()` for game logic and debouncing [cite: 50-51].
- [cite_start]**Random Generation**: Utilizing `randomSeed(millis())` for unpredictable patterns[cite: 52].

## 📁 Project Structure


```

.
├── src
│   └── main.cpp          # Main Arduino sketch (Game Logic)
├── lib                   # Project specific libraries
├── include               # Project header files
├── platformio.ini        # PlatformIO configuration
├── .gitignore            # Git configuration
├── Wokwi System Diagram.png              # Circuit Diagram
├── GIL Antony Projet Arduino Simon Game.pdf  # Full Project Report
└── README.md             # This file

```

## 🚀 Installation and Execution

### Prerequisites
- **VSCode** with **PlatformIO** extension.
- **Arduino Uno** board.
- Wiring components (LEDs, Resistors, Pushbuttons, Potentiometer, LCD 1602).

### Build and Upload
1. Clone the repository or download the source code.
2. Open the folder in VSCode.
3. Connect your Arduino Uno via USB.
4. Click on the **PlatformIO Upload** button (→) in the bottom bar.

### Hardware Configuration
Based on `main.cpp` and `Wokwi System Diagram`:

| Component | Pin(s) on Arduino | Type |
|-----------|-------------------|------|
| **LEDs** | 10, 11, 12, 13 | Digital Output |
| **Buttons** | 0, 1, 2, 3 | Digital Input |
| **LCD (RS, EN)** | 8, 9 | Digital Output |
| **LCD (Data D4-D7)** | 4, 5, 6, 7 | Digital Output |
| **Potentiometer** | A0 | Analog Input |

## 💻 Usage

Once the program is running on the Arduino:

1.  **Start**: The LCD displays the initial score (0).
2.  **Watch**: Observe the sequence of LEDs lighting up.
3.  **Repeat**: Press the corresponding buttons in the exact order.
    * *Success*: Pattern gets longer (+1), Score increases.
    * *Fail*: LEDs flash, Score decreases.
4.  **Adjust Speed**: Turn the potentiometer knob at any time to change the speed of the LED sequence (displayed as `D: xxx ms` on the LCD).

## 📊 Logic Flow (Simplified)

```text
START
  │
  ├── Initialize Pins & LCD
  │
  LOOP
    │
    ├── Read Potentiometer (Set Speed)
    ├── Generate/Extend Random Pattern
    ├── Show Pattern (LEDs)
    │
    ├── Player Turn (Wait for Buttons)
    │     ├── Match? ──> Score++, Pattern++
    │     └── Error? ──> Score--, Pattern--, Flash LEDs
    │
    ├── Update LCD (Score, Round, Speed)
    │
    └── Check Game Over (Rounds >= 10 OR Score < 0)
          ├── YES ──> STOP (Display "GAME OVER")
          └── NO  ──> Repeat LOOP

```

## 👨‍💻 Author

**GIL Antony**

* GitHub: [@AntonyGil1999](https://github.com/AntonyGil1999)
* University: Politechnika Krakowska im. Tadeusza Kościuszki

## 📅 Development Timeline

* **Academic Year**: 2025/2026
* **Project Type**: Individual Academic Project
* **Status**: Completed (Code & Report finalized)

## 📝 License & Documentation

This project was created as part of the **Arduino Platform Project** course at Politechnika Krakowska.

For a detailed explanation of the code, algorithms, and design choices, please refer to the attached report:
👉 **[GIL Antony Projet Arduino Simon Game.pdf](https://www.google.com/search?q=GIL%2520Antony%2520Projet%2520Arduino%2520Simon%2520Game.pdf)**

## 🙏 Acknowledgments

* 
**Professor**: Paweł Król 


* 
**Course**: Arduino Platform Project 


* 
**Institution**: Politechnika Krakowska 



```

```