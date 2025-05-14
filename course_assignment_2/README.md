# Assignment 2 – Magic Square Validator (`maman12`)

This program was developed as part of **Assignment 2** in the *Systems Programming Lab* course (`20465`) at the Open University of Israel.

## 📌 Assignment Overview

The goal of this assignment is to create a C program that reads a sequence of numbers and determines whether they form a **magic square** — a square matrix where the sum of the numbers in each row, column, and both diagonals is equal, and the numbers are all unique and within the required range (1 to N²).

The program adheres to the **ANSI C90** standard and is written to be compiled using `gcc` on a **Linux (Ubuntu)** environment with the following flags:

```bash
gcc -Wall -ansi -pedantic
```

## 🧠 Key Concepts Practiced

- Reading input from standard input character by character (using `getchar`)
- Input validation, including:
  - Integer range checks
  - Duplicate detection
  - Whitespace and negative number handling
- Modular programming with multiple source/header files
- Matrix handling and formatted output
- Strict error checking and user feedback
- Use of global arrays via `extern`
- Building using a `Makefile` (optional)

## 📁 Project Structure

```
.
├── magic.c                # Main program logic and control flow
├── magicSquare.h          # Constants, global declarations, and function prototypes
├── magicSquare_io.c       # Input parsing, validation, and printing logic
├── magicSquare_test.c     # Core logic to test magic square properties
```

## 🧪 How It Works

### 1. Input Phase
- User is prompted to enter `SIZE * SIZE` numbers between 1 and `SIZE²` (default: 9 numbers for a 3×3 square).
- Input is read character-by-character using `getchar`, with validation for:
  - Only valid integers
  - Correct quantity of numbers
  - No duplicates
  - Valid range (1 to `SIZE²`)

### 2. Matrix Display
- Once valid input is received, the numbers are printed as a matrix.

### 3. Validation Phase
The program checks:
- All numbers are unique and within the expected range.
- The sum of each **row** equals the expected magic sum.
- The sum of each **column** equals the expected magic sum.
- The sum of both **diagonals** equals the expected magic sum.

If all conditions are met, the program prints:

```
This is a magic square!
```

Otherwise, it explains the reasons for failure (e.g., invalid range, row/column/diagonal mismatch, duplicates, etc.).

## 🧮 Examples

### Input1:
```
8 1 6 3 5 7 4 9 2
```

### Output1:
```
inserted numbers (square form) :

8     1     6     
3     5     7     
4     9     2     

This is a magic square!
```
### Input2:
```
1 2 3 4 5 6 7 8 9
```

### Output2:
```
inserted numbers (square form) :

1     2     3     
4     5     6     
7     8     9     

This is not a magic square.


Reasons :
The sum of numbers in each row doesn't equals the magic sum: 15
The sum of numbers in each column doesn't equals the magic sum: 15
The sum of numbers in the diagonals doesn't equals the magic sum: 15
```

## ⚙️ Compilation & Run

Use the following command to compile:

```bash
  gcc -Wall -ansi -pedantic magic.c magicSquare_io.c magicSquare_test.c -o magic
```
or compile by prepared makefile by using following command:

```bash
  make
```

To run the compiled program:

```bash
 ./magic
```

Then follow the on-screen instructions to enter your matrix values.

## 🧾 Notes

- The program uses `#define SIZE 3` in `magicSquare.h` to set the matrix dimensions.
- You can change the matrix size by modifying the `SIZE` macro and recompiling.



## 📜 License

This code was developed by **Ivgeny Tokarzhesky** as part of the Open University coursework. Reuse for educational purposes is allowed.
