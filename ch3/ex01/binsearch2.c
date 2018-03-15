/**
 * @brief The C Programming Language - 2nd Edition, Exercise 3-1.
 *
 * @file binsearch2.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 09/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>
#include <time.h>

#define NVALUES 100000 /* array size */

int binsearch2(int x, const int v[], int n);

/**
 * @brief Test modified function binsearch2().
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int v[NVALUES] = {0};   /* array of sorted values */
    int val = -1;   /* value o interest */
    int match = 0;  /* index of match */
    clock_t start = 0, end = 0;

    for (int i = 0; i < NVALUES; i++) v[i] = i;
    printf("Array: [0,1,...,%d]\n", NVALUES - 1);
    printf("Value: %d\n", val);

    start = clock();
    for (int i = 0; i < 10000000; i++)  /* multiple calls to measure time */
        match = binsearch2(val, v, NVALUES);
    end = clock();

    printf("Index of match: %d\n", match);
    printf("Clock cycles: %ld\n", end - start);

    return 0;
}

/**
 * @brief Binary search.
 *
 * @param x search value
 * @param v input array
 * @param n search limit
 * @return index where match was found
 * @return -1 if no match
 */
int binsearch2(int x, const int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == v[low])
        return low;
    else if (x == v[high])
        return high;
    else
        return -1;  /* no match */
}