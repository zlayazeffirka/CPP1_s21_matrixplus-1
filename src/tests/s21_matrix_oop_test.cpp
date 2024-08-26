#include "../s21_matrix_oop.h"

#include <gtest/gtest.h>

class S21MatrixTest : public ::testing::Test {};

TEST(Constructor_basic, test_1) {
  S21Matrix a;
  ASSERT_EQ(a.GetCols(), 0);
  ASSERT_EQ(a.GetRows(), 0);
}

TEST(MatrixTest, CheckRows) {
  S21Matrix mtr(5, 3);
  ASSERT_TRUE(mtr.GetRows() == 5);
}

TEST(Constructor_copying, test_1) {
  S21Matrix M(5, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 2;
    }
  }
  S21Matrix M2 = M;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), M2(i, j));
    }
  }
}

TEST(Constructor_moving, test_1) {
  S21Matrix m1(2, 3);
  S21Matrix m2 = m1;
  S21Matrix m3(std::move(m1));

  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 3);

  EXPECT_EQ(m3.GetRows(), 2);
  EXPECT_EQ(m3.GetCols(), 3);
}

TEST(Method_EqMatrix, test_1) {
  S21Matrix M(3, 3);
  S21Matrix M2(2, 2);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 3;
    }
  }
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 3;
    }
  }
  ASSERT_EQ(M.EqMatrix(M2), 0);
}

TEST(Method_EqMatrix, test_3) {
  S21Matrix M(3, 3);
  S21Matrix M2(3, 3);
  M(0, 0) = 123;
  M(0, 1) = 123;
  M(0, 2) = 123;

  M(1, 0) = 123;
  M(1, 1) = 129;
  M(1, 2) = 123;

  M(2, 0) = 123;
  M(2, 1) = 123;
  M(2, 2) = 123;

  M2(0, 0) = 123;
  M2(0, 1) = 123;
  M2(0, 2) = 123;

  M2(1, 0) = 123;
  M2(1, 1) = 123;
  M2(1, 2) = 123;

  M2(2, 0) = 123;
  M2(2, 1) = 123;
  M2(2, 2) = 123;

  ASSERT_EQ(M.EqMatrix(M2), 0);
}

TEST(Method_SumMatrix, test_1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2 = M;
  M.SumMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 20);
    }
  }
}

TEST(Method_SumMatrix, test_2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 150.5;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150.5;
    }
  }
  M.SumMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 301);
    }
  }
}

TEST(Method_SumMatrix, test_3) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2(7, 7);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 10;
    }
  }
  ASSERT_ANY_THROW(M.SumMatrix(M2));
}

TEST(Method_SumMatrix, test_4) {
  S21Matrix M(3, 3);
  M(0, 0) = 50.34;
  M(0, 1) = 4654.453;
  M(0, 2) = 345;

  M(1, 0) = 56.563;
  M(1, 1) = 56.345;
  M(1, 2) = 456;

  M(2, 0) = 345;
  M(2, 1) = 433;
  M(2, 2) = 3345;

  S21Matrix M2(3, 3);
  M2(0, 0) = 345;
  M2(0, 1) = 68;
  M2(0, 2) = 345;

  M2(1, 0) = -456.56;
  M2(1, 1) = -345;
  M2(1, 2) = 86;

  M2(2, 0) = -456.5;
  M2(2, 1) = 57;
  M2(2, 2) = 0.987;

  M.SumMatrix(M2);
  ASSERT_DOUBLE_EQ(M(0, 0), 395.34);
  ASSERT_DOUBLE_EQ(M(0, 1), 4722.453);
  ASSERT_DOUBLE_EQ(M(0, 2), 690);
  ASSERT_DOUBLE_EQ(M(1, 0), -399.997);
  ASSERT_DOUBLE_EQ(M(1, 1), -288.655);
  ASSERT_DOUBLE_EQ(M(1, 2), 542);
  ASSERT_DOUBLE_EQ(M(2, 0), -111.5);
  ASSERT_DOUBLE_EQ(M(2, 1), 490);
  ASSERT_DOUBLE_EQ(M(2, 2), 3345.987);
}

TEST(Method_SumMatrix, test_5) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2(6, 7);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 10;
    }
  }
  ASSERT_ANY_THROW(M.SumMatrix(M2));
}

TEST(Method_SubMatrix, test_1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 347.475;
    }
  }
  S21Matrix M2 = M;
  M.SubMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 0);
    }
  }
}

TEST(Method_SubMatrix, test_2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 374729.342;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150342.5425;
    }
  }
  M.SubMatrix(M2);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 224386.7995);
    }
  }
}

TEST(Method_SubMatrix, test_3) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2(7, 7);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 10;
    }
  }
  ASSERT_ANY_THROW(M.SubMatrix(M2));
}

TEST(Method_SubMatrix, test_4) {
  S21Matrix M(3, 3);
  M(0, 0) = 234;
  M(0, 1) = 5698;
  M(0, 2) = 23716;

  M(1, 0) = 682812.487;
  M(1, 1) = 21234;
  M(1, 2) = 3459877.34875;

  M(2, 0) = 23587.3487;
  M(2, 1) = 1.2345;
  M(2, 2) = 13.3452;

  S21Matrix M2(3, 3);
  M2(0, 0) = 123874;
  M2(0, 1) = 2387;
  M2(0, 2) = -3846;

  M2(1, 0) = 23948.3472;
  M2(1, 1) = 0.98762;
  M2(1, 2) = 123.23;

  M2(2, 0) = 696387.12;
  M2(2, 1) = 343.43;
  M2(2, 2) = 9999.9999;

  M.SubMatrix(M2);
  ASSERT_DOUBLE_EQ(M(0, 0), -123640);
  ASSERT_DOUBLE_EQ(M(0, 1), 3311);
  ASSERT_DOUBLE_EQ(M(0, 2), 27562);
  ASSERT_DOUBLE_EQ(M(1, 0), 658864.1398);
  ASSERT_DOUBLE_EQ(M(1, 1), 21233.01238);
  ASSERT_DOUBLE_EQ(M(1, 2), 3459754.11875);
  ASSERT_DOUBLE_EQ(M(2, 0), -672799.7713);
  ASSERT_DOUBLE_EQ(M(2, 1), -342.1955);
  ASSERT_DOUBLE_EQ(M(2, 2), -9986.6547);
}

TEST(Method_SubMatrix, test_5) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2(6, 7);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 10;
    }
  }
  ASSERT_ANY_THROW(M.SubMatrix(M2));
}

TEST(Method_SubMatrix, test_6) {
  S21Matrix M(6, 6);
  S21Matrix M1;
  ASSERT_ANY_THROW(M.SubMatrix(M1));
}

TEST(Method_MulNumber, test_1) {
  S21Matrix M(5, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  M.MulNumber(9);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 342);
    }
  }
}

TEST(Method_MulNumber, test_2) {
  S21Matrix M(3, 3);
  M(0, 0) = 50.34;
  M(0, 1) = 4654.453;
  M(0, 2) = 345;

  M(1, 0) = 56.563;
  M(1, 1) = 56.345;
  M(1, 2) = 456;

  M(2, 0) = 345;
  M(2, 1) = 433;
  M(2, 2) = 3345;
  M.MulNumber(178);

  ASSERT_DOUBLE_EQ(M(0, 0), 8960.52);
  ASSERT_DOUBLE_EQ(M(0, 1), 828492.634);
  ASSERT_DOUBLE_EQ(M(0, 2), 61410);
  ASSERT_DOUBLE_EQ(M(1, 0), 10068.214);
  ASSERT_DOUBLE_EQ(M(1, 1), 10029.41);
  ASSERT_DOUBLE_EQ(M(1, 2), 81168);
  ASSERT_DOUBLE_EQ(M(2, 0), 61410);
  ASSERT_DOUBLE_EQ(M(2, 1), 77074);
  ASSERT_DOUBLE_EQ(M(2, 2), 595410);
}

TEST(Method_MulMatrix, test_1) {
  S21Matrix M(4, 5);
  S21Matrix M2(4, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
      M2(i, j) = 25;
    }
  }
  ASSERT_ANY_THROW(M.MulMatrix(M2));
}

TEST(Method_MulMatrix, test_2) {
  S21Matrix M(4, 5);
  S21Matrix M2(5, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 12;
    }
  }
  M.MulMatrix(M2);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 2280);
    }
  }
}

TEST(Method_MulMatrix, test_3) {
  S21Matrix M(4, 5);
  S21Matrix M2(5, 4);
  M(0, 0) = 38;
  M(0, 1) = 45.56;
  M(0, 2) = 12.484;
  M(0, 3) = 17892;
  M(0, 4) = 41.54;

  M(1, 0) = 12.1;
  M(1, 1) = 0.999;
  M(1, 2) = 99;
  M(1, 3) = 9;
  M(1, 4) = 12.4;

  M(2, 0) = 0.154;
  M(2, 1) = 0.487;
  M(2, 2) = 4110.4;
  M(2, 3) = 12;
  M(2, 4) = 38;

  M(3, 0) = 45.58;
  M(3, 1) = 0.1;
  M(3, 2) = 0.12;
  M(3, 3) = 38;
  M(3, 4) = 3825;

  M2(0, 0) = 0;
  M2(0, 1) = 14;
  M2(0, 2) = 1;
  M2(0, 3) = 85.2;

  M2(1, 0) = 1.254;
  M2(1, 1) = 13.544;
  M2(1, 2) = 12;
  M2(1, 3) = 1;

  M2(2, 0) = 148;
  M2(2, 1) = 58;
  M2(2, 2) = 698;
  M2(2, 3) = 1.1235;

  M2(3, 0) = 125;
  M2(3, 1) = 48;
  M2(3, 2) = 75.1;
  M2(3, 3) = 2.25;

  M2(4, 0) = 12.5;
  M2(4, 1) = 51;
  M2(4, 2) = 34;
  M2(4, 3) = 12;

  M.MulMatrix(M2);
  ASSERT_DOUBLE_EQ(M(0, 0), 2238924.01424);
  ASSERT_DOUBLE_EQ(M(0, 1), 862807.67664);
  ASSERT_DOUBLE_EQ(M(0, 2), 1354400.112);
  ASSERT_DOUBLE_EQ(M(0, 3), 44052.665774);

  ASSERT_DOUBLE_EQ(M(1, 0), 15933.252746);
  ASSERT_DOUBLE_EQ(M(1, 1), 6989.330456);
  ASSERT_DOUBLE_EQ(M(1, 2), 70223.588);
  ASSERT_DOUBLE_EQ(M(1, 3), 1312.1955);

  ASSERT_DOUBLE_EQ(M(2, 0), 610314.810698);
  ASSERT_DOUBLE_EQ(M(2, 1), 240925.951928);
  ASSERT_DOUBLE_EQ(M(2, 2), 2871258.398);
  ASSERT_DOUBLE_EQ(M(2, 3), 5114.6422);

  ASSERT_DOUBLE_EQ(M(3, 0), 52580.3854);
  ASSERT_DOUBLE_EQ(M(3, 1), 197545.4344);
  ASSERT_DOUBLE_EQ(M(3, 2), 133034.34);
  ASSERT_DOUBLE_EQ(M(3, 3), 49869.15082);
}

TEST(Method_Transpose, test_1) {
  int rows_ = 9;
  int cols_ = 3;
  S21Matrix M(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      M(i, j) = 38;
    }
  }

  S21Matrix M2 = M.Transpose();

  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      ASSERT_DOUBLE_EQ(M2(i, j), 38);
    }
  }
}

TEST(Method_Transpose, test_2) {
  S21Matrix M(3, 3);
  M(0, 0) = 23;
  M(0, 1) = 76;
  M(0, 2) = 54;

  M(1, 0) = 98;
  M(1, 1) = 578;
  M(1, 2) = 6;

  M(2, 0) = 9;
  M(2, 1) = 2;
  M(2, 2) = 6;
  S21Matrix M2 = M.Transpose();

  ASSERT_DOUBLE_EQ(M2(0, 0), 23);
  ASSERT_DOUBLE_EQ(M2(0, 1), 98);
  ASSERT_DOUBLE_EQ(M2(0, 2), 9);

  ASSERT_DOUBLE_EQ(M2(1, 0), 76);
  ASSERT_DOUBLE_EQ(M2(1, 1), 578);
  ASSERT_DOUBLE_EQ(M2(1, 2), 2);

  ASSERT_DOUBLE_EQ(M2(2, 0), 54);
  ASSERT_DOUBLE_EQ(M2(2, 1), 6);
  ASSERT_DOUBLE_EQ(M2(2, 2), 6);
}

TEST(Method_Transpose, test_3) {
  S21Matrix M(1, 1);
  M(0, 0) = 79;
  S21Matrix M2 = M.Transpose();
  ASSERT_DOUBLE_EQ(M2(0, 0), 79);
}

TEST(Method_CalcComplements, test_1) {
  S21Matrix M(3, 3);
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;

  M(1, 0) = 0;
  M(1, 1) = 4;
  M(1, 2) = 2;

  M(2, 0) = 5;
  M(2, 1) = 2;
  M(2, 2) = 1;

  S21Matrix M2 = M.CalcComplements();
  ASSERT_DOUBLE_EQ(M2(0, 0), 0);
  ASSERT_DOUBLE_EQ(M2(0, 1), 10);
  ASSERT_DOUBLE_EQ(M2(0, 2), -20);

  ASSERT_DOUBLE_EQ(M2(1, 0), 4);
  ASSERT_DOUBLE_EQ(M2(1, 1), -14);
  ASSERT_DOUBLE_EQ(M2(1, 2), 8);

  ASSERT_DOUBLE_EQ(M2(2, 0), -8);
  ASSERT_DOUBLE_EQ(M2(2, 1), -2);
  ASSERT_DOUBLE_EQ(M2(2, 2), 4);
}

TEST(Method_CalcComplements, test_2) {
  S21Matrix M(3, 2);
  M(0, 0) = 1;
  M(0, 1) = 2;

  M(1, 0) = 0;
  M(1, 1) = 4;

  M(2, 0) = 5;
  M(2, 1) = 2;

  ASSERT_ANY_THROW(M.CalcComplements());
}

TEST(Method_CalcComplements, test_3) {
  S21Matrix M(1, 1);
  M(0, 0) = 1;

  ASSERT_ANY_THROW(M.CalcComplements());
}

TEST(Method_Determinant, test_1) {
  S21Matrix M(4, 4);
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 4;

  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 3;
  M(1, 3) = 2;

  M(2, 0) = 5;
  M(2, 1) = 6;
  M(2, 2) = 6;
  M(2, 3) = 7;

  M(3, 0) = 9;
  M(3, 1) = 4;
  M(3, 2) = 1;
  M(3, 3) = 6;
  double res = M.Determinant();
  ASSERT_NEAR(res, -46.0, 0.00000001);
}

TEST(Method_Determinant, test_2) {
  S21Matrix M(4, 3);
  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;

  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 3;

  M(2, 0) = 5;
  M(2, 1) = 6;
  M(2, 2) = 6;

  M(3, 0) = 9;
  M(3, 1) = 4;
  M(3, 2) = 1;
  ASSERT_ANY_THROW(M.Determinant());
}

TEST(Method_InverseMatrix, test_1) {
  S21Matrix M(3, 3);
  M(0, 0) = 2;
  M(0, 1) = 5;
  M(0, 2) = 7;
  M(1, 0) = 6;
  M(1, 1) = 3;
  M(1, 2) = 4;
  M(2, 0) = 5;
  M(2, 1) = -2;
  M(2, 2) = -3;

  S21Matrix M2 = M.InverseMatrix();

  ASSERT_DOUBLE_EQ(M2.GetRows(), 3);
  ASSERT_DOUBLE_EQ(M2.GetCols(), 3);

  ASSERT_DOUBLE_EQ(M2(0, 0), 1);
  ASSERT_DOUBLE_EQ(M2(0, 1), -1);
  ASSERT_DOUBLE_EQ(M2(0, 2), 1);

  ASSERT_DOUBLE_EQ(M2(1, 0), -38);
  ASSERT_DOUBLE_EQ(M2(1, 1), 41);
  ASSERT_DOUBLE_EQ(M2(1, 2), -34);

  ASSERT_DOUBLE_EQ(M2(2, 0), 27);
  ASSERT_DOUBLE_EQ(M2(2, 1), -29);
  ASSERT_DOUBLE_EQ(M2(2, 2), 24);
}

TEST(Method_InverseMatrix, test_2) {
  S21Matrix M(5, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 0;
    }
  }
  ASSERT_ANY_THROW(M.InverseMatrix());
}

TEST(Method_InverseMatrix, test_3) {
  S21Matrix M;
  ASSERT_ANY_THROW(M.InverseMatrix());
}

TEST(Method_InverseMatrix, test_4) {
  S21Matrix M(1, 1);
  M(0, 0) = 1;

  S21Matrix M2 = M.InverseMatrix();

  ASSERT_DOUBLE_EQ(M2.GetRows(), 1);
  ASSERT_DOUBLE_EQ(M2.GetCols(), 1);

  ASSERT_DOUBLE_EQ(M2(0, 0), 1);
}

TEST(Method_SetCols, test1) {
  S21Matrix M(1, 1);
  M.SetCols(3);

  ASSERT_DOUBLE_EQ(M.GetCols(), 3);

  for (int i = 0; i < 1; i++) {
    for (int j = 1; j < 3; j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 0);
    }
  }
}

TEST(Method_SetCols, test2) {
  S21Matrix M(1, 3);
  M.SetCols(1);

  ASSERT_DOUBLE_EQ(M.GetCols(), 1);
}

TEST(Method_SetCols, test3) {
  S21Matrix M(1, 3);

  ASSERT_ANY_THROW(M.SetCols(-1));
}

TEST(Method_SetRows, test1) {
  S21Matrix M(1, 1);
  M.SetRows(3);

  ASSERT_DOUBLE_EQ(M.GetRows(), 3);

  for (int i = 1; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 0);
    }
  }
}

TEST(Method_SetRows, test2) {
  S21Matrix M(3, 3);
  M.SetRows(1);

  ASSERT_DOUBLE_EQ(M.GetRows(), 1);
}

TEST(Method_SetRows, test3) {
  S21Matrix M(1, 3);

  ASSERT_ANY_THROW(M.SetRows(-1));
}

TEST(Operator_assignment, test_1) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38.456;
    }
  }
  S21Matrix M2;
  M2 = M;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), M2(i, j));
    }
  }
}

TEST(Operator_brackets, test_1) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  ASSERT_DOUBLE_EQ(M(2, 2), 38);
}

TEST(Operator_brackets, test_2) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  ASSERT_ANY_THROW(M(2, 6));
  ASSERT_ANY_THROW(M(6, 2));
}

TEST(Operator_brackets, test_3) {
  S21Matrix M(4, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  ASSERT_NO_THROW(M(3, 3));
  ASSERT_ANY_THROW(M(4, 4));
  ASSERT_ANY_THROW(M(0, -1));
  ASSERT_ANY_THROW(M(2, -1));
  ASSERT_ANY_THROW(M(-2, 2));
}

TEST(Operator_Sum, test_1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2 = M;
  S21Matrix M3 = M2 + M;
  for (int i = 0; i < M3.GetRows(); i++) {
    for (int j = 0; j < M3.GetCols(); j++) {
      ASSERT_EQ(M3(i, j), 20);
    }
  }
}

TEST(Operator_Sum, test_2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 150.5;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150.5;
    }
  }
  S21Matrix M3 = M2 + M;
  for (int i = 0; i < M3.GetRows(); i++) {
    for (int j = 0; j < M3.GetCols(); j++) {
      ASSERT_EQ(M3(i, j), 301);
    }
  }
}

TEST(Operator_Sum, test_3) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2;
  S21Matrix M3;
  ASSERT_ANY_THROW(M3 = M2 + M);
}

TEST(Operator_Sub, test_1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 347.475;
    }
  }
  S21Matrix M2 = M;
  S21Matrix M3 = M - M2;
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      ASSERT_EQ(M3(i, j), 0);
    }
  }
}

TEST(Operator_Sub, test_2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 374729.342;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150342.5425;
    }
  }
  S21Matrix M3 = M - M2;
  for (int i = 0; i < M3.GetRows(); i++) {
    for (int j = 0; j < M3.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M3(i, j), 224386.7995);
    }
  }
}

TEST(Operator_Sub, test_3) {
  S21Matrix M(3, 3);
  M(0, 0) = 234;
  M(0, 1) = 5698;
  M(0, 2) = 23716;

  M(1, 0) = 682812.487;
  M(1, 1) = 21234;
  M(1, 2) = 3459877.34875;

  M(2, 0) = 23587.3487;
  M(2, 1) = 1.2345;
  M(2, 2) = 13.3452;

  S21Matrix M2(3, 3);
  M2(0, 0) = 123874;
  M2(0, 1) = 2387;
  M2(0, 2) = -3846;

  M2(1, 0) = 23948.3472;
  M2(1, 1) = 0.98762;
  M2(1, 2) = 123.23;

  M2(2, 0) = 696387.12;
  M2(2, 1) = 343.43;
  M2(2, 2) = 9999.9999;

  S21Matrix M3 = M - M2;
  ASSERT_DOUBLE_EQ(M3(0, 0), -123640);
  ASSERT_DOUBLE_EQ(M3(0, 1), 3311);
  ASSERT_DOUBLE_EQ(M3(0, 2), 27562);
  ASSERT_DOUBLE_EQ(M3(1, 0), 658864.1398);
  ASSERT_DOUBLE_EQ(M3(1, 1), 21233.01238);
  ASSERT_DOUBLE_EQ(M3(1, 2), 3459754.11875);
  ASSERT_DOUBLE_EQ(M3(2, 0), -672799.7713);
  ASSERT_DOUBLE_EQ(M3(2, 1), -342.1955);
  ASSERT_DOUBLE_EQ(M3(2, 2), -9986.6547);
}

TEST(Operator_MulMatrix, test_1) {
  S21Matrix M(4, 5);
  S21Matrix M2(4, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
      M2(i, j) = 25;
    }
  }
  ASSERT_ANY_THROW(M * M2);
}

TEST(Operator_MulMatrix, test_2) {
  S21Matrix M(4, 5);
  S21Matrix M2(5, 4);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
    }
  }
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 12;
    }
  }
  S21Matrix M3 = M * M2;
  for (int i = 0; i < M3.GetRows(); i++) {
    for (int j = 0; j < M3.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M3(i, j), 2280);
    }
  }
}

TEST(Operator_MulMatrix, test_3) {
  S21Matrix M(4, 5);
  S21Matrix M2(5, 4);
  M(0, 0) = 38;
  M(0, 1) = 45.56;
  M(0, 2) = 12.484;
  M(0, 3) = 17892;
  M(0, 4) = 41.54;

  M(1, 0) = 12.1;
  M(1, 1) = 0.999;
  M(1, 2) = 99;
  M(1, 3) = 9;
  M(1, 4) = 12.4;

  M(2, 0) = 0.154;
  M(2, 1) = 0.487;
  M(2, 2) = 4110.4;
  M(2, 3) = 12;
  M(2, 4) = 38;

  M(3, 0) = 45.58;
  M(3, 1) = 0.1;
  M(3, 2) = 0.12;
  M(3, 3) = 38;
  M(3, 4) = 3825;

  M2(0, 0) = 0;
  M2(0, 1) = 14;
  M2(0, 2) = 1;
  M2(0, 3) = 85.2;

  M2(1, 0) = 1.254;
  M2(1, 1) = 13.544;
  M2(1, 2) = 12;
  M2(1, 3) = 1;

  M2(2, 0) = 148;
  M2(2, 1) = 58;
  M2(2, 2) = 698;
  M2(2, 3) = 1.1235;

  M2(3, 0) = 125;
  M2(3, 1) = 48;
  M2(3, 2) = 75.1;
  M2(3, 3) = 2.25;

  M2(4, 0) = 12.5;
  M2(4, 1) = 51;
  M2(4, 2) = 34;
  M2(4, 3) = 12;

  S21Matrix M3 = M * M2;
  ASSERT_DOUBLE_EQ(M3(0, 0), 2238924.01424);
  ASSERT_DOUBLE_EQ(M3(0, 1), 862807.67664);
  ASSERT_DOUBLE_EQ(M3(0, 2), 1354400.112);
  ASSERT_DOUBLE_EQ(M3(0, 3), 44052.665774);

  ASSERT_DOUBLE_EQ(M3(1, 0), 15933.252746);
  ASSERT_DOUBLE_EQ(M3(1, 1), 6989.330456);
  ASSERT_DOUBLE_EQ(M3(1, 2), 70223.588);
  ASSERT_DOUBLE_EQ(M3(1, 3), 1312.1955);

  ASSERT_DOUBLE_EQ(M3(2, 0), 610314.810698);
  ASSERT_DOUBLE_EQ(M3(2, 1), 240925.951928);
  ASSERT_DOUBLE_EQ(M3(2, 2), 2871258.398);
  ASSERT_DOUBLE_EQ(M3(2, 3), 5114.6422);

  ASSERT_DOUBLE_EQ(M3(3, 0), 52580.3854);
  ASSERT_DOUBLE_EQ(M3(3, 1), 197545.4344);
  ASSERT_DOUBLE_EQ(M3(3, 2), 133034.34);
  ASSERT_DOUBLE_EQ(M3(3, 3), 49869.15082);
}

TEST(Operator_MulNumber, test_1) {
  S21Matrix M(2, 3);

  M(0, 0) = 1;
  M(0, 1) = -2;
  M(0, 2) = 3;

  M(1, 0) = -4;
  M(1, 1) = 5;
  M(1, 2) = -6;

  S21Matrix M2 = M * 5;

  ASSERT_DOUBLE_EQ(M2.GetCols(), 3);
  ASSERT_DOUBLE_EQ(M2.GetRows(), 2);

  ASSERT_DOUBLE_EQ(M2(0, 0), 5);
  ASSERT_DOUBLE_EQ(M2(0, 1), -10);
  ASSERT_DOUBLE_EQ(M2(0, 2), 15);

  ASSERT_DOUBLE_EQ(M2(1, 0), -20);
  ASSERT_DOUBLE_EQ(M2(1, 1), 25);
  ASSERT_DOUBLE_EQ(M2(1, 2), -30);
}

TEST(Operator_MulNumber, test_2) {
  S21Matrix M(2, 3);

  M(0, 0) = 1;
  M(0, 1) = -2;
  M(0, 2) = 3;

  M(1, 0) = -4;
  M(1, 1) = 5;
  M(1, 2) = -6;

  M *= 5;

  ASSERT_DOUBLE_EQ(M.GetCols(), 3);
  ASSERT_DOUBLE_EQ(M.GetRows(), 2);

  ASSERT_DOUBLE_EQ(M(0, 0), 5);
  ASSERT_DOUBLE_EQ(M(0, 1), -10);
  ASSERT_DOUBLE_EQ(M(0, 2), 15);

  ASSERT_DOUBLE_EQ(M(1, 0), -20);
  ASSERT_DOUBLE_EQ(M(1, 1), 25);
  ASSERT_DOUBLE_EQ(M(1, 2), -30);
}

TEST(Operator_EqMatrix, test_1) {
  S21Matrix M(3, 3);
  S21Matrix M2(2, 2);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 3;
    }
  }
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 3;
    }
  }
  ASSERT_EQ(M == M2, 0);
}

TEST(Operator_EqMatrix, test_2) {
  S21Matrix M(3, 3);
  S21Matrix M2(3, 3);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 3.4736287;
    }
  }
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 3.4736287;
    }
  }
  ASSERT_EQ(M == M2, 1);
}

TEST(Operator_EqMatrix, test_3) {
  S21Matrix M(3, 3);
  S21Matrix M2(3, 3);
  M(0, 0) = 123;
  M(0, 1) = 123;
  M(0, 2) = 123;

  M(1, 0) = 123;
  M(1, 1) = 129;
  M(1, 2) = 123;

  M(2, 0) = 123;
  M(2, 1) = 123;
  M(2, 2) = 123;

  M2(0, 0) = 123;
  M2(0, 1) = 123;
  M2(0, 2) = 123;

  M2(1, 0) = 123;
  M2(1, 1) = 123;
  M2(1, 2) = 123;

  M2(2, 0) = 123;
  M2(2, 1) = 123;
  M2(2, 2) = 123;

  ASSERT_EQ(M == M2, 0);
}

TEST(Operator_Sum_Assignment, test_1) {
  S21Matrix M(3, 3);
  M(0, 0) = 50.34;
  M(0, 1) = 4654.453;
  M(0, 2) = 345;

  M(1, 0) = 56.563;
  M(1, 1) = 56.345;
  M(1, 2) = 456;

  M(2, 0) = 345;
  M(2, 1) = 433;
  M(2, 2) = 3345;

  S21Matrix M2(3, 3);
  M2(0, 0) = 345;
  M2(0, 1) = 68;
  M2(0, 2) = 345;

  M2(1, 0) = -456.56;
  M2(1, 1) = -345;
  M2(1, 2) = 86;

  M2(2, 0) = -456.5;
  M2(2, 1) = 57;
  M2(2, 2) = 0.987;

  M += M2;
  ASSERT_DOUBLE_EQ(M(0, 0), 395.34);
  ASSERT_DOUBLE_EQ(M(0, 1), 4722.453);
  ASSERT_DOUBLE_EQ(M(0, 2), 690);
  ASSERT_DOUBLE_EQ(M(1, 0), -399.997);
  ASSERT_DOUBLE_EQ(M(1, 1), -288.655);
  ASSERT_DOUBLE_EQ(M(1, 2), 542);
  ASSERT_DOUBLE_EQ(M(2, 0), -111.5);
  ASSERT_DOUBLE_EQ(M(2, 1), 490);
  ASSERT_DOUBLE_EQ(M(2, 2), 3345.987);
}

TEST(Operator_Sum_Assignment, test_2) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 10;
    }
  }
  S21Matrix M2;
  ASSERT_ANY_THROW(M += M2);
  ASSERT_ANY_THROW(M2 += M);
}

TEST(Operator_Sub_Assignment, test_1) {
  S21Matrix M(6, 6);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 347.475;
    }
  }
  S21Matrix M2 = M;
  M -= M2;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_EQ(M(i, j), 0);
    }
  }
}

TEST(Operator_Sub_Assignment, test_2) {
  S21Matrix M(6, 10);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 374729.342;
    }
  }
  S21Matrix M2(6, 10);
  for (int i = 0; i < M2.GetRows(); i++) {
    for (int j = 0; j < M2.GetCols(); j++) {
      M2(i, j) = 150342.5425;
    }
  }
  M -= M2;
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      ASSERT_DOUBLE_EQ(M(i, j), 224386.7995);
    }
  }
}

TEST(Operator_Sub_Assignment, test_3) {
  S21Matrix M(3, 3);
  M(0, 0) = 234;
  M(0, 1) = 5698;
  M(0, 2) = 23716;

  M(1, 0) = 682812.487;
  M(1, 1) = 21234;
  M(1, 2) = 3459877.34875;

  M(2, 0) = 23587.3487;
  M(2, 1) = 1.2345;
  M(2, 2) = 13.3452;

  S21Matrix M2(3, 3);
  M2(0, 0) = 123874;
  M2(0, 1) = 2387;
  M2(0, 2) = -3846;

  M2(1, 0) = 23948.3472;
  M2(1, 1) = 0.98762;
  M2(1, 2) = 123.23;

  M2(2, 0) = 696387.12;
  M2(2, 1) = 343.43;
  M2(2, 2) = 9999.9999;

  M -= M2;
  ASSERT_DOUBLE_EQ(M(0, 0), -123640);
  ASSERT_DOUBLE_EQ(M(0, 1), 3311);
  ASSERT_DOUBLE_EQ(M(0, 2), 27562);
  ASSERT_DOUBLE_EQ(M(1, 0), 658864.1398);
  ASSERT_DOUBLE_EQ(M(1, 1), 21233.01238);
  ASSERT_DOUBLE_EQ(M(1, 2), 3459754.11875);
  ASSERT_DOUBLE_EQ(M(2, 0), -672799.7713);
  ASSERT_DOUBLE_EQ(M(2, 1), -342.1955);
  ASSERT_DOUBLE_EQ(M(2, 2), -9986.6547);
}

TEST(Operator_MulMatrix_Assignment, test_1) {
  S21Matrix M(4, 5);
  S21Matrix M2(4, 5);
  for (int i = 0; i < M.GetRows(); i++) {
    for (int j = 0; j < M.GetCols(); j++) {
      M(i, j) = 38;
      M2(i, j) = 25;
    }
  }
  ASSERT_ANY_THROW(M *= M2);
}

TEST(Operator_MulMatrix_Assignment, test_3) {
  S21Matrix M(4, 5);
  S21Matrix M2(5, 4);
  M(0, 0) = 38;
  M(0, 1) = 45.56;
  M(0, 2) = 12.484;
  M(0, 3) = 17892;
  M(0, 4) = 41.54;

  M(1, 0) = 12.1;
  M(1, 1) = 0.999;
  M(1, 2) = 99;
  M(1, 3) = 9;
  M(1, 4) = 12.4;

  M(2, 0) = 0.154;
  M(2, 1) = 0.487;
  M(2, 2) = 4110.4;
  M(2, 3) = 12;
  M(2, 4) = 38;

  M(3, 0) = 45.58;
  M(3, 1) = 0.1;
  M(3, 2) = 0.12;
  M(3, 3) = 38;
  M(3, 4) = 3825;

  M2(0, 0) = 0;
  M2(0, 1) = 14;
  M2(0, 2) = 1;
  M2(0, 3) = 85.2;

  M2(1, 0) = 1.254;
  M2(1, 1) = 13.544;
  M2(1, 2) = 12;
  M2(1, 3) = 1;

  M2(2, 0) = 148;
  M2(2, 1) = 58;
  M2(2, 2) = 698;
  M2(2, 3) = 1.1235;

  M2(3, 0) = 125;
  M2(3, 1) = 48;
  M2(3, 2) = 75.1;
  M2(3, 3) = 2.25;

  M2(4, 0) = 12.5;
  M2(4, 1) = 51;
  M2(4, 2) = 34;
  M2(4, 3) = 12;

  M *= M2;
  ASSERT_DOUBLE_EQ(M(0, 0), 2238924.01424);
  ASSERT_DOUBLE_EQ(M(0, 1), 862807.67664);
  ASSERT_DOUBLE_EQ(M(0, 2), 1354400.112);
  ASSERT_DOUBLE_EQ(M(0, 3), 44052.665774);
  ASSERT_DOUBLE_EQ(M(1, 0), 15933.252746);
  ASSERT_DOUBLE_EQ(M(1, 1), 6989.330456);
  ASSERT_DOUBLE_EQ(M(1, 2), 70223.588);
  ASSERT_DOUBLE_EQ(M(1, 3), 1312.1955);
  ASSERT_DOUBLE_EQ(M(2, 0), 610314.810698);
  ASSERT_DOUBLE_EQ(M(2, 1), 240925.951928);
  ASSERT_DOUBLE_EQ(M(2, 2), 2871258.398);
  ASSERT_DOUBLE_EQ(M(2, 3), 5114.6422);
  ASSERT_DOUBLE_EQ(M(3, 0), 52580.3854);
  ASSERT_DOUBLE_EQ(M(3, 1), 197545.4344);
  ASSERT_DOUBLE_EQ(M(3, 2), 133034.34);
  ASSERT_DOUBLE_EQ(M(3, 3), 49869.15082);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}