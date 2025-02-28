
# Simulation Project

This project simulates a scenario with a customizable seed for randomness. It is written in C++20 and uses standard C++ libraries for various functionalities.

## Build Instructions

To build the project, follow these steps:

1. Ensure that **g++** is installed on your system (version 10.0 or above for C++20 support).
2. Clone this repository or download the source files.
3. In the project directory, run the following command to compile the source files:
   ```bash
   g++ -std=c++20 src/*.cpp -o sim
   ```

This will generate an executable named `sim`.

## Usage

To run the simulation, use the following command:
```bash
./sim [seed]
```

- Replace `[seed]` with an integer value to set the random seed for the simulation.
- If no seed is provided, a random seed will be used.

### Example:

To run the simulation with a seed of `12345`, use:
```bash
./sim 12345
```

This will start the simulation with the specified seed.

