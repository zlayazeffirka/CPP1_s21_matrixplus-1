// #ifndef S21_MATRIX
// #define S21_MATRIX

#include <cmath>
#include <iostream>

class S21Matrix {
  int rows_;
  int cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  int GetRows();
  int GetCols();
  double GetData(int i, int j);

  void SetRows(int rows);
  void SetCols(int cols);
  void SetData(int i, int j, double data);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix& operator=(const S21Matrix& other);   //
  bool operator==(const S21Matrix& other);        //
  S21Matrix operator+(const S21Matrix& other);    //
  S21Matrix& operator+=(const S21Matrix& other);  //
  S21Matrix operator-(const S21Matrix& other);    //
  S21Matrix& operator-=(const S21Matrix& other);  //
  S21Matrix operator*(double number);             //
  S21Matrix& operator*=(double number);           //
  S21Matrix operator*(const S21Matrix& other);    //
  S21Matrix& operator*=(const S21Matrix& other);  //
  double& operator()(int row, int col);
};
int get_minor(S21Matrix A, int i, int j, S21Matrix* minor);
