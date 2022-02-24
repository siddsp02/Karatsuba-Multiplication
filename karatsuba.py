"""
Karatsuba's algorithm in Python.

References: https://en.wikipedia.org/wiki/Karatsuba_algorithm
"""

__author__ = "Siddharth Pai"
__email__ = "sidd.s.pai@gmail.com"
__version__ = "0.1"


def karatsuba(n1: int, n2: int) -> int:
    """Returns the product of two numbers using Karatsuba's algorithm.

    The following code was taken from wikipedia, and then converted to
    base-2 instead of base-10.

    :param n1: the first number
    :type n1: int
    :param n2: the second number
    :type n2: int
    :return: n1*n2
    :rtype: int
    """
    if n1 < 2 or n2 < 2:
        return n1*n2
    m = min(n1.bit_length(), n2.bit_length()) >> 1
    h1, l1 = n1 >> m, (1 << m) - 1 & n1
    h2, l2 = n2 >> m, (1 << m) - 1 & n2
    z0, z1, z2 = karatsuba(l1, l2), karatsuba(l1+h1, l2+h2), karatsuba(h1, h2)
    return (z2 << (m << 1)) + (z1 - z2 - z0 << m) + z0


def main() -> None:
    a = karatsuba(9, 8)
    print(a)


if __name__ == "__main__":
    main()