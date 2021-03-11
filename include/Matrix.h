#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
   public:
    int width, height;
    int* matrix;

    Matrix(int width, int height);
    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    Matrix& operator+=(Matrix&);
    Matrix& operator-=(Matrix&);
    Matrix& operator=(Matrix&);
    void transpose();
    void shape();
};

std::istream& operator>>(std::istream& is, Matrix& other);
std::ostream& operator<<(std::ostream& os, Matrix& other);

#endif