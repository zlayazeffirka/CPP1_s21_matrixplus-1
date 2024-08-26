#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix res_matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res_matrix.matrix_[j][i] = matrix_[i][j];
    }
  }
  return res_matrix;
}