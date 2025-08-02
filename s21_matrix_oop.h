#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cassert>
#include <gtest/gtest.h>
#include <iostream>
#include <math.h>
#include <stdexcept>

class S21Matrix {
private:
  int _rows, _cols;
  double **matrix;

public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  void SetElement(int row, int col, double value);
  double GetElement(int row, int col) const;
  int get_rows() const;
  int get_cols() const;
  S21Matrix GetMinor(int row, int col) const;

  S21Matrix &operator=(const S21Matrix &other);
  double &operator()(int row, int col);
  const double &operator()(int row, int col) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  bool operator==(const S21Matrix &other) const;

  bool eq_matrix(const S21Matrix &other) const;
  void sum_matrix(const S21Matrix &other);
  void sub_matrix(const S21Matrix &other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix &other);

  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  bool SizesEqual(const S21Matrix &other) const;
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double num) const;
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double num);
};

#endif // __S21MATRIX_H__
