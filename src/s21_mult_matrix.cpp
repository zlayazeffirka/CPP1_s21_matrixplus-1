#include "s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (other.matrix_ == nullptr || other.rows_ <= 0 || other.cols_ <= 0) {
    throw std::length_error("Incorrect matrix");
  } else if (rows_ != other.cols_ || cols_ != other.rows_) {
    throw std::length_error(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix.");
  } else {
    double **res_matrix = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      res_matrix[i] = new double[other.cols_];
    }
    double res;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        res = 0;
        for (int k = 0; k < cols_; k++) {
          res += matrix_[i][k] * other.matrix_[k][j];
        }
        res_matrix[i][j] = res;
      }
    }
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    cols_ = other.cols_;
    matrix_ = res_matrix;
  }
}