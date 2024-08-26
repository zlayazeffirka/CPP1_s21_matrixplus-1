#include "s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::length_error("The matrix is not square.");
  } else if (rows_ == 1) {
    throw std::length_error("Matrix is 1x1");
  }
  S21Matrix res_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor(rows_ - 1, cols_ - 1);
      get_minor(*this, i, j, &minor);
      double tmp_det = minor.Determinant();
      res_matrix.matrix_[i][j] = tmp_det * pow(-1, i + j);
    }
  }
  return res_matrix;
}