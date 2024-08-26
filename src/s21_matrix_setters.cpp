#include "s21_matrix_oop.h"

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::length_error("Incorrect length");
  }
  double **new_matrix = new double *[rows];
  if (rows >= rows_) {
    for (int i = 0; i < rows; i++) {
      new_matrix[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        if (i < rows_) {
          new_matrix[i][j] = matrix_[i][j];
        } else {
          new_matrix[i][j] = 0.0;
        }
      }
    }
  } else {
    for (int i = 0; i < rows; i++) {
      new_matrix[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }
  }
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  rows_ = rows;
  matrix_ = new_matrix;
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::length_error("Incorrect length");
  }
  double **new_matrix = new double *[rows_];
  if (cols >= cols_) {
    for (int i = 0; i < rows_; i++) {
      new_matrix[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        if (j < cols_) {
          new_matrix[i][j] = matrix_[i][j];
        } else {
          new_matrix[i][j] = 0.0;
        }
      }
    }
  } else {
    for (int i = 0; i < rows_; i++) {
      new_matrix[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }
  }
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  cols_ = cols;
  matrix_ = new_matrix;
}

void S21Matrix::SetData(int i, int j, double data) { matrix_[i][j] = data; }