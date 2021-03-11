# Linear Algebra: Matrix operations

## Table of Contents

-   [About](#about)
-   [Getting Started](#getting_started)
-   [Usage](#usage)
-   [Contributing](../CONTRIBUTING.md)

## About <a name = "about"></a>

A simple console application that allows you to calculate sum, difference, product and transposition over matrices.

## Getting Started <a name = "getting_started"></a>

All source _.cpp_ files are located in the **src** folder. Header files _.h_ in the **include** folder. The finished _.exe_ application in the **output** folder. If you want to extend the project with any libraries, then they can be located in the **lib** folder.
There is a **Makefile** collector for building projects.

### Prerequisites

What things you need to install the software and how to install them.

```cmd
cd ~/output
start main.exe
```

### Installing

To build a package

```сmd
cd ~/project name
make
```

End with an example of getting some data out of the system or using it for a little demo.

## Usage <a name = "usage"></a>

For test code you can use the template

```cpp
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
```
