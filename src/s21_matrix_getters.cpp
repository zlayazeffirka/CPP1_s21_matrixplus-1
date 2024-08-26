#include "s21_matrix_oop.h"

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

double S21Matrix::GetData(int i, int j) { return matrix_[i][j]; }