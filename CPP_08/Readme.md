*This project has been created as part of the 42 curriculum by bmezher.*

## Description

CPP_08 is a C++ module focusing on advanced template programming and container manipulation. This project consists of three exercises that explore function templates, container specialization, and custom container implementations.

### Project Goal
The goal of this module is to master C++ template fundamentals and understand how to work with the Standard Template Library (STL). Through practical exercises, learners gain experience with:
- Function templates and their instantiation
- Template specialization
- Container operations and algorithms
- Custom container implementations based on existing STL containers

### Exercises Overview

**Exercise 00 - easyfind**
A function template that searches for a specific value in any container. Demonstrates basic template syntax and iterator usage.

**Exercise 01 - Span**
A container class that stores a fixed-size array of integers and provides methods to find the shortest and longest span (distance between two elements). Introduces template classes and container manipulation.

**Exercise 02 - MutantStack**
A custom container that combines the properties of a stack with iterator support. Shows how to create specialized containers by wrapping STL containers and adding functionality.

## Instructions

### Requirements
- C++98 standard or later
- A C++ compiler (g++, clang++, etc.)
- GNU Make

### Compilation

Navigate to the project root directory and compile all exercises:

```bash
cd ex00 && make && cd ..
cd ex01 && make && cd ..
cd ex02 && make && cd ..
```

Or compile individual exercises:

```bash
cd ex00 && make    # Compiles easyfind
cd ex01 && make    # Compiles Span
cd ex02 && make    # Compiles MutantStack
```

### Execution

**Exercise 00 - easyfind:**
```bash
cd ex00
./easyfind
```

**Exercise 01 - Span:**
```bash
cd ex01
./span
```

**Exercise 02 - MutantStack:**
```bash
cd ex02
./mutantstack
```

### Cleaning

To remove compiled objects and executables:

```bash
cd ex00 && make clean && cd ..
cd ex01 && make clean && cd ..
cd ex02 && make clean && cd ..
```

To remove all generated files:

```bash
cd ex00 && make fclean && cd ..
cd ex01 && make fclean && cd ..
cd ex02 && make fclean && cd ..
```

## Resources

### C++ Template References
- [cppreference.com - Templates](https://en.cppreference.com/w/cpp/language/templates) - Official C++ template documentation
- [cppreference.com - STL Containers](https://en.cppreference.com/w/cpp/container) - Standard container library reference
- [cppreference.com - Iterators](https://en.cppreference.com/w/cpp/iterator) - Iterator concepts and usage

### Learning Materials
- [C++ Templates: The Complete Guide](http://www.tmplbook.com/) - Comprehensive template programming resource
- [GeeksforGeeks - C++ Templates](https://www.geeksforgeeks.org/templates-cpp/) - Tutorial on function and class templates
- [cplusplus.com - Templates](http://www.cplusplus.com/doc/oldtutorial/templates/) - Basic template tutorial

### AI Usage

AI assistance was used for the following aspects of this project:
- **Documentation**: Assisted in creating clear and comprehensive README

The core algorithm implementations and logical problem-solving were performed independently to ensure learning objectives were met.

## Notes

- All code follows the C++98 standard for compatibility
- Memory management should be handled carefully, especially with dynamic allocations
- Template instantiation happens at compile-time
- Each exercise builds on previous concepts progressively

---

For more information about the 42 school and its curriculum, visit [42.fr](https://www.42.fr/)
