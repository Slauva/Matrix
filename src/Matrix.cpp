#include "../include/Matrix.h"

#include <iostream>
#include <stdexcept>

Matrix::Matrix(int width, int height) : width(width), height(height) {
    this->matrix = new int(height * width);
    for (int i = 0; i < height * width; i++)
        this->matrix[i] = 0;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (this->height != other.height || this->width != other.width)
        throw std::out_of_range("Matrix size error");
    Matrix res(other.width, other.height);
    for (int j = 0; j < other.height; j++)
        for (int i = 0; i < other.width; i++)
            *(res.matrix + i + j * other.width) = *(this->matrix + i + j * other.width) + *(other.matrix + i + j * other.width);
    return res;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (this->height != other.height || this->width != other.width)
        throw std::out_of_range("Matrix size error");
    Matrix res(other.width, other.height);
    for (int j = 0; j < other.height; j++)
        for (int i = 0; i < other.width; i++)
            *(res.matrix + i + j * other.width) = *(this->matrix + i + j * other.width) - *(other.matrix + i + j * other.width);
    return res;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (this->width != other.height)
        throw std::out_of_range("Column of first matrix should be equal to row of second matrix");
    Matrix res(other.width, this->height);
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < other.width; j++)
            for (int k = 0; k < this->width; k++)
                *(res.matrix + j + i * other.width) += *(this->matrix + k + i * this->width) * *(other.matrix + j + k * other.width);
    return res;
}

Matrix& Matrix::operator+=(Matrix& other) {
    if (this->height != other.height || this->width != other.width)
        throw std::out_of_range("Matrix size error");
    for (int j = 0; j < other.height; j++)
        for (int i = 0; i < other.width; i++)
            *(this->matrix + i + j * other.width) += *(other.matrix + i + j * other.width);
    return *this;
}

Matrix& Matrix::operator-=(Matrix& other) {
    if (this->height != other.height || this->width != other.width)
        throw std::out_of_range("Matrix size error");
    for (int j = 0; j < other.height; j++)
        for (int i = 0; i < other.width; i++)
            *(this->matrix + i + j * other.width) -= *(other.matrix + i + j * other.width);
    return *this;
}

Matrix& Matrix::operator=(Matrix& other) {
    width = other.width;
    height = other.height;
    matrix = other.matrix;
    return *this;
}

void Matrix::transpose() {
    Matrix res(height, width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            *(res.matrix + i + j * height) = *(matrix + j + i * width);
    width = res.width;
    height = res.height;
    matrix = res.matrix;
}

void Matrix::shape() {
    std::cout << "Width: " << width << "\nHeight: " << height << std::endl;
}

// Overloading function cin for matrix
std::istream& operator>>(std::istream& is, Matrix& other) {
    std::cout << "Enter a " << other.height << " by " << other.width << " Matrix:" << std::endl;
    for (int j = 0; j < other.height; j++)
        for (int i = 0; i < other.width; i++)
            std::cin >> *(other.matrix + i + j * other.width);
}

// Overloading function cout for matrix
std::ostream& operator<<(std::ostream& os, Matrix& other) {
    std::cout << "Output a " << other.height << " by " << other.width << " Matrix:" << std::endl;
    for (int j = 0; j < other.height; ++j) {
        for (int i = 0; i < other.width; ++i)
            std::cout << *(other.matrix + i + j * other.width) << " ";
        std::cout << std::endl;
    }
}