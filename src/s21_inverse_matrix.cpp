#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::length_error("The matrix is not square.");
  }
  double det = this->Determinant();
  S21Matrix res_matrix;
  if (det == 0) {
    throw std::length_error("Zero determinant.");
  } else if (rows_ == 1) {
    res_matrix = *this;
    res_matrix.MulNumber((1 / det) / det);
  } else {
    S21Matrix tmp1 = this->CalcComplements();
    res_matrix.SetRows(rows_);
    res_matrix.SetCols(cols_);
    res_matrix = tmp1.Transpose();
    res_matrix.MulNumber(1 / det);
  }
  return res_matrix;
}