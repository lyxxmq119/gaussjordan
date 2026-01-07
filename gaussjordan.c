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
                swap_rows(Matrix, n, row, pivot);
            }
            normalize_pivot_row(Matrix, row, col, n);
            eliminate_rows(Matrix, row, col, n);
            
            row++;
            col++;
        }
    }
    
    arr(double) result = new(double, n + 1);
    if (num_pivot < n) {
        result[0] = 0;
    } else {
        result[0] = 1;
        for (int i = 0; i < n; i++) {
            result[i + 1] = Matrix[i][n];
        }
    }
    return result;
}

void swap_rows(arr(arr(double)) Matrix, int n, int r1, int r2) {
    for (int j = 0; j < n + 1; j++) {
        double temp = Matrix[r1][j];
        Matrix[r1][j] = Matrix[r2][j];
        Matrix[r2][j] = temp;
    }
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
    for (int j = col; j <= n; j++) {
        Matrix[row][j] = Matrix[row][j] / divisor;
    }
}

void eliminate_rows(arr(arr(double)) Matrix, int pivot_row, int col, int n) {
    int k = 0;
    while (k < n) {
        if (k != pivot_row && Matrix[k][col] != 0) {
            double factor = Matrix[k][col];
            int j = col;
            while (j <= n) {
                Matrix[k][j] = Matrix[k][j] - factor * Matrix[pivot_row][j];
                j++;
            }
        }
        k++;
    }
}

