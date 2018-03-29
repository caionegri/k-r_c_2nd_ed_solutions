/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-11.
 *
 * @file calc.h
 * @version 1.0
 * @author Caio A N Rocha
 * @date 29/03/2018
 * @see https://github.com/caionegri 
 */

#define NUMBER '0'

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);