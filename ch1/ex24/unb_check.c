/**
 * @file ubalanced_check.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 26/02/2018
 * @brief C Programming Language - 2nd Edition, 
 * Exercise 1-24.
 * @see https://github.com/caionegri 
 */

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */
#define IN 1        /* inside a comment */
#define OUT 0       /* outside a comment */

int getLine(char line[], int maxline);

/**
 * @brief 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero
 */
int main(int argc, char *argv[]) {
    int len = 0;                        /* current line lenght */
    char line[MAXLINE] = {'\0'};        /* current input line */
    int last_char = '\0';               /* last input character */
    int state = 0;                      /* current state */
    int last_state = 0;                 /* previous state */ // not used here
    int escp = 0;                       /* unmatched escape sequences ("\ ") */
    /* unbalanced parenteses, brackets, braces, quotes (single and double) */
    int paren = 0, brack = 0, brace = 0, squot = 0, dquot = 0;

    printf("Enter C code to remove comments.\n"); 
    
    while((len = getLine(line, MAXLINE)) > 0) {
        int j = 0;
        for(int i = 0; i < len; ++i) {
            if(state == IN) {
                if(last_char == '*' && line[i] == '/')
                    state = OUT;    /* comment ended */
                last_state = IN;
            }
            else {  /* state == OUT */
                if(last_char == '/' && line[i] == '*')
                    state = IN;     /* comment started */
                else if(last_char == '\\' && (line[i]==' ' || line[i]=='\t'))
                    ++ escp;
                else if(line[i] == '(')
                    ++paren;
                else if(line[i] == '[')
                    ++brack;
                else if(line[i] == '{')
                    ++brace;
                else if(line[i] == '\'')
                    ++squot;
                else if(line[i] == '\"')
                    ++dquot;
                else if(line[i] == ')')
                    --paren;
                else if(line[i] == ']')
                    --brack;
                else if(line[i] == '}')
                    --brace;
                last_state = OUT;                
            }
            last_char = line[i];
        }
    }
    printf("###### SYNTAX ERRORS ######\n"); 
    /* positive if too many opening operators, negative if too many closing
    operators , zero if balanced */
    printf("unbalanced parentheses  : %d\n", paren);
    printf("unbalanced brackets     : %d\n", brack);
    printf("unbalanced braces       : %d\n", brace);
    /* one if unbalanced, zero if balanced */
    printf("unbalanced single quotes: %d\n", squot%2);
    printf("unbalanced double quotes: %d\n", dquot%2);
    printf("unbalanced comments     : %d\n", state);
    /* number of unmatched escape sequences */
    printf("unmatched escpape seq.  : %d\n", escp);
 
    return 0;
}

/**
 * @brief Read a line and save into s, return length.
 * @param s line
 * @param lim maximum line length
 * @return line lenght
 */
int getLine(char s[], int lim) {
    int c = '\0', i = 0;

    for(; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}