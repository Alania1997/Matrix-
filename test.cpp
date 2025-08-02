#include "s21_matrix_oop.h"

class S21MatrixTest : public ::testing::Test {};

TEST(S21MatrixTest, SizesEqualTrue) {
  S21Matrix mat1(2, 2);
  S21Matrix mat2(2, 2);
  EXPECT_TRUE(mat1.SizesEqual(mat2));
}

TEST(S21MatrixTest, SizesEqualFalse) {
  S21Matrix mat1(2, 2);
  S21Matrix mat2(3, 2);
  EXPECT_FALSE(mat1.SizesEqual(mat2));
}

TEST(S21MatrixTest, SizesEqualDifferentColumns) {
  S21Matrix mat1(2, 3);
  S21Matrix mat2(2, 2);
  EXPECT_FALSE(mat1.SizesEqual(mat2));
}

TEST(S21MatrixTest, SizesEqualBothEmpty) {
  S21Matrix mat1;
  S21Matrix mat2;
  EXPECT_TRUE(mat1.SizesEqual(mat2));
}

TEST(S21MatrixTest, SizesEqualWithNonDefaultConstructor) {
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  EXPECT_TRUE(mat1.SizesEqual(mat2));
}

// Тесты для функции sum_matrix
class S21MatrixSumTest : public ::testing::Test {};

TEST_F(S21MatrixSumTest, SumEqualSizes) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1.SetElement(0, 0, 1.0);
  m1.SetElement(0, 1, 2.0);
  m1.SetElement(1, 0, 3.0);
  m1.SetElement(1, 1, 4.0);

  m2.SetElement(0, 0, 1.0);
  m2.SetElement(0, 1, 1.0);
  m2.SetElement(1, 0, 1.0);
  m2.SetElement(1, 1, 1.0);

  m1.sum_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), 5.0);
}

TEST_F(S21MatrixSumTest, SumWithZeros) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1.SetElement(0, 0, 1.0);
  m1.SetElement(0, 1, 2.0);
  m1.SetElement(1, 0, 3.0);
  m1.SetElement(1, 1, 4.0);

  m2.SetElement(0, 0, 0.0);
  m2.SetElement(0, 1, 0.0);
  m2.SetElement(1, 0, 0.0);
  m2.SetElement(1, 1, 0.0);

  m1.sum_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), 4.0);
}

TEST_F(S21MatrixSumTest, SumNegativeValues) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1.SetElement(0, 0, -1.0);
  m1.SetElement(0, 1, -2.0);
  m1.SetElement(1, 0, -3.0);
  m1.SetElement(1, 1, -4.0);

  m2.SetElement(0, 0, -1.0);
  m2.SetElement(0, 1, -1.0);
  m2.SetElement(1, 0, -1.0);
  m2.SetElement(1, 1, -1.0);

  m1.sum_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), -5.0);
}

TEST_F(S21MatrixSumTest, SumNonSquareMatrix) {
  S21Matrix m1(2, 3);
  S21Matrix m2(2, 3);

  m1.SetElement(0, 0, 1.0);
  m1.SetElement(0, 1, 2.0);
  m1.SetElement(0, 2, 3.0);
  m1.SetElement(1, 0, 4.0);
  m1.SetElement(1, 1, 5.0);
  m1.SetElement(1, 2, 6.0);

  m2.SetElement(0, 0, 1.0);
  m2.SetElement(0, 1, 1.0);
  m2.SetElement(0, 2, 1.0);
  m2.SetElement(1, 0, 1.0);
  m2.SetElement(1, 1, 1.0);
  m2.SetElement(1, 2, 1.0);

  m1.sum_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 2), 4.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), 5.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), 6.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 2), 7.0);
}

TEST_F(S21MatrixSumTest, SumDifferentSizes) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 3);
  EXPECT_THROW(m1.sum_matrix(m2), std::out_of_range);
}

// Тесты для функции sub_matrix
class S21MatrixSubTest : public ::testing::Test {};

TEST_F(S21MatrixSubTest, SubEqualSizes) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1.SetElement(0, 0, 5.0);
  m1.SetElement(0, 1, 4.0);
  m1.SetElement(1, 0, 3.0);
  m1.SetElement(1, 1, 2.0);

  m2.SetElement(0, 0, 1.0);
  m2.SetElement(0, 1, 1.0);
  m2.SetElement(1, 0, 1.0);
  m2.SetElement(1, 1, 1.0);

  m1.sub_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), 1.0);
}

TEST_F(S21MatrixSubTest, SubWithZeros) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1.SetElement(0, 0, 5.0);
  m1.SetElement(0, 1, 4.0);
  m1.SetElement(1, 0, 3.0);
  m1.SetElement(1, 1, 2.0);

  m2.SetElement(0, 0, 0.0);
  m2.SetElement(0, 1, 0.0);
  m2.SetElement(1, 0, 0.0);
  m2.SetElement(1, 1, 0.0);

  m1.sub_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), 2.0);
}

TEST_F(S21MatrixSubTest, SubNegativeValues) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1.SetElement(0, 0, -5.0);
  m1.SetElement(0, 1, -4.0);
  m1.SetElement(1, 0, -3.0);
  m1.SetElement(1, 1, -2.0);

  m2.SetElement(0, 0, -1.0);
  m2.SetElement(0, 1, -1.0);
  m2.SetElement(1, 0, -1.0);
  m2.SetElement(1, 1, -1.0);

  m1.sub_matrix(m2);

  EXPECT_DOUBLE_EQ(m1.GetElement(0, 0), -4.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 0), -2.0);
  EXPECT_DOUBLE_EQ(m1.GetElement(1, 1), -1.0);
}

// Тест 1: Умножение матрицы на положительное число
TEST(S21MatrixTest, MulNumberPositiveTest) {
  S21Matrix matrix(2, 2);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(1, 0, 3.0);
  matrix.SetElement(1, 1, 4.0);

  // Умножаем на число 2
  matrix.mul_number(2.0);

  // Проверяем результат умножения
  EXPECT_EQ(matrix.GetElement(0, 0), 2.0); // 1 * 2
  EXPECT_EQ(matrix.GetElement(0, 1), 4.0); // 2 * 2
  EXPECT_EQ(matrix.GetElement(1, 0), 6.0); // 3 * 2
  EXPECT_EQ(matrix.GetElement(1, 1), 8.0); // 4 * 2
}

// Тест 2: Умножение матрицы на отрицательное число
TEST(S21MatrixTest, MulNumberNegativeTest) {
  S21Matrix matrix(2, 2);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(1, 0, 3.0);
  matrix.SetElement(1, 1, 4.0);

  // Умножаем на число -2
  matrix.mul_number(-2.0);

  // Проверяем результат умножения
  EXPECT_EQ(matrix.GetElement(0, 0), -2.0); // 1 * -2
  EXPECT_EQ(matrix.GetElement(0, 1), -4.0); // 2 * -2
  EXPECT_EQ(matrix.GetElement(1, 0), -6.0); // 3 * -2
  EXPECT_EQ(matrix.GetElement(1, 1), -8.0); // 4 * -2
}

// Тест 3: Умножение матрицы на 0
TEST(S21MatrixTest, MulNumberZeroTest) {
  S21Matrix matrix(2, 2);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(1, 0, 3.0);
  matrix.SetElement(1, 1, 4.0);

  // Умножаем на 0
  matrix.mul_number(0.0);

  // Проверяем, что все элементы матрицы стали 0
  EXPECT_EQ(matrix.GetElement(0, 0), 0.0); // 1 * 0
  EXPECT_EQ(matrix.GetElement(0, 1), 0.0); // 2 * 0
  EXPECT_EQ(matrix.GetElement(1, 0), 0.0); // 3 * 0
  EXPECT_EQ(matrix.GetElement(1, 1), 0.0); // 4 * 0
}

// Тест 4: Умножение на 1 (должно оставить матрицу неизменной)
TEST(S21MatrixTest, MulNumberOneTest) {
  S21Matrix matrix(2, 2);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 5.0);
  matrix.SetElement(0, 1, 10.0);
  matrix.SetElement(1, 0, 15.0);
  matrix.SetElement(1, 1, 20.0);

  // Умножаем на 1
  matrix.mul_number(1.0);

  // Проверяем, что матрица осталась без изменений
  EXPECT_EQ(matrix.GetElement(0, 0), 5.0);
  EXPECT_EQ(matrix.GetElement(0, 1), 10.0);
  EXPECT_EQ(matrix.GetElement(1, 0), 15.0);
  EXPECT_EQ(matrix.GetElement(1, 1), 20.0);
}

// Тест 5: Умножение матрицы на большое число
TEST(S21MatrixTest, MulNumberLargeTest) {
  S21Matrix matrix(3, 3);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(0, 2, 3.0);
  matrix.SetElement(1, 0, 4.0);
  matrix.SetElement(1, 1, 5.0);
  matrix.SetElement(1, 2, 6.0);
  matrix.SetElement(2, 0, 7.0);
  matrix.SetElement(2, 1, 8.0);
  matrix.SetElement(2, 2, 9.0);

  // Умножаем на 1000
  matrix.mul_number(1000.0);

  // Проверяем результат умножения
  EXPECT_EQ(matrix.GetElement(0, 0), 1000.0);
  EXPECT_EQ(matrix.GetElement(0, 1), 2000.0);
  EXPECT_EQ(matrix.GetElement(0, 2), 3000.0);
  EXPECT_EQ(matrix.GetElement(1, 0), 4000.0);
  EXPECT_EQ(matrix.GetElement(1, 1), 5000.0);
  EXPECT_EQ(matrix.GetElement(1, 2), 6000.0);
  EXPECT_EQ(matrix.GetElement(2, 0), 7000.0);
  EXPECT_EQ(matrix.GetElement(2, 1), 8000.0);
  EXPECT_EQ(matrix.GetElement(2, 2), 9000.0);
}

// Тест 1: Умножение двух матриц 2x2
TEST(S21MatrixTest, MulMatrix2x2Test) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  // Заполняем первую матрицу
  matrix1.SetElement(0, 0, 1.0);
  matrix1.SetElement(0, 1, 2.0);
  matrix1.SetElement(1, 0, 3.0);
  matrix1.SetElement(1, 1, 4.0);

  // Заполняем вторую матрицу
  matrix2.SetElement(0, 0, 5.0);
  matrix2.SetElement(0, 1, 6.0);
  matrix2.SetElement(1, 0, 7.0);
  matrix2.SetElement(1, 1, 8.0);

  // Выполняем умножение
  matrix1.mul_matrix(matrix2);

  // Проверяем результат умножения
  EXPECT_EQ(matrix1.GetElement(0, 0), 19.0); // 1*5 + 2*7
  EXPECT_EQ(matrix1.GetElement(0, 1), 22.0); // 1*6 + 2*8
  EXPECT_EQ(matrix1.GetElement(1, 0), 43.0); // 3*5 + 4*7
  EXPECT_EQ(matrix1.GetElement(1, 1), 50.0); // 3*6 + 4*8
}

// Тест 2: Умножение матриц с несовпадающими размерами
TEST(S21MatrixTest, MulMatrixSizeMismatchTest) {
  S21Matrix matrix1(2, 3); // 2x3 матрица
  S21Matrix matrix2(4, 2); // 4x2 матрица

  // Проверка выброса исключения при несовпадении размеров
  EXPECT_THROW(matrix1.mul_matrix(matrix2), std::out_of_range);
}

// Тест 3: Умножение матрицы на нулевую матрицу
TEST(S21MatrixTest, MulMatrixZeroTest) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  // Заполняем первую матрицу
  matrix1.SetElement(0, 0, 1.0);
  matrix1.SetElement(0, 1, 2.0);
  matrix1.SetElement(1, 0, 3.0);
  matrix1.SetElement(1, 1, 4.0);

  // Заполняем вторую матрицу нулями
  matrix2.SetElement(0, 0, 0.0);
  matrix2.SetElement(0, 1, 0.0);
  matrix2.SetElement(1, 0, 0.0);
  matrix2.SetElement(1, 1, 0.0);

  // Выполняем умножение
  matrix1.mul_matrix(matrix2);

  // Проверяем, что результат умножения — это матрица с нулями
  EXPECT_EQ(matrix1.GetElement(0, 0), 0.0);
  EXPECT_EQ(matrix1.GetElement(0, 1), 0.0);
  EXPECT_EQ(matrix1.GetElement(1, 0), 0.0);
  EXPECT_EQ(matrix1.GetElement(1, 1), 0.0);
}

// Тест 4: Умножение матрицы на единичную матрицу
TEST(S21MatrixTest, MulMatrixIdentityTest) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  // Заполняем первую матрицу
  matrix1.SetElement(0, 0, 5.0);
  matrix1.SetElement(0, 1, 3.0);
  matrix1.SetElement(1, 0, 1.0);
  matrix1.SetElement(1, 1, 4.0);

  // Заполняем вторую матрицу единичными элементами
  matrix2.SetElement(0, 0, 1.0);
  matrix2.SetElement(0, 1, 0.0);
  matrix2.SetElement(1, 0, 0.0);
  matrix2.SetElement(1, 1, 1.0);

  // Выполняем умножение
  matrix1.mul_matrix(matrix2);

  // Проверяем, что результат умножения — это сама матрица matrix1
  EXPECT_EQ(matrix1.GetElement(0, 0), 5.0);
  EXPECT_EQ(matrix1.GetElement(0, 1), 3.0);
  EXPECT_EQ(matrix1.GetElement(1, 0), 1.0);
  EXPECT_EQ(matrix1.GetElement(1, 1), 4.0);
}

// Тест 5: Умножение матрицы на матрицу 1x1
TEST(S21MatrixTest, MulMatrix1x1Test) {
  S21Matrix matrix1(2, 1); // 2x1 матрица
  S21Matrix matrix2(1, 1); // 1x1 матрица

  // Заполняем первую матрицу
  matrix1.SetElement(0, 0, 2.0);
  matrix1.SetElement(1, 0, 3.0);

  // Заполняем вторую матрицу
  matrix2.SetElement(0, 0, 4.0);

  // Выполняем умножение
  matrix1.mul_matrix(matrix2);

  // Проверяем результат умножения
  EXPECT_EQ(matrix1.GetElement(0, 0), 8.0);  // 2*4
  EXPECT_EQ(matrix1.GetElement(1, 0), 12.0); // 3*4
}

// Тест 1: Транспонирование матрицы 2x2
TEST(S21MatrixTest, Transpose2x2) {
  S21Matrix matrix(2, 2);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(1, 0, 3.0);
  matrix.SetElement(1, 1, 4.0);

  // Транспонируем матрицу
  S21Matrix transposed = matrix.Transpose();

  // Проверяем элементы транспонированной матрицы
  EXPECT_EQ(transposed.GetElement(0, 0), 1.0); // Было 1.0 на позиции (0,0)
  EXPECT_EQ(transposed.GetElement(0, 1), 3.0); // Было 3.0 на позиции (1,0)
  EXPECT_EQ(transposed.GetElement(1, 0), 2.0); // Было 2.0 на позиции (0,1)
  EXPECT_EQ(transposed.GetElement(1, 1), 4.0); // Было 4.0 на позиции (1,1)
}

// Тест 2: Транспонирование матрицы 3x2
TEST(S21MatrixTest, Transpose3x2) {
  S21Matrix matrix(3, 2);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(1, 0, 3.0);
  matrix.SetElement(1, 1, 4.0);
  matrix.SetElement(2, 0, 5.0);
  matrix.SetElement(2, 1, 6.0);

  // Транспонируем матрицу
  S21Matrix transposed = matrix.Transpose();

  // Проверяем элементы транспонированной матрицы
  EXPECT_EQ(transposed.GetElement(0, 0), 1.0); // Было 1.0 на позиции (0,0)
  EXPECT_EQ(transposed.GetElement(0, 1), 3.0); // Было 3.0 на позиции (1,0)
  EXPECT_EQ(transposed.GetElement(0, 2), 5.0); // Было 5.0 на позиции (2,0)
  EXPECT_EQ(transposed.GetElement(1, 0), 2.0); // Было 2.0 на позиции (0,1)
  EXPECT_EQ(transposed.GetElement(1, 1), 4.0); // Было 4.0 на позиции (1,1)
  EXPECT_EQ(transposed.GetElement(1, 2), 6.0); // Было 6.0 на позиции (2,1)
}

// Тест 3: Транспонирование квадратной матрицы 3x3
TEST(S21MatrixTest, Transpose3x3) {
  S21Matrix matrix(3, 3);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(0, 2, 3.0);
  matrix.SetElement(1, 0, 4.0);
  matrix.SetElement(1, 1, 5.0);
  matrix.SetElement(1, 2, 6.0);
  matrix.SetElement(2, 0, 7.0);
  matrix.SetElement(2, 1, 8.0);
  matrix.SetElement(2, 2, 9.0);

  // Транспонируем матрицу
  S21Matrix transposed = matrix.Transpose();

  // Проверяем элементы транспонированной матрицы
  EXPECT_EQ(transposed.GetElement(0, 0), 1.0);
  EXPECT_EQ(transposed.GetElement(0, 1), 4.0);
  EXPECT_EQ(transposed.GetElement(0, 2), 7.0);
  EXPECT_EQ(transposed.GetElement(1, 0), 2.0);
  EXPECT_EQ(transposed.GetElement(1, 1), 5.0);
  EXPECT_EQ(transposed.GetElement(1, 2), 8.0);
  EXPECT_EQ(transposed.GetElement(2, 0), 3.0);
  EXPECT_EQ(transposed.GetElement(2, 1), 6.0);
  EXPECT_EQ(transposed.GetElement(2, 2), 9.0);
}

// Тест 4: Транспонирование матрицы 1x3
TEST(S21MatrixTest, Transpose1x3) {
  S21Matrix matrix(1, 3);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(0, 2, 3.0);

  // Транспонируем матрицу
  S21Matrix transposed = matrix.Transpose();

  // Проверяем элементы транспонированной матрицы
  EXPECT_EQ(transposed.GetElement(0, 0), 1.0);
  EXPECT_EQ(transposed.GetElement(1, 0), 2.0);
  EXPECT_EQ(transposed.GetElement(2, 0), 3.0);
}

// Тест 5: Транспонирование матрицы 3x1
TEST(S21MatrixTest, Transpose3x1) {
  S21Matrix matrix(3, 1);

  // Заполняем матрицу
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(1, 0, 2.0);
  matrix.SetElement(2, 0, 3.0);

  // Транспонируем матрицу
  S21Matrix transposed = matrix.Transpose();

  // Проверяем элементы транспонированной матрицы
  EXPECT_EQ(transposed.GetElement(0, 0), 1.0);
  EXPECT_EQ(transposed.GetElement(0, 1), 2.0);
  EXPECT_EQ(transposed.GetElement(0, 2), 3.0);
}
// Оператор +
TEST(S21MatrixTest, AdditionOfEqualMatrices) {
  S21Matrix matrix1(2, 2);
  matrix1.SetElement(0, 0, 1.0);
  matrix1.SetElement(0, 1, 2.0);
  matrix1.SetElement(1, 0, 3.0);
  matrix1.SetElement(1, 1, 4.0);

  S21Matrix matrix2(2, 2);
  matrix2.SetElement(0, 0, 5.0);
  matrix2.SetElement(0, 1, 6.0);
  matrix2.SetElement(1, 0, 7.0);
  matrix2.SetElement(1, 1, 8.0);

  S21Matrix expected(2, 2);
  expected.SetElement(0, 0, 6.0);
  expected.SetElement(0, 1, 8.0);
  expected.SetElement(1, 0, 10.0);
  expected.SetElement(1, 1, 12.0);

  S21Matrix result = matrix1 + matrix2;
  EXPECT_TRUE(result == expected);
}

// Тест 2: Сложение матрицы с нулевой матрицей
TEST(S21MatrixTest, AdditionWithZeroMatrix) {
  S21Matrix matrix1(2, 2);
  matrix1.SetElement(0, 0, 1.0);
  matrix1.SetElement(0, 1, 2.0);
  matrix1.SetElement(1, 0, 3.0);
  matrix1.SetElement(1, 1, 4.0);

  S21Matrix zeroMatrix(
      2, 2); // Инициализируется как нулевая матрица (0.0 в каждом элементе)

  S21Matrix result = matrix1 + zeroMatrix;
  EXPECT_TRUE(result ==
              matrix1); // Результат должен быть равен исходной матрице
}

// Тест 3: Сложение матриц разных размеров (ожидаем исключение)
TEST(S21MatrixTest, AdditionWithDifferentSizeMatrices) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);
}
// Оператор -
TEST(S21MatrixTest, SubtractionOfEqualMatrices) {
  S21Matrix matrix1(2, 2);
  matrix1.SetElement(0, 0, 5.0);
  matrix1.SetElement(0, 1, 4.0);
  matrix1.SetElement(1, 0, 3.0);
  matrix1.SetElement(1, 1, 2.0);

  S21Matrix matrix2(2, 2);
  matrix2.SetElement(0, 0, 2.0);
  matrix2.SetElement(0, 1, 1.0);
  matrix2.SetElement(1, 0, 1.0);
  matrix2.SetElement(1, 1, 1.0);

  S21Matrix expected(2, 2);
  expected.SetElement(0, 0, 3.0);
  expected.SetElement(0, 1, 3.0);
  expected.SetElement(1, 0, 2.0);
  expected.SetElement(1, 1, 1.0);

  S21Matrix result = matrix1 - matrix2;
  EXPECT_TRUE(result == expected);
}

// Тест 2: Вычитание матрицы с нулевой матрицей
TEST(S21MatrixTest, SubtractionWithZeroMatrix) {
  S21Matrix matrix1(2, 2);
  matrix1.SetElement(0, 0, 5.0);
  matrix1.SetElement(0, 1, 4.0);
  matrix1.SetElement(1, 0, 3.0);
  matrix1.SetElement(1, 1, 2.0);

  S21Matrix zeroMatrix(2, 2); // Нулевая матрица

  S21Matrix expected(2, 2);
  expected.SetElement(0, 0, 5.0);
  expected.SetElement(0, 1, 4.0);
  expected.SetElement(1, 0, 3.0);
  expected.SetElement(1, 1, 2.0);

  S21Matrix result = matrix1 - zeroMatrix;
  EXPECT_TRUE(result == expected); // Ожидаем, что результат будет равен matrix1
}

// Тест 3: Вычитание матриц разных размеров (ожидаем исключение)
TEST(S21MatrixTest, SubtractionWithDifferentSizeMatrices) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);
}
// Тест 1: Умножение двух совместимых матриц
TEST(S21MatrixTest, MultiplicationOfCompatibleMatrices) {
  S21Matrix matrix1(2, 3);
  matrix1.SetElement(0, 0, 1.0);
  matrix1.SetElement(0, 1, 2.0);
  matrix1.SetElement(0, 2, 3.0);
  matrix1.SetElement(1, 0, 4.0);
  matrix1.SetElement(1, 1, 5.0);
  matrix1.SetElement(1, 2, 6.0);

  S21Matrix matrix2(3, 2);
  matrix2.SetElement(0, 0, 7.0);
  matrix2.SetElement(0, 1, 8.0);
  matrix2.SetElement(1, 0, 9.0);
  matrix2.SetElement(1, 1, 10.0);
  matrix2.SetElement(2, 0, 11.0);
  matrix2.SetElement(2, 1, 12.0);

  S21Matrix expected(2, 2);
  expected.SetElement(0, 0, 58.0);
  expected.SetElement(0, 1, 64.0);
  expected.SetElement(1, 0, 139.0);
  expected.SetElement(1, 1, 154.0);

  S21Matrix result = matrix1 * matrix2;
  EXPECT_TRUE(result == expected);
}

// Тест 2: Умножение матрицы на скалярное значение
TEST(S21MatrixTest, MultiplicationByScalar) {
  S21Matrix matrix(2, 2);
  matrix.SetElement(0, 0, 1.0);
  matrix.SetElement(0, 1, 2.0);
  matrix.SetElement(1, 0, 3.0);
  matrix.SetElement(1, 1, 4.0);

  double scalar = 3.0;
  S21Matrix expected(2, 2);
  expected.SetElement(0, 0, 3.0);
  expected.SetElement(0, 1, 6.0);
  expected.SetElement(1, 0, 9.0);
  expected.SetElement(1, 1, 12.0);

  S21Matrix result = matrix * scalar;
  EXPECT_TRUE(result == expected);
}

// Тест 3: Умножение несовместимых матриц (ожидаем исключение)
TEST(S21MatrixTest, MultiplicationWithIncompatibleMatrices) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(4, 2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);
}
TEST(S21MatrixTest, AssignmentEqualSize) {
  S21Matrix mat1(2, 3); // Создаем матрицу 2x3
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  S21Matrix mat2(2, 3); // Создаем другую матрицу 2x3
  mat2 = mat1;          // Присваиваем mat1 в mat2

  // Проверяем, что матрицы одинаковы после присваивания
  EXPECT_EQ(mat2(0, 0), 1.0);
  EXPECT_EQ(mat2(0, 1), 2.0);
  EXPECT_EQ(mat2(0, 2), 3.0);
  EXPECT_EQ(mat2(1, 0), 4.0);
  EXPECT_EQ(mat2(1, 1), 5.0);
  EXPECT_EQ(mat2(1, 2), 6.0);
}

// Тест 2: Присваивание матрицы самой себе
TEST(S21MatrixTest, AssignmentToSelf) {
  S21Matrix mat1(2, 3); // Создаем матрицу 2x3
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  mat1 = mat1; // Присваиваем матрицу самой себе

  // Проверяем, что матрица не изменилась
  EXPECT_EQ(mat1(0, 0), 1.0);
  EXPECT_EQ(mat1(0, 1), 2.0);
  EXPECT_EQ(mat1(0, 2), 3.0);
  EXPECT_EQ(mat1(1, 0), 4.0);
  EXPECT_EQ(mat1(1, 1), 5.0);
  EXPECT_EQ(mat1(1, 2), 6.0);
}

// Тест 3: Присваивание матрицы с различными размерами
TEST(S21MatrixTest, AssignmentDifferentSizes) {
  S21Matrix mat1(2, 3); // Создаем матрицу 2x3
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  S21Matrix mat2(3, 2); // Создаем матрицу 3x2

  mat2 = mat1; // Присваиваем mat1 в mat2

  // Проверяем, что размеры обновились
  EXPECT_EQ(mat2.get_rows(), 2); // Теперь матрица должна быть 2x3
  EXPECT_EQ(mat2.get_cols(), 3);

  // Проверяем значения в новой матрице
  EXPECT_EQ(mat2(0, 0), 1.0);
  EXPECT_EQ(mat2(0, 1), 2.0);
  EXPECT_EQ(mat2(0, 2), 3.0);
  EXPECT_EQ(mat2(1, 0), 4.0);
  EXPECT_EQ(mat2(1, 1), 5.0);
  EXPECT_EQ(mat2(1, 2), 6.0);
}

TEST(S21MatrixTest, EqualityMatricesWithSameSizeAndValues) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;

  EXPECT_TRUE(mat1 == mat2); // Ожидаем, что матрицы равны
}
TEST(S21MatrixTest, InequalityMatricesWithDifferentSizes) {
  S21Matrix mat1(2, 3); // Матрица 2x3
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(0, 2) = 3.0;
  mat1(1, 0) = 4.0;
  mat1(1, 1) = 5.0;
  mat1(1, 2) = 6.0;

  S21Matrix mat2(3, 2); // Матрица 3x2
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;
  mat2(2, 0) = 5.0;
  mat2(2, 1) = 6.0;

  EXPECT_FALSE(mat1 ==
               mat2); // Ожидаем, что матрицы с разными размерами не равны
}
TEST(S21MatrixTest, InequalityMatricesWithDifferentValues) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 5.0; // Изменяем значение

  EXPECT_FALSE(mat1 ==
               mat2); // Ожидаем, что матрицы с разными значениями не равны
}
// Тест 1: Проверка корректного сложения матриц одинаковых размеров
TEST(S21MatrixTest, OperatorPlusEqual_SameSize) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;

  mat1 += mat2; // Используем оператор +=

  EXPECT_EQ(mat1(0, 0), 6.0); // Проверка суммы элементов
  EXPECT_EQ(mat1(0, 1), 8.0);
  EXPECT_EQ(mat1(1, 0), 10.0);
  EXPECT_EQ(mat1(1, 1), 12.0);
}

// Тест 2: Проверка корректного сложения матриц с отрицательными значениями
TEST(S21MatrixTest, OperatorPlusEqual_NegativeValues) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = -1.0;
  mat1(0, 1) = -2.0;
  mat1(1, 0) = -3.0;
  mat1(1, 1) = -4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;

  mat1 += mat2; // Используем оператор +=

  EXPECT_EQ(mat1(0, 0), 0.0); // Проверка суммы элементов
  EXPECT_EQ(mat1(0, 1), 0.0);
  EXPECT_EQ(mat1(1, 0), 0.0);
  EXPECT_EQ(mat1(1, 1), 0.0);
}

// Тест 3: Проверка самоприсваивания
TEST(S21MatrixTest, OperatorPlusEqual_SelfAssignment) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat += mat; // Самоприсваивание

  EXPECT_EQ(mat(0, 0), 2.0); // Проверка результата
  EXPECT_EQ(mat(0, 1), 4.0);
  EXPECT_EQ(mat(1, 0), 6.0);
  EXPECT_EQ(mat(1, 1), 8.0);
}
// Тест 1: Проверка корректного вычитания матриц одинаковых размеров
TEST(S21MatrixTest, OperatorMinusEqual_SameSize) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 5.0;
  mat1(0, 1) = 6.0;
  mat1(1, 0) = 7.0;
  mat1(1, 1) = 8.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;

  mat1 -= mat2; // Используем оператор -=

  EXPECT_EQ(mat1(0, 0), 4.0); // Проверка разности элементов
  EXPECT_EQ(mat1(0, 1), 4.0);
  EXPECT_EQ(mat1(1, 0), 4.0);
  EXPECT_EQ(mat1(1, 1), 4.0);
}

// Тест 2: Проверка корректного вычитания матриц с отрицательными значениями
TEST(S21MatrixTest, OperatorMinusEqual_NegativeValues) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = -1.0;
  mat1(0, 1) = -2.0;
  mat1(1, 0) = -3.0;
  mat1(1, 1) = -4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;

  mat1 -= mat2; // Используем оператор -=

  EXPECT_EQ(mat1(0, 0), -2.0); // Проверка разности элементов
  EXPECT_EQ(mat1(0, 1), -4.0);
  EXPECT_EQ(mat1(1, 0), -6.0);
  EXPECT_EQ(mat1(1, 1), -8.0);
}

// Тест 3: Проверка самоприсваивания
TEST(S21MatrixTest, OperatorMinusEqual_SelfAssignment) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 5.0;
  mat(0, 1) = 6.0;
  mat(1, 0) = 7.0;
  mat(1, 1) = 8.0;

  mat -= mat; // Самоприсваивание

  EXPECT_EQ(mat(0, 0), 0.0); // Проверка результата
  EXPECT_EQ(mat(0, 1), 0.0);
  EXPECT_EQ(mat(1, 0), 0.0);
  EXPECT_EQ(mat(1, 1), 0.0);
}

// Тест 1: Проверка умножения матриц одинаковых размеров
TEST(S21MatrixTest, OperatorMultiplyEqual_Matrix_SameSize) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;

  mat1 *= mat2; // Используем оператор *=

  EXPECT_EQ(mat1(0, 0), 19.0); // Проверка результата умножения
  EXPECT_EQ(mat1(0, 1), 22.0);
  EXPECT_EQ(mat1(1, 0), 43.0);
  EXPECT_EQ(mat1(1, 1), 50.0);
}

// Тест 2: Проверка умножения матриц, где одна матрица является единичной
TEST(S21MatrixTest, OperatorMultiplyEqual_Matrix_Identity) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 5.0;
  mat1(0, 1) = 6.0;
  mat1(1, 0) = 7.0;
  mat1(1, 1) = 8.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 0.0;
  mat2(1, 1) = 1.0; // Единичная матрица

  mat1 *= mat2; // Используем оператор *=

  EXPECT_EQ(mat1(0, 0), 5.0); // Проверка, что результат остался прежним
  EXPECT_EQ(mat1(0, 1), 6.0);
  EXPECT_EQ(mat1(1, 0), 7.0);
  EXPECT_EQ(mat1(1, 1), 8.0);
}

// Тест 3: Проверка умножения матриц с нулями
TEST(S21MatrixTest, OperatorMultiplyEqual_Matrix_Zero) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 0.0;
  mat1(0, 1) = 0.0;
  mat1(1, 0) = 0.0;
  mat1(1, 1) = 0.0;

  S21Matrix mat2(2, 2);
  mat2(0, 0) = 5.0;
  mat2(0, 1) = 6.0;
  mat2(1, 0) = 7.0;
  mat2(1, 1) = 8.0;

  mat1 *= mat2; // Используем оператор *=

  EXPECT_EQ(mat1(0, 0),
            0.0); // Проверка, что результат умножения на ноль — это ноль
  EXPECT_EQ(mat1(0, 1), 0.0);
  EXPECT_EQ(mat1(1, 0), 0.0);
  EXPECT_EQ(mat1(1, 1), 0.0);
}

// Тест 1: Проверка умножения матрицы на число
TEST(S21MatrixTest, OperatorMultiplyEqual_Number) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat *= 2.0; // Используем оператор *=

  EXPECT_EQ(mat(0, 0), 2.0); // Проверка умножения на число
  EXPECT_EQ(mat(0, 1), 4.0);
  EXPECT_EQ(mat(1, 0), 6.0);
  EXPECT_EQ(mat(1, 1), 8.0);
}

// Тест 2: Проверка умножения матрицы на ноль
TEST(S21MatrixTest, OperatorMultiplyEqual_Zero) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat *= 0.0; // Умножаем на ноль

  EXPECT_EQ(mat(0, 0), 0.0); // Проверка результата умножения на ноль
  EXPECT_EQ(mat(0, 1), 0.0);
  EXPECT_EQ(mat(1, 0), 0.0);
  EXPECT_EQ(mat(1, 1), 0.0);
}

// Тест 3: Проверка умножения матрицы на отрицательное число
TEST(S21MatrixTest, OperatorMultiplyEqual_NegativeNumber) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat *= -2.0; // Умножаем на отрицательное число

  EXPECT_EQ(mat(0, 0), -2.0); // Проверка умножения на отрицательное число
  EXPECT_EQ(mat(0, 1), -4.0);
  EXPECT_EQ(mat(1, 0), -6.0);
  EXPECT_EQ(mat(1, 1), -8.0);
}
TEST(S21MatrixTest, AccessElement) {
  S21Matrix mat(3, 3); // Создаем матрицу 3x3

  // Изменяем элемент
  mat(1, 1) = 5.0;

  // Проверяем, что элемент изменился
  EXPECT_DOUBLE_EQ(mat(1, 1), 5.0);
}
TEST(S21MatrixTest, AccessElementInRange) {
  S21Matrix mat(3, 3); // Создаем матрицу 3x3

  // Проверяем доступ к элементам в пределах диапазона
  EXPECT_NO_THROW(mat(0, 0)); // Первая строка, первый столбец
  EXPECT_NO_THROW(mat(2, 2)); // Третья строка, третий столбец
  EXPECT_NO_THROW(mat(1, 2)); // Вторая строка, третий столбец
}
TEST(S21MatrixTest, AccessElementOutOfRange) {
  S21Matrix mat(3, 3); // Создаем матрицу 3x3

  // Проверяем выход за пределы матрицы
  EXPECT_THROW(mat(3, 3), std::out_of_range); // Индексы вне матрицы
  EXPECT_THROW(mat(-1, 0), std::out_of_range); // Отрицательный индекс
  EXPECT_THROW(mat(0, -1), std::out_of_range); // Отрицательный индекс
}

TEST(S21MatrixTest, GetMinor_2x2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4;
  matrix(0, 1) = 7;
  matrix(1, 0) = 2;
  matrix(1, 1) = 6;

  // Получение минора, исключая строку 0 и столбец 1
  S21Matrix minor = matrix.GetMinor(0, 1);

  EXPECT_EQ(minor.get_rows(), 1);
  EXPECT_EQ(minor.get_cols(), 1);
  EXPECT_DOUBLE_EQ(minor(0, 0), 2);
}

TEST(S21MatrixTest, GetMinor_3x3) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  // Получение минора, исключая строку 1 и столбец 1
  S21Matrix minor = matrix.GetMinor(1, 1);

  EXPECT_EQ(minor.get_rows(), 2);
  EXPECT_EQ(minor.get_cols(), 2);
  EXPECT_DOUBLE_EQ(minor(0, 0), 1);
  EXPECT_DOUBLE_EQ(minor(0, 1), 3);
  EXPECT_DOUBLE_EQ(minor(1, 0), 7);
  EXPECT_DOUBLE_EQ(minor(1, 1), 9);
}
TEST(S21MatrixTest, GetMinor_4x4) {
  S21Matrix matrix(4, 4);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(0, 3) = 4;
  matrix(1, 0) = 5;
  matrix(1, 1) = 6;
  matrix(1, 2) = 7;
  matrix(1, 3) = 8;
  matrix(2, 0) = 9;
  matrix(2, 1) = 10;
  matrix(2, 2) = 11;
  matrix(2, 3) = 12;
  matrix(3, 0) = 13;
  matrix(3, 1) = 14;
  matrix(3, 2) = 15;
  matrix(3, 3) = 16;

  // Получение минора, исключая строку 2 и столбец 2
  S21Matrix minor = matrix.GetMinor(2, 2);

  EXPECT_EQ(minor.get_rows(), 3);
  EXPECT_EQ(minor.get_cols(), 3);
  EXPECT_DOUBLE_EQ(minor(0, 0), 1);
  EXPECT_DOUBLE_EQ(minor(0, 1), 2);
  EXPECT_DOUBLE_EQ(minor(0, 2), 4);
  EXPECT_DOUBLE_EQ(minor(1, 0), 5);
  EXPECT_DOUBLE_EQ(minor(1, 1), 6);
  EXPECT_DOUBLE_EQ(minor(1, 2), 8);
  EXPECT_DOUBLE_EQ(minor(2, 0), 13);
  EXPECT_DOUBLE_EQ(minor(2, 1), 14);
  EXPECT_DOUBLE_EQ(minor(2, 2), 16);
}
TEST(S21MatrixTest, Determinant_1x1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5;

  double det = matrix.Determinant();

  EXPECT_DOUBLE_EQ(det, 5); // Проверяем, что детерминант равен 5
}
TEST(S21MatrixTest, Determinant_2x2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  double det = matrix.Determinant();

  EXPECT_DOUBLE_EQ(det, -2); // Проверяем, что детерминант равен -2
}
TEST(S21MatrixTest, Determinant_3x3) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 5;
  matrix(2, 0) = 1;
  matrix(2, 1) = 0;
  matrix(2, 2) = 6;

  double det = matrix.Determinant();

  EXPECT_DOUBLE_EQ(det, 22); // Проверяем, что детерминант равен 14
}
TEST(S21MatrixTest, Determinant1_3x3) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 4;
  matrix(1, 0) = 8;
  matrix(1, 1) = 7;
  matrix(1, 2) = 9;
  matrix(2, 0) = 1;
  matrix(2, 1) = 2;
  matrix(2, 2) = 3;

  double det = matrix.Determinant();

  EXPECT_DOUBLE_EQ(det, 9); // Проверка ожидаемого значения детерминанта
}
TEST(S21MatrixTest, Determinant_5x5) {
  S21Matrix matrix(5, 5);

  // Заполнение матрицы значениями
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(0, 3) = 4;
  matrix(0, 4) = 5;
  matrix(1, 0) = 6;
  matrix(1, 1) = 7;
  matrix(1, 2) = 8;
  matrix(1, 3) = 9;
  matrix(1, 4) = 10;
  matrix(2, 0) = 11;
  matrix(2, 1) = 12;
  matrix(2, 2) = 13;
  matrix(2, 3) = 14;
  matrix(2, 4) = 15;
  matrix(3, 0) = 16;
  matrix(3, 1) = 17;
  matrix(3, 2) = 18;
  matrix(3, 3) = 19;
  matrix(3, 4) = 20;
  matrix(4, 0) = 21;
  matrix(4, 1) = 22;
  matrix(4, 2) = 23;
  matrix(4, 3) = 24;
  matrix(4, 4) = 25;

  // Вычисление детерминанта
  double det = matrix.Determinant();

  // Проверка, что детерминант равен 0 для данной вырожденной матрицы
  EXPECT_DOUBLE_EQ(det, 0); // Матрица вырождена, детерминант должен быть 0
}
TEST(S21MatrixTest, CalcComplementsThrowsForNonSquareMatrix) {
  // Создаём прямоугольную матрицу (например, 2x3)
  S21Matrix matrix(2, 3);

  // Заполняем её значениями
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;

  // Проверяем, что выбрасывается исключение при попытке вычисления дополнений
  EXPECT_THROW(matrix.CalcComplements(), std::invalid_argument);
}
TEST(S21MatrixTest, CalcComplementsFor2x2Matrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), -2.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), 1.0);
}
TEST(S21MatrixTest, CalcComplementsFor3x3Matrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;
  matrix(2, 0) = 7.0;
  matrix(2, 1) = 8.0;
  matrix(2, 2) = 9.0;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), -3.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 6.0);
  EXPECT_DOUBLE_EQ(complements(0, 2), -3.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), -12.0);
  EXPECT_DOUBLE_EQ(complements(1, 2), 6.0);
  EXPECT_DOUBLE_EQ(complements(2, 0), -3.0);
  EXPECT_DOUBLE_EQ(complements(2, 1), 6.0);
  EXPECT_DOUBLE_EQ(complements(2, 2), -3.0);
}
TEST(S21MatrixTest, InverseMatrixFor2x2Matrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4.0;
  matrix(0, 1) = 7.0;
  matrix(1, 0) = 2.0;
  matrix(1, 1) = 6.0;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(inverse(0, 0), 0.6);
  EXPECT_DOUBLE_EQ(inverse(0, 1), -0.7);
  EXPECT_DOUBLE_EQ(inverse(1, 0), -0.2);
  EXPECT_DOUBLE_EQ(inverse(1, 1), 0.4);
}
TEST(S21MatrixTest, InverseMatrixForNonInvertibleMatrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 2.0;
  matrix(1, 1) = 4.0;

  // Детерминант этой матрицы равен 0, так как:
  // det(A) = (1 * 4) - (2 * 2) = 4 - 4 = 0
  EXPECT_THROW(matrix.InverseMatrix(), std::runtime_error);
}
TEST(S21MatrixTest, InverseMatrixFor1x1Matrix) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5.0;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(inverse(0, 0), 1.0 / 5.0);
}

// main
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}