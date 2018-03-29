/**
 * @brief The C Programming Language - 2nd Edition, Exercise 4-9.
 *
 * @file calc.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 27/03/2018
 * @see https://github.com/caionegri
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define DPL '@'
#define SWP '#'
#define CLR '`'
#define SIN '~'
#define EXP '&'
#define POW '^'
#define ANS '_'
#define MEM '<'

int getop(char[]);
void push(double);
double pop(void);

/**
 * @brief RPN calculator.
 *
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int type = 0, last_type = 0;
    double op1 = 0.0, op2 = 0.0;
    char op[MAXOP] = {'\0'};
    double var[26] = {0.0}; /* a-z */
    double ans = 0.0;       /* last (printed) ANSwer */

    while ((type = getop(op)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(op));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if ((int)op2 != 0) {
                    push((int)pop() % (int)op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case SIN:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '=':
                op2 = pop();
                printf("\t%.8g\n", op2);
                ans = op2;
                push(op2);
                break;
            case DPL:
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case SWP:
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
                break;
            case CLR:
                while (pop() != 0.0) {
                    ;
                }
                break;
            case MEM:
                op2 = pop();
                if (last_type >= 'a' && last_type <= 'z') { /* store variable */
                    op1 = pop();
                    var[last_type - 'a'] = op1;
                    push(op1);
                } else {
                    printf("error: invalid variable\n");
                    push(op2);
                }
                break;
            case ANS:
                push(ans);
                break;
            case '\n':
                op2 = pop();
                printf("\t%.8g\n", op2);
                ans = op2;
                break;
            default:
                if (type >= 'a' && type <= 'z') { /* use variable */
                    push(var[type - 'a']);
                } else {
                    printf("error: unknown command %s\n", op);
                }
                break;
        }
        last_type = type;
    }
    return 0;
}
/******************************************************************************/
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/**
 * @brief Push f onto value stack.
 *
 * @param f
 */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/**
 * @brief Pop and return top value from stack.
 *
 * @return double
 */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/******************************************************************************/
#include <ctype.h>

int getch(void);
void ungetch(int);

/**
 * @brief Get next operator or numeric operand in @p s
 *
 * @param s input array
 * @return int
 */
int getop(char s[]) {
    int i = 0;
    int c = '\0';

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') { /* not a number */
        return c;
    }
    if (c == '-')
        if (isdigit(c = getch())) { /* negative sign, keep going */
            s[++i] = c;
        } else { /* '-' operator, return */
            ungetch(c);
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
    ungetch(c);
    return NUMBER;
}
/******************************************************************************/
#define BUFFSIZE 100

int buf[BUFFSIZE] = {'\0'}; /* buffer for ungetch */
int bufp = 0;               /* next ferr position in buf */

/**
 * @brief Get a (possibly pushed back) character.
 *
 * @return int
 */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/**
 * @brief Push character back on input.
 *
 * @param c
 */
void ungetch(int c) {
    if (bufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}