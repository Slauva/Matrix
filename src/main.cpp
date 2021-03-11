#include <iostream>

#include "../include/Matrix.h"

int main() {
    int w, h;
    std::cout << "Enter width of matrix:";
    std::cin >> w;
    std::cout << "Enter height of matrix:";
    std::cin >> h;
    Matrix a(w, h);
    std::cin >> a;
    a.transpose();
    std::cout << a;
    a.shape();
    std::system("pause");

    return 0;
}