/**
 * @file replace_char.c
 * @brief The C Programming Language - 2nd Edition,
 * Excercise 1-10
 * @author Caio A N Rocha
 * @date 14 Feb 2018
 */
#include <stdio.h>

/**
 * @brief Replace tabs, backspaces and backlashes by their escape sequences
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */
int main(int argc, char *argv[]) {
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\t'){
            putchar('\\');
            putchar('t');               
        }
        else if(c == '\b') { // How to input backspace in powershell?
            putchar('\\');
            putchar('b'); 
        }
        else if(c == '\\') {
            putchar('\\');
            putchar('\\'); 
        }
        else
            putchar(c);
    }

    return 0;
}