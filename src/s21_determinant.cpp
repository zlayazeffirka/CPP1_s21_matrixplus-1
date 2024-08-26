#include "s21_matrix_oop.h"

int get_minor(S21Matrix A, int i, int j, S21Matrix *minor) {
  for (int l = 0; l < i; ++l) {
    for (int k = 0; k < A.GetCols(); ++k) {
      if (k < j) {
        minor->SetData(l, k, A.GetData(l, k));
      } else if (k > j) {
        minor->SetData(l, k - 1, A.GetData(l, k));
      }
    }
  }
  for (int l = i + 1; l < A.GetRows(); ++l) {
    for (int k = 0; k < A.GetCols(); ++k) {
      if (k < j) {
        minor->SetData(l - 1, k, A.GetData(l, k));
      } else if (k > j) {
        minor->SetData(l - 1, k - 1, A.GetData(l, k));
      }
    }
  }
  return 0;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::length_error("The matrix is not square.");
  }
  double det = 0.0;
  if (rows_ == 1) {
    det = matrix_[0][0];
  } else if (rows_ == 2) {
    det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix minor(rows_ - 1, cols_ - 1);
      get_minor(*this, 0, j, &minor);
      double result1 = minor.Determinant();
      det += pow(-1, j) * matrix_[0][j] * result1;
    }
  }
  return det;
}