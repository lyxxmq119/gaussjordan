# Report

## 1. Overview of the algorithm

Our algorithm implements the Gauss-Jordan elimination method to solve a system of linear equations represented as an augmented matrix. The process transforms the matrix into reduced row echelon form (RREF) to identify the solution.

The algorithm determines if the system has a unique solution, no solution (inconsistent), or infinitely many solutions.
If the system has a unique solution, it outputs the values of the variables. Otherwise, it reports "no unique solution".

## 2. Compile and run instructions

To compile and run the program, use the following commands:

gcc --std=c99 -o gaussjordan main.c gaussjordan.c file.c strlib.c array.c -I.

To run the program:
./gaussjordan <input_file>

Example:
./gaussjordan test.txt

## 3. Main structure

The program consists of two main parts:
1.  **Parsing**: Reading the input file `main.c` parses the number of unknowns `n` and the augmented matrix entries.
2.  **Solving**: `gaussjordan.c` implements the Gauss-Jordan elimination.
    *   **Elimination**: Iterates through columns to find pivots, swaps rows (partial pivoting), and eliminates entries above and below the pivot.
    *   **Solution Analysis**: After reduction, the algorithm checks for consistency (e.g., a row like `[0 0 ... 0 | non-zero]`) and verifies that the rank equals the number of variables (no free variables).

## 4. Key concepts and Variables

*   **Matrix Representation**: The matrix is stored as an array of rows (`double**` via `typedef`), which allows efficient row swapping.
*   **Pivot Selection**: In each step `k`, we select the row `i >= k` maximizing `|A[i][k]|`.
*   **Epsilon**: A small value (`1e-9`) is used for floating-point comparisons to determine if a value is effectively zero.
*   **Invariants**: The algorithm maintains that after processing column `j`, the top `j+1` rows form a reduced row echelon structure for the first `j+1` columns.
