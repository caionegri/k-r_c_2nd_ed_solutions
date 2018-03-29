/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-11.
 *
 * @file getop.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 29/03/2018
 * @see https://github.com/caionegri 
 */

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/**
 * @brief Get next operator or numeric operand in @p s
 *
 * @param s input array
 * @return int
 */
int getop(char s[]) {
    int i = 0;
    int aux = 0;
    static int c = ' '; /* static variables are only initialized once, c will
                           maintain it's last value for next call */

    while ((s[0] = c) == ' ' || c == '\t') {
        c = getch();
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') { /* not a number */
        aux = c;
        c = ' '; /* force next call to update c */
        return aux;
    }
    if (c == '-')
        if (isdigit(c = getch())) { /* negative sign, keep going */
            s[++i] = c;
        } else { /* '-' operator, return */
            return '-';
        }
    if (isdigit(c)) { /* collect integer part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') { /* collect fractional part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    return NUMBER;
}