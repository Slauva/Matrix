#include <iostream>

#include "../include/Matrix.h"

int main() {
    int w, h;

    std::cout << "Enter width of matrix: ";
    std::cin >> w;
    std::cout << "Enter height of matrix: ";
    std::cin >> h;
    Matrix a(w, h);
    std::cin >> a;

    int w1, h1;

    std::cout << "Enter width of matrix: ";
    std::cin >> w1;
    std::cout << "Enter height of matrix: ";
    std::cin >> h1;
    Matrix b(w1, h1);
    std::cin >> b;

    Matrix sum = a + b;
    Matrix sub = a - b;
    Matrix mul = a * b;
    Matrix ass = a;

    std::cout << sum;
    std::cout << sub;
    std::cout << mul;
    std::cout << ass;

    ass.transpose();
    std::cout << ass;

    std::system("pause");

    return 0;
}