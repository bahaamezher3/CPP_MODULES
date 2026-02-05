# C++ Modules (CPP_00 - CPP_04)

A comprehensive collection of C++ exercises covering fundamental to advanced concepts in object-oriented programming. These modules are part of the 42 school curriculum, designed to progressively teach C++98 standard.

## 📚 Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Module Breakdown](#module-breakdown)
  - [CPP_00: Basics](#cpp_00-basics)
  - [CPP_01: Memory, References & Pointers](#cpp_01-memory-references--pointers)
  - [CPP_02: Ad-hoc Polymorphism](#cpp_02-ad-hoc-polymorphism)
  - [CPP_03: Inheritance](#cpp_03-inheritance)
  - [CPP_04: Subtype Polymorphism](#cpp_04-subtype-polymorphism)
- [Compilation](#compilation)
- [Usage](#usage)

## 🎯 Overview

This repository contains solutions to the C++ programming modules from 42 school. Each module focuses on specific C++ concepts and progressively builds upon previous knowledge.

**Standard:** C++98  
**Compiler:** c++  
**Flags:** `-Wall -Wextra -Werror -std=c++98`

## 🔧 Requirements

- A C++ compiler (g++, clang++)
- Make
- Linux/Unix environment

## 📖 Module Breakdown

### CPP_00: Basics

Introduction to C++ syntax, namespaces, classes, member functions, stdio streams, initialization lists, static, const.

#### Exercises:

- **ex00 - Megaphone**
  - Simple program that converts arguments to uppercase
  - Introduction to command-line arguments and string manipulation
  - `Usage: ./megaphone "string" "another string"`

- **ex01 - PhoneBook**
  - Implementation of a simple phonebook application
  - Learn about classes, objects, and basic member functions
  - Features: ADD, SEARCH, EXIT commands
  - Stores up to 8 contacts with formatted display

- **ex02 - Account**
  - Recreation of Account class based on provided logs
  - Understanding timestamps, static members, and class design

---

### CPP_01: Memory, References & Pointers

Deep dive into memory allocation, pointers vs references, and when to use each.

#### Exercises:

- **ex00 - BraiiiiiiinnnzzzZ**
  - Zombie class with stack vs heap allocation
  - Functions: `newZombie()` (heap) and `randomChump()` (stack)
  - Understanding object lifetime and memory management

- **ex01 - Moar brainz!**
  - Creating zombie hordes (arrays of objects)
  - Dynamic memory allocation for multiple objects
  - `zombieHorde()` function implementation

- **ex02 - HI THIS IS BRAIN**
  - Understanding pointers and references
  - Demonstrating memory addresses and dereferencing

- **ex03 - Unnecessary violence**
  - `HumanA` and `HumanB` classes with `Weapon`
  - Learning when to use references vs pointers
  - HumanA: Has a weapon (reference)
  - HumanB: May have a weapon (pointer)

- **ex04 - Sed is for losers**
  - File manipulation program
  - String replacement in files
  - `Usage: ./replace filename s1 s2`

- **ex05 - Harl 2.0**
  - Class with member function pointers
  - Implementation of logging levels (DEBUG, INFO, WARNING, ERROR)

- **ex06 - Harl filter**
  - Switch statement usage
  - Filtering log messages by level

---

### CPP_02: Ad-hoc Polymorphism

Operator overloading, Orthodox Canonical Form, and fixed-point numbers.

#### Exercises:

- **ex00 - My First Orthodox Canonical Class**
  - Fixed-point number class implementation
  - Orthodox Canonical Form (OCF):
    - Default constructor
    - Copy constructor
    - Copy assignment operator
    - Destructor

- **ex01 - Towards a more useful fixed-point number class**
  - Constructors for int and float
  - Conversion to int and float
  - Overloading insertion operator (`<<`)

- **ex02 - Now we're talking**
  - Overloading comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - Overloading arithmetic operators: `+`, `-`, `*`, `/`
  - Overloading increment/decrement: `++`, `--` (pre and post)
  - Static member functions: `min()`, `max()`

- **ex03 - BSP**
  - Binary Space Partitioning
  - Point class with Fixed coordinates
  - Determining if a point is inside a triangle

---

### CPP_03: Inheritance

Understanding inheritance hierarchies, protected members, and the diamond problem.

#### Exercises:

- **ex00 - Aaaaand... OPEN!**
  - `ClapTrap` class
  - Basic class with hit points, energy, and attack damage
  - Member functions: `attack()`, `takeDamage()`, `beRepaired()`

- **ex01 - Serena, my love!**
  - `ScavTrap` inherits from `ClapTrap`
  - Different initial values and behaviors
  - Special function: `guardGate()`

- **ex02 - Repetitive work**
  - `FragTrap` inherits from `ClapTrap`
  - Another derived class with unique attributes
  - Special function: `highFivesGuys()`

- **ex03 - Now it's weird!**
  - `DiamondTrap` with virtual inheritance
  - Inherits from both `ScavTrap` and `FragTrap`
  - Solving the diamond problem
  - Special function: `whoAmI()`

---

### CPP_04: Subtype Polymorphism

Abstract classes, interfaces, and deep copies.

#### Exercises:

- **ex00 - Polymorphism**
  - `Animal` base class with virtual destructor
  - `Dog` and `Cat` derived classes
  - `WrongAnimal` and `WrongCat` (demonstrating non-virtual issues)
  - Virtual function: `makeSound()`

- **ex01 - I don't want to set the world on fire**
  - `Brain` class with array of ideas
  - Deep copy implementation in `Dog` and `Cat`
  - Memory management with composition

- **ex02 - Abstract class**
  - `AAnimal` (Abstract Animal) with pure virtual functions
  - Cannot instantiate abstract classes
  - Enforcing implementation in derived classes

- **ex03 - Interface & recap**
  - `ICharacter` and `IMateriaSource` interfaces
  - `AMateria` abstract class
  - `Ice` and `Cure` materia implementations
  - `Character` and `MateriaSource` concrete classes
  - Complex system demonstrating interfaces and polymorphism

---

## 🔨 Compilation

Each exercise contains a Makefile. To compile any exercise:

```bash
cd CPP_0X/exYY
make
```

This will create an executable. Clean up with:

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything
```

## 🚀 Usage

### Example: Running CPP_00/ex00 (Megaphone)

```bash
cd CPP_00/ex00
make
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

### Example: Running CPP_00/ex01 (PhoneBook)

```bash
cd CPP_00/ex01
make
./phonebook
# Then use commands: ADD, SEARCH, EXIT
```

### Example: Running CPP_01/ex04 (Replace)

```bash
cd CPP_01/ex04
make
./replace filename "old_string" "new_string"
```

### Example: Running CPP_03/ex03 (DiamondTrap)

```bash
cd CPP_03/ex03
make
./diamondtrap
```

## 📝 Notes

- All code follows the **C++98 standard**
- Compilation flags ensure strict error checking: `-Wall -Wextra -Werror`
- Each class follows the **Orthodox Canonical Form** where applicable
- Memory leaks are checked and prevented
- Proper use of const correctness throughout

## 🎓 Learning Objectives

- **CPP_00:** Basic C++ syntax, classes, and member functions
- **CPP_01:** Memory management, pointers vs references
- **CPP_02:** Operator overloading, Orthodox Canonical Form
- **CPP_03:** Inheritance and inheritance hierarchies
- **CPP_04:** Polymorphism, abstract classes, and interfaces

## 📄 License

This project is part of the 42 school curriculum. Feel free to use it for educational purposes.

---

**Note:** Each exercise includes its own main.cpp for testing. Feel free to modify the main functions to test different scenarios and edge cases.
