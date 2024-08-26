#include "s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->SetRows(other.rows_);
  this->SetCols(other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(double number) {
  S21Matrix tmp(*this);
  tmp.MulNumber(number);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(double number) {
  this->MulNumber(number);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}