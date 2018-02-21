/**
 * @file backslash_test.c
 * @brief The C Programming Language - 2nd Edition, Exercise 1-2
 * @author Caio A N Rocha
 * @date 14 Feb 2018 
 * @see https://en.wikipedia.org/wiki/Escape_sequences_in_C
 */
#include <stdio.h>

/**
 * @brief Test escape sequences
 */
main() {
    printf("test word: \\c1000\n");
    printf("\\a: \a1000\n");    // Alert (Bleep)
    printf("\\b: \b1000\n");    // Backspace
    printf("\\e: \e1000\n");    // Escape next character (some character sets)
    printf("\\f: \f1000\n");    // Formfeed
    printf("\\n: \n1000\n");    // Line Feed
    printf("\\r: \r1000\n");    // Carriage Return
    printf("\\t: \t1000\n");    // Horizontal Tab
    printf("\\u: \u1000\n");    // Unicode code point in hexadecimal
    printf("\\v: \v1000\n");    // Vertical Tab
    printf("\\x: \x10\x00");    // Byte given by a hexadecimal number
}
