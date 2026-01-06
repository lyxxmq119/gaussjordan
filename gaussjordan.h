#ifndef GAUSSJORDAN_H
#define GAUSSJORDAN_H

#include "array.h"

arr(double) solve(int n, arr(arr(double)) matrix);
void swap_rows(arr(arr(double)) Matrix, int r1, int r2);
int find_pivot(arr(arr(double)) Matrix, int start_row, int col, int n);
void normalize_pivot_row(arr(arr(double)) Matrix, int row, int col, int n);
void eliminate_rows(arr(arr(double)) Matrix, int pivot_row, int col, int n);
int has_unique_solution(int n, arr(arr(double)) Matrix, int num_pivots);

#endif