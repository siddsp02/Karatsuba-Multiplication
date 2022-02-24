/**
 * @file karatsuba.cpp
 * @author Siddharth Pai (sidd.s.pai@gmail.com)
 * @brief Karatsuba's algorithm in C++.
 * @version 0.1
 * @date 2022-02-23 
 */

#include <iostream>
#include <cmath>

#define min(x, y) ((x < y) ? x : y)

/**
 * @brief Returns the product of two numbers using Karatsuba's Algorithm.
 *
 * The following code was taken from wikipedia, and then converted to
 * base-2 instead of base-10.
 *
 * @see [Karatsuba's Algorithm](https://en.wikipedia.org/wiki/Karatsuba_algorithm)
 * @param n1 the first number
 * @param n2 the second number
 * @return int
 */
int karatsuba(int n1, int n2) {
    if (n1 < 2 || n2 < 2)
        return n1 * n2;
    int p, q;
    std::frexp(n1, &p);
    std::frexp(n2, &q);
    int m = min(p, q) >> 1;
    int h1 = n1 >> m, l1 = (1 << m) - 1 & n1;
    int h2 = n2 >> m, l2 = (1 << m) - 1 & n2;
    int z0 = karatsuba(l1, l2), z1 = karatsuba(l1+h1, l2+h2), z2 = karatsuba(h1, h2);
    return (z2 << (m << 1)) + (z1 - z2 - z0 << m) + z0;
}

int main() {
    int a = karatsuba(121, 318);
    std::cout << a << '\n';
    return 0;
}
