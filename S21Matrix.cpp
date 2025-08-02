#include "s21_matrix_oop.h"
// Декомпозиция
bool S21Matrix::SizesEqual(const S21Matrix &other) const {
  return (_rows == other._rows && _cols == other._cols);
}

// Методы доступа
void S21Matrix::SetElement(int row, int col, double value) {
  matrix[row][col] = value;
}
double S21Matrix::GetElement(int row, int col) const {
  return matrix[row][col];
}
int S21Matrix::get_rows() const { return _rows; }
int S21Matrix::get_cols() const { return _cols; }

// Конструкторы и деструкторы
S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  matrix = nullptr;
}

// S21Matrix::S21Matrix(int rows, int cols) {

//   if (rows <= 0 || cols <= 0) {
//     throw std::invalid_argument(
//         "Количество строк и столбцов должно быть положительным.");
//   }
//   _rows = rows;
//   _cols = cols;

//   matrix = new double *[rows];

//   for (int i = 0; i < rows; i++) {
//     matrix[i] = new double[cols];
//     for (int j = 0; j < cols; j++) {
//       matrix[i][j] = 0.0;
//     }
//   }
// }

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument(
        "Количество строк и столбцов должно быть положительным.");
  }
  _rows = rows;
  _cols = cols;

  matrix = new double *[rows];

  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[cols];
    // Используем std::fill для инициализации элементов матрицы нулями
    std::fill(matrix[i], matrix[i] + cols, 0.0);
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {

  _rows = other._rows;
  _cols = other._cols;

  matrix = new double *[_rows];
  for (int i = 0; i < _rows; i++) {
    matrix[i] = new double[_cols];
  }

  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {

  _rows = other._rows;
  _cols = other._cols;

  matrix = other.matrix;

  other._rows = 0;
  other._cols = 0;
  other.matrix = nullptr;
}
S21Matrix::~S21Matrix() {
  if (matrix != nullptr) {
    for (int i = 0; i < _rows; i++) {
      if (matrix[i] != nullptr) {
        delete[] matrix[i];
      }
    }
    delete[] matrix;
    matrix = nullptr;
  }
}
// Операции над матрицами
bool S21Matrix::eq_matrix(const S21Matrix &other) const {
  bool flag = true;
  if (!SizesEqual(other)) {
    flag = false;
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      if (std::fabs(matrix[i][j] - other.matrix[i][j]) > 1e-6) {
        flag = false;
      }
    }
  }
  return flag;
}

void S21Matrix::sum_matrix(const S21Matrix &other) {
  if (!SizesEqual(other)) {
    throw std::out_of_range("Ширина и длинна должны быть идентичны");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      matrix[i][j] += other.matrix[i][j];
    }
  }
}
void S21Matrix::sub_matrix(const S21Matrix &other) {
  if (!SizesEqual(other)) {
    throw std::out_of_range("Ширина и длинна должны быть идентичны");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      matrix[i][j] -= other.matrix[i][j];
    }
  }
}
void S21Matrix::mul_number(double n) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      matrix[i][j] *= n;
    }
  }
}
void S21Matrix::mul_matrix(const S21Matrix &other) {
  if (_cols != other._rows) {
    throw std::out_of_range(
        "Число столбцов первой матрицы должно быть равно числу строк второй "
        "матрицы");
  }
  S21Matrix result(_rows, other._cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < other._cols; ++j) {
      result.matrix[i][j] = 0.0;
      for (int k = 0; k < _cols; k++) {
        result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
      }
    }
  }
  *this = result;
}
S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(_cols, _rows);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      result.matrix[j][i] = matrix[i][j];
    }
  }
  return result;
}
S21Matrix S21Matrix::GetMinor(int row, int col) const {
  S21Matrix minor(_rows - 1, _cols - 1);
  int minor_row = 0;
  for (int i = 0; i < _rows; i++) {
    if (i == row)
      continue;
    int minor_col = 0;
    for (int j = 0; j < _cols; j++) {
      if (j == col)
        continue;
      minor.matrix[minor_row][minor_col] = matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
  return minor;
}
double S21Matrix::Determinant() const {
  if (_rows != _cols) {
    throw std::invalid_argument("Матрица должна быть квадратной");
  }
  if (_rows == 1) {
    return matrix[0][0];
  }
  if (_rows == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  }
  double det = 0.0;
  for (int j = 0; j < _cols; j++) {
    S21Matrix minor_matrix = GetMinor(0, j);
    double minor_det = minor_matrix.Determinant();
    double sign = (j % 2 == 0) ? 1 : -1;
    det += sign * matrix[0][j] * minor_det;
  }
  return det;
}
S21Matrix S21Matrix::CalcComplements() const {
  if (_rows != _cols) {
    throw std::invalid_argument("Матрица должна быть квадратной");
  }
  S21Matrix result(_rows, _cols);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      S21Matrix minor_matrix = GetMinor(i, j);
      double minor_determinant = minor_matrix.Determinant();
      result.matrix[i][j] = minor_determinant * ((i + j) % 2 == 0 ? 1 : -1);
    }
  }
  return result;
}
S21Matrix S21Matrix::InverseMatrix() const {

  if (_cols != _rows) {
    throw std::invalid_argument("Матрица должна быть квадратной.");
  }
  if (_rows == 1) {
    S21Matrix inverse_matr(1, 1);
    inverse_matr(0, 0) = 1.0 / (*this)(0, 0);
    return inverse_matr;
  }
  S21Matrix complements = this->CalcComplements();
  S21Matrix transposed = complements.Transpose();

  double det = this->Determinant();

  if (det == 0) {
    throw std::runtime_error("Детерминант равен 0");
  }
  return transposed * (1.0 / det);
}
