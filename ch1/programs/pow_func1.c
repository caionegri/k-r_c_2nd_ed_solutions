/**
 * @file pow_func1.c
 * @brief The C Programming Language - 2nd Edition,
 * Section 1.7 example
 */
#include <stdio.h>

int power(int m, int n);

/* test power function */
int main(int argc, char *argv[]) {
    for(int i = 0; i < 10; ++i)
        printf("%d\t%d\t%d\n", i, power(2, i), power(-3, i));
    return 0;
}

/* power: raise base to n_th power; n <= 0; */
int power( int base, int n) {
    int i, p;
     p = 1;
     for(i = 1; i <= n; ++i)
        p = p * base;
    return p;
}