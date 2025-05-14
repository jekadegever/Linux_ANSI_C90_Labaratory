# Systems Programming Lab (C Language)

This repository contains assignments and projects developed as part of the **Systems Programming Lab** (course 20465), a second-year core course in the Software Engineering B.Sc. program at the **Open University of Israel**, Spring 2024 semester.

## Course Overview

The Systems Programming Lab offers an in-depth exploration of the C programming language according to the ANSI C90 standard. The course aims to build a solid understanding of how the C language works internally, including:

- Language architecture and compilation flow
- Memory management (stack vs. heap, dynamic allocation)
- Pointers and pointer arithmetic
- Modular design using header files and multiple source files
- Command-line interaction and standard input/output

All development is done in a **Linux (Ubuntu)** environment using the **GCC compiler**, with an emphasis on working through the terminal using `bash script`, `makefile`, and without the aid of external IDEs.

## Course Deliverables

The course includes **four programming assignments** and a **final project**:

---

### 🧪 Assignment 1: `palindrome` and `zero_bits_count`

- **`palindrome.c`**: Reads a string and determines whether it is a palindrome, ignoring whitespace and case sensitivity.
- **`count_zero_bits.c`**: Counts the number of binary zero bits in an unsigned integer using portable code across architectures.

---

### 🧮 Assignment 2: `magic.c`

- A program that reads an N×N matrix from input and checks if it's a **magic square**—i.e., all rows, columns, and diagonals sum to the same value.
- Includes input validation, dynamic analysis, and clear output reporting.
- Emphasizes modular code structure, error handling, and terminal I/O.

---

### 🧠 Assignment 3: `mymat`

- An interactive "matrix calculator" that accepts commands via standard input and performs operations such as:
  - Addition, subtraction, and multiplication of 4×4 matrices
  - Scalar multiplication
  - Matrix transposition
- Implements a command parser, input validation, and error messaging.
- Code is split into multiple files (`mainmat.c`, `mymat.c`, `mymat.h`) with clearly defined types, modularity, and abstraction via `typedef`.

---

### 🧾 Assignment 4: `numbers.c`

- A command-line program that:
  - Reads integers from a file or standard input
  - Converts each number (0–99) into its English word equivalent
  - Handles optional redirection of input and output files
  - Provides detailed error messages for invalid arguments or I/O issues
- Includes robust handling of edge cases, formatted output, and command-line parsing.

---

## 🛠 Final Project: Assembler in C

The capstone project involves developing a **custom assembler** written in C that emulates the functionality of a simplified system-level tool.

### Project Goals

- Parse and compile source files written in a **custom assembly language**
- Translate valid instructions into machine code and generate output files
- Handle various addressing methods, labels, macros, and memory structures
- Validate syntax and semantics, and report descriptive error messages

### Deliverables

- Full implementation in modular `.c` and `.h` files
- Compilation via `make` using `gcc -Wall -ansi -pedantic`
- Sample test files demonstrating:
  - Successful translation of valid input
  - Handling of multiple types of syntax and semantic errors
  - Output of generated machine code and error logs

This final project synthesizes all prior course knowledge and tests the student’s ability to manage a full-scale software development task in a low-level programming context.

---

Feel free to browse the repository to explore code, documentation, and sample inputs/outputs. This course is foundational for any software engineer aiming to master systems programming and develop close-to-hardware software with precision.
