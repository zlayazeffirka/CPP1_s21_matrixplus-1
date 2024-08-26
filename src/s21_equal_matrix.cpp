#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool returned_value = true;
  if (rows_ != other.rows_) {
    returned_value = false;
  } else if (cols_ != other.cols_) {
    returned_value = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 0.0000001) {
          returned_value = false;
        }
      }
    }
  }
  return returned_value;
}