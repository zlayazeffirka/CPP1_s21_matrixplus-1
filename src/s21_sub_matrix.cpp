#include "s21_matrix_oop.h"

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (other.matrix_ == nullptr || other.rows_ <= 0 || other.cols_ <= 0) {
    throw std::length_error("Incorrect matrix");
  } else if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::length_error("Different matrix dimensions");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}