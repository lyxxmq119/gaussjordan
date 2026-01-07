# report

## 1.Overview of the algorithm
Our algorithm implenments the Gauss-Jordan elimination algorithm to solve linear systems of linear equations. It performs a series of elementary row operations to transform the matrix into reduced row-echelon form
and determines wehther a given system has unqiue solution or not. 

The algorithm has inputs for the augumented matrix representing a linear system of n equations with n unknowns. In terms of the outputs , if it has unique solution, it outputs a result string desrcibing the solution.If not, it outputs 'no unique solution' indicating either no solution or infinitely many solutions.


## Compile and run instructions
To compile and run the program, use the following commands:
gcc main.c file.c gaussjordan.c strlib.c array.c -o gaussjordan -I .
To run the program:


## 2.Main structure
The algorithm has two main parts:
1. Transform the matrix into reduced row-echelon form by a seies of elementary row operations.
2. Determine whether the system has unqiue solution or not.

// 
## 3.Tracking variables 
#3.1 The state of the matrix includes the following 3 components:
1. 'row': Current position in row
2. 'col': Current position in column
3. 'num_pivot' : The cumulative number of pivot
#3.2 We use 'divisor' and 'factor' to help eliminate the matrix:
1. 'divisor': The original number in the pivot position
2. 'factor' : The original number in a column without the pivot


## 4. Execution process
The execution process has two main parts:

### 4.1 The matrix elimination
We use the 'while' function to construct a loop. In the function, there are three main steps.
1. The first step is to find the pivot by the find_pivot function. In this function , we find the pivot column by column. There are two cases: If 'pivot==n', which means all the entries in the column is 0.Therefore,there is no pivot in the current column and we should move to next column. If not , then it means we have found a pivot in the current column. But we don't know wether the pivot is in the current row. Therefore, if 'pivot!=row' ,we should swap the row to ensure that the pivot is in the current row.
2. The second step is to normalize the pivot by the normalize_pivot_row function. In other words , the step is to let the pivot equals to one. We extract the orignal number of the pivot, then divides it by itself and we will get pivot equal to one.
3. The third step is to eliminate non-pivot entries by the eliminate_rows function. In other words ,the step is to let the entries in the same column to be 0 except the pivot. We will do this step row by row. First extract all the number of the entries . Then let it times the pivot and minus itself respectively,and we will get the entries all be 0 since the pivot has been 1. Then we will do the same step column by column.
### 4.2 The solution judgement
- Infinitely many solutions : This needs to satisfy two conditions : 1.'num_pivot< n' 2. the entry of the corresponding n+1-th column equals to 0.
- No solution : This needs to satisfy two conditions : 1.'num_pivot< n' 2. the entry of the corresponding n+1-th column doesn't equal to 0.
- Unique solution : This needs to satisfy one condition : 1. 'num_pivot==n'. The solution value equals to the n+1-th column row by row. 

We notice that whether the system has a unqiue solution only depends on the number of the pivot. If 'num_pivot==n' , then the systems has a unqiue solution . The solution value equals to the n+1-th column row by row. 
If not , there is no unique solution and the martix must have at least one zero-row. Then there are two cases. In the zero row , if the entry of the corresponding n+1-th column equals to 0, then  the system has infintiely many solutions. If it doesn't equals to 0, then the system has no soultion.




## 5 Input/Output
# 5.1 Input
The type of the inputs should be double. Therefore, we need process the decimals by build_double function. We first search the space to split n real numbers. Then we should extract the string in each slice. We will do this by using 'start' and 'end'. The 'start' is the beginning of the slice and the 'end' is the position of the space. These two items help to find and fix the position of the string. Moreover , we can use the slice function to extract the string from 'start' to 'end'. After once extraction , the position of the 'start' will be 'end+1' to ensure that it is the beginning of the next string we need. Now we have got the string of one split number and we need to transform the string into the corresponding  number. Therefore,We will use the str2double function. After all the step , we can process the decimals.
# 5.2 Output
We will generate the output use the 'for' function to construct a loop. We will extract the solution value row by row and add a space between two values. After doing the loop n times ,we will get the whole output . After we have already print the output ,we printf'\n' to build a new line.

## 6 List of functions
- int main(int argc, arr(str) argv):Parses command-line arguments as integers and strings, then creates two integer arrays representing a matrix. It processes these inputs through the solve function to generate a list of real numbers, which is printed before freeing allocated memory.
- arr(double) solve(int n, arr(arr(double)) Matrix) : The core algorithm function.
- int find_pivot(Matrix, row, col, n) :Find the pivot in a given column starting from a given row.
- void swap_rows(arr(arr(double)) Matrix, int n, int r1, int r2)：Swaps two rows in the matrix.
- void normalize_pivot_row(arr(arr(double)) Matrix, int row, int col, int n)：Divide the pivot row by the pivot element to make the pivot equal to 1.
- void eliminate_rows(arr(arr(double)) Matrix, int pivot_row, int col, int n)：Eliminate the current column from all other rows using the pivot row.
- void printda(arr(double) a, int n)：Print an array of doubles .
- arr(double) build_double(str s, int n)：Transform a string containing n space-separated real numbers into an array of doubles.
- arr(double) str2double(str s , int n):Transform a string to a double.
- str slice(str s, int start, int end) :Extract a substring from a string.
- int len(str sentence) : Return the length of a string.
- int search(str sentence, int i, char c): Searche for a character in a string starting from a given index.
- file new_file(str path): Open a file for reading.
- int has_next_line(file f):Check if there is a next line in the file.
- str get_next_line(file f): Read the next line from the file.


## 6 Test execution
There are three cases : unique solution, no solution and infinitely many solutions 
# 6.1 Unique solution


