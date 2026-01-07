# Report

## 1. Project Information
**Team Members:**
*   **Congyi Mai (800014359)**: Adjusted pseudo-code, implemented the algorithm, assigned tasks, and finalized the project (including the report).
*   **Yuexuan Li (800017337)**: Drafted the initial pseudo-code.
*   **Yunpu Liu (800018715)**: Drafted the report based on the pseudo-code and implementation.

## 2. Overview of the algorithm

We implemented the Gauss-Jordan elimination algorithm to solve linear systems of linear equations (n equations with n unknowns). It performs a series of elementary row operations to transform the matrix into its reduced row-echelon form and determines whether a given system has a unique solution or not. 

The program takes an augmented matrix representing a linear system of n equations with n unknowns as input. If the system has a unique solution, it outputs a result string describing the solution. If not, it outputs `no unique solution`, which covers cases of either no solution or infinitely many solutions.

## 3. Algorithm Design
We design the algorithm follong the the Gauss-Jordan elimination process. The algorithm is describe in `fun solve(n: num, Matrix: arr(arr(num))) -> result: arr(num)`. The functions repeatedly performs the elimination process until the it has reduced the entire matrix. We designed some helper functions to improve readablity. These functions are called one by one in each elimination step.

### 3.1 Pivot Searching and Row Swapping

We design a `find_pivot` function that helps us to find the pivot in the elimination process. This is used in each step of the elimination process. The function goes through the current column (`col`) starting from `start_row` to find the first row with a non-zero element. This non-zero element will serve as the pivot. Here, the function ignore the rows before `start_row` because we assume that they are already reduced and can not be used for pivot row again. 
If the function finds a pivot, it returns the index of the pivot row. If no pivot is found, it returns n, the total number of rows.

```plaintext
// Finds the first rows that contains a non-zero element in the col-th column, starting from start_row
fun find_pivot(Matrix: arr(arr(num)), start_row: num, col: num, n: num) -> pivot: num
!   require: Matrix is a n*(n+1) array ^ 0 <= start_row <= n ^ 0 <= col <= n ^ len(Matrix) = n

    // Finds the first row >= start_row that has a non-zero value in the specified column
    pivot := start_row
    while pivot < n and Matrix[pivot][col] == 0 do
    !   invariant: Matrix[k][col] == 0 for all k, start_row <= k < pivot
        pivot := pivot + 1

!   ensure: start_row <= pivot <= n ^ (pivot < n => Matrix[pivot][col] != 0) ^ (Matrix[k][col] == 0 for all k in [start_row, pivot))
```

If the pivot belongs to a row different from the current `start_row`, we need to bring it the the current position. Therefore we design the `swap_rows` function to interchange the rows. The function swaps the values in the two rows one by one, with a loop variable i to go through the columns.

```
// Swaps row r1 and row r2 in the matrix
fun swap_rows(Matrix: arr(arr(num)), n: num, r1: num, r2: num)
!   require: Matrix is a n*(n+1) array ^ 0 <= r1 < len(Matrix) ^ 0 <= r2 < len(Matrix)

    for every i in [0:n+1) do
        temp := Matrix[r1][i]
        Matrix[r1][i] := Matrix[r2][i]
        Matrix[r2][i] := temp

!   ensure: the r1-th and r2-th rows are switched
```

### 3.2 Row Normalization
After finding the pivot and putting it to the current position, we need to make the pivot value one, without affecting the same solution set. Hence, we need to divide each of the element in the selected pivot row by the value of the leading element (which is not 0). Here, `col` is the location of the pivot and we uses a for-loop to divide the elements with loop-variable j going from col to n. Note that we ignore the elements before the `col`, the pivot, because they are zeros.

```plaintext
fun normalize_pivot_row(Matrix: arr(arr(num)), row: num, col: num, n: num)
!   require: Matrix is a n*(n+1) array ^ 0 <= row < n ^ 0 <= col <= n ^ Matrix[row][col] != 0 ^ Matrix[row][j] = 0 for all j in [0, col)

    // Normalize the pivot row so the pivot becomes 1
    divisor := Matrix[row][col]
    for every j in [col, n) do
    !   invariant: col <= j <= n + 1 ^ for all k in [col, j), Matrix[row][k] is divided by divisor
        Matrix[row][j] := Matrix[row][j] / divisor

!   ensure: Matrix[row][col] = 1 ^ (Matrix[row][k] is divided by the original value of Matrix[row][col] for all k in [col+1, n])
```

### 3.3 Elimination of Variables
After normalizing the pivot row, it is used to eliminate the other elements in the pivot column. For every row `k` (where `k != pivot_row`), we calculate a `factor` based on its value in the current column. We then update row `k` by subtracting `factor` times the pivot row.
This operation corresponds to adding a multiple of one equation to another. This is an elementary row operation that preserves the solution set.

```plaintext
fun eliminate_rows(Matrix: arr(arr(num)), pivot_row: num, col: num, n: num)
!   require: Matrix is a n*(n+1) array ^ 0 <= pivot_row < n ^ 0 <= col <= n ^ Matrix[pivot_row][col] = 1 
    ^ Matrix[pivot_row][j] = 0 for all 0<=j<col

    // Eliminate entries in other rows in the current column
    k := 0
    while k < n do
    !   invariant: 0 <= k <= n ^ Matrix[r][col] = 0 for all 0<=r<k and r!=pivot_row
        if k != pivot_row and Matrix[k][col] != 0 then
            factor := Matrix[k][col]
            j := col
            while j <= n do
            !   invariant: col <= j <= n + 1 ^ Matrix ^ Matrix[k][c] is proceded for all 0<=c<j
                Matrix[k][j] := Matrix[k][j] - factor * Matrix[pivot_row][j]
                j := j + 1
        k := k + 1

!   ensure: Matrix[k][col] = 0 for all k in [0, n), k != pivot_row
```

### 3.4 Full Solver Logic
Finally, we can look at the full image of the solver. 

Here, the `solve` function orchestrates the entire process. It takes two inputs: an natural number `n` representing the number of equation, and the augmented matrix (n*(n*1)) stored as a 2-dimensional array of real numbers.

The returning value is an array of real numbers with length n+1, `result`, where the first element of `result` is an indicator of result type:
- `result[0] = 1`: The system has is a unique solution and `result[1:n]` (inclusive) is the values in the solution, in order
- `result[0] = 0`: The system has no solution, or has infinitely many solutions. In this cases `result[1:n]` (inclusive) has no meaning.

```plaintext
fun solve(n: num, Matrix: arr(arr(num))) -> result: arr(num)
!   require: Matrix[k][col] = 0 ^ n > 0 ^ len(Matrix) = n ^ len(Matrix[i]) = (n + 1) for all 0<=i<n

    // Initial state
    row := 0
    col := 0
    num_pivot := 0
    
    // Gauss-Jordan Elimination
    while row < n and col < n do
    !   invariant: Matrix is in reduced row echelon form for the processed rows and columns
                  ^ 0 <= row <= n ^ 0 <= col <= n
        
        pivot := find_pivot(Matrix, row, col, n)
            
        if pivot == n then
            // No pivot in this column, move to next column
            col := col + 1 
        else
            num_pivot := num_pivot + 1
            // Swap rows to bring the pivot to the current row
            if pivot != row then
                swap_rows(Matrix, n, row, pivot)
            
            normalize_pivot_row(Matrix, row, col, n)
            eliminate_rows(Matrix, row, col, n)
            
            row := row + 1
            col := col + 1

    // Determine the result type and construct the returning array
    result := []
    if num_pivot < n then
        result[0] = 0
    else
        result[0] = 1
        // construct the result
        for every i in [0, n) do
            result[i+1] := Matrix[i][n]

!   ensure: len(result) = n+1 ^ (result[0]=1 ^ result[1:n] is a solution for the system) iff the system has a unique solution ^ (result[0]=0 iff the system has no or infinitely many solutions)
```

The solver consists of two main components:
1. Transform the matrix into reduced row-echelon form by a seies of elementary row operations. The function iterates through the matrix, finding pivots, normalizing rows, and eliminating entries. At the same time, it counts the number of pivots found.

2. Determine whether the system has unqiue solution or not. This is based on the number of pivots.
    - If `num_pivot == n`, the matrix is invertible, and we can uniquely determine each variable from the last column ($Matrix[i][n]$).
    - If `num_pivot < n`, the effective rank is less than $n$. This means either the system is inconsistent (no solution) or has free variables (infinite solutions).

Mathematical explanation
In a system of $n$ equations with $n$ variables, solving it may end up in three types of situations:
- The system has a unique solution: The matrix is invertible and thus the it has $n$ pivots
- The system has no soluion: The row-reduced echelon form of the matrix has a row where all coefficients are zero and the constant is not zero. In this case, the number of pivots is less then n.
- The systhem has infinitely many solutions: The row-reduced echelon form of the matrix has a row where all coefficients are zero and the constant is also zero. In this case, the number of pivots is less then n.

Therefore, the system has a unique solution exists if and only if the coefficient matrix has $n$ pivots. In our algorithm, this corresponds to finding exactly $n$ pivots (`num_pivot == n`). 

## 4. Implementation Details

### 4.1 Main Structure
The implementation follows the design closely, separating the elimination logic from the judgment logic. The main loop ensures that each column is processed, and the matrix is transformed in place.

### 4.2 List of Functions
The implementation is modularized across several files:

**`gaussjordan.c`**
-   `solve`: The driver function.
-   `find_pivot`, `swap_rows`, `normalize_pivot_row`, `eliminate_rows`: Helper functions for row operations.

**`strlib.c` & `array.c`**
-   `build_double`: Input parsing (string -> double array).
-   `slice`, `search`: String utility functions.

**`main.c`**
-   `main`: Entry point handling file I/O and result printing.

### 4.3 Input Parsing
**Design Evolution:**
At first, we thought we needed to implement `str2dou` with manual decimal parsing (as shown in early pseudo-code drafts). However, we later realized that using `slice` combined with the standard library function `atof` (ASCII to float) is much more efficient and less error-prone. We adopted this improved approach in the final implementation.

**Pseudo-code for Input Parsing:**
```plaintext
fun build_double(s: str, n: num) -> result: arr(num)
!   require: s contains n real numbers separated by one space

    result := [] // new array of length n
    
    start := 0
    for every i in [0, n) do
    !   invariant: result[0:i) matches the first i+1 real numbers in s
        end := search(s, start, ' ')
        result[i] := str2double(s[start:end)) // s[start:end) excludes the ending whitespace
        start := end + 1

!   ensure: result contains the n parsed numbers in order
```

## 5. Compile and run instructions

To compile and run the program, use the following commands:

`gcc main.c file.c gaussjordan.c strlib.c array.c -o gaussjordan -I .`

To run the program:

`./gaussjordan <input_file>`

## 6. Test Execution

### 6.1 Test Suite Description
We designed a comprehensive test suite to cover various scenarios:
1.  **Unique Solution**: Square systems with full rank.
2.  **No Unique Solution**: Inconsistent systems and systems with infinite solutions.
3.  **Edge Cases**: Zero pivots requiring swaps, and numerical stability cases.

### 6.2 Example Executions

**Case 1: Unique Solution (`test_2x2.txt`)**
Command: `./gaussjordan test_2x2.txt`
Input:
```
2
2 1 5
1 1 3
```
Execution Trace:
1.  **Start**: `row=0, col=0`. `find_pivot` selects row 0 (value 2).
2.  **Normalize**: Row 0 becomes `1 0.5 2.5`.
3.  **Eliminate**: Eliminate Row 1 using Row 0. Row 1 becomes `0 0.5 0.5`.
4.  **Next**: `row=1, col=1`. `find_pivot` selects row 1 (value 0.5).
5.  **Normalize**: Row 1 becomes `0 1 1`.
6.  **Eliminate**: Eliminate Row 0 using Row 1. Row 0 becomes `1 0 2`.
7.  **Result**: `num_pivot` is 2. Solution vector is derived from the last column: `2 1`.
Output: `2 1`

**Case 2: Inconsistent System (`test_inconsistent.txt`)**
Command: `./gaussjordan test_inconsistent.txt`
Input:
```
2
1 1 2
1 1 3
```
Execution Trace:
1.  **Start**: `row=0, col=0`. `find_pivot` selects row 0.
2.  **Normalize**: Row 0 becomes `1 1 2`.
3.  **Eliminate**: Row 1 becomes `0 0 1`.
4.  **Next**: `col=1`. `find_pivot` finds no non-zero pivot for column 1 in remaining rows.
5.  **Finish**: `num_pivot` remains 1. Since `num_pivot (1) < n (2)`, the system has no unique solution.
Output: `no unique solution`


