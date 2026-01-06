#include <stdio.h>
#include <array.h>
#include "gaussjordan.h"

// Gauss-Jordan elimination to solve the system of linear equations
arr(double) solve(int n, arr(arr(double)) Matrix) {
    int row = 0;
    int col = 0;
    int num_pivot = 0;

    while (row < n && col < n) {
        int pivot = find_pivot(Matrix, row, col, n);
        
        if (pivot == n) {
            col++;
        } else {
            num_pivot++;
            if (pivot != row) {
                swap_rows(Matrix, row, pivot);
            }
            normalize_pivot_row(Matrix, row, col, n);
            eliminate_rows(Matrix, row, col, n);
            
            row++;
            col++;
        }
    }
    
    arr(double) result = new(double, n + 1);
    if (!has_unique_solution(n, Matrix, num_pivot)) {
        result[0] = 0;
    } else {
        result[0] = 1;
        for (int i = 0; i < n; i++) {
            result[i + 1] = Matrix[i][n];
        }
    }
    return result;
}

// TODO)) Investigate the feasibility.
void swap_rows(arr(arr(double)) Matrix, int r1, int r2) {
    arr(double) temp = Matrix[r1];
    Matrix[r1] = Matrix[r2];
    Matrix[r2] = temp;
}

int find_pivot(arr(arr(double)) Matrix, int start_row, int col, int n) {
    int pivot = start_row;
    while (pivot < n && Matrix[pivot][col] == 0) {
        pivot++;
    }
    return pivot;
}

void normalize_pivot_row(arr(arr(double)) Matrix, int row, int col, int n) {
    double divisor = Matrix[row][col];
    int j = col;
    while (j <= n) {
        Matrix[row][j] = Matrix[row][j] / divisor;
        j++;
    }
}

void eliminate_rows(arr(arr(double)) Matrix, int pivot_row, int col, int n) {
    int k = 0;
    while (k < n) {
        if (k != pivot_row && Matrix[k][col] != 0) {
            double factor = Matrix[k][col];
            int j = col;
            // TODO)) Handle the case when the difference is very small
            while (j <= n) {
                Matrix[k][j] = Matrix[k][j] - factor * Matrix[pivot_row][j];
                j++;
            }
        }
        k++;
    }
}

// Check for unique solution
// A unique solution exists if there are n pivots and no contradictory equations.
// Returns 1 if unique solution exists, 0 otherwise.
int has_unique_solution(int n, arr(arr(double)) Matrix, int num_pivots) {
    if (num_pivots != n) return 0;
    for (int i = num_pivots; i < n; i++) {
        if (Matrix[i][n] != 0) return 0;
    }
    return 1;
}