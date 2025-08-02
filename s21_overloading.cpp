#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  if (!SizesEqual(other)) {
    throw std::invalid_argument(
        "Матрицы должны иметь одинаковые размеры для сложения.");
  }
  S21Matrix result(*this);
  result.sum_matrix(other);
  return result;
}
S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  if (!SizesEqual(other)) {
    throw std::invalid_argument(
        "Матрицы должны иметь одинаковые размеры для вычитания.");
  }
  S21Matrix result(*this);
  result.sub_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  if (_cols != other._rows) {
    throw std::invalid_argument(
        "Количество столбцов первой матрицы должно совпадать с количеством "
        "строк второй матрицы для умножения.");
  }
  S21Matrix result(*this);
  result.mul_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result(*this);
  result.mul_number(num);
  return result;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    if (matrix != nullptr) {
      for (int i = 0; i < _rows; ++i) {
        delete[] matrix[i];
      }
      delete[] matrix;
    }
    _rows = other._rows;
    _cols = other._cols;

    matrix = new double *[_rows];
    for (int i = 0; i < _rows; ++i) {
      matrix[i] = new double[_cols];
      for (int j = 0; j < _cols; ++j) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return eq_matrix(other);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->sum_matrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->sub_matrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->mul_matrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  this->mul_number(num);
  return *this;
}
double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= _rows || col < 0 || col >= _cols) {
    throw std::out_of_range("Индекс за пределами матрицы.");
  }
  return matrix[row][col];
}

const double &S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= _rows || col < 0 || col >= _cols) {
    throw std::out_of_range("Индекс за пределами матрицы.");
  }
  return matrix[row][col];
}
