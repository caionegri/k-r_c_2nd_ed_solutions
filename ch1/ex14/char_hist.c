/**
 * @brief The C Programming Language - 2nd Edition, Exercise 1-14.
 *
 * @file char_hist.c
 * @version 1.0
 * @author Caio A N Rocha
 * @date 14/02/2018
 * @see https://github.com/caionegri 
 */

#include <stdio.h>
/**
 * @brief Prints histogram of character (A-Z) frequency input.
 * 
 * @param argc command line argument count
 * @param argv command line argument vector
 * @return zero 
 */

int main(int argc, char *agrv[]) {
    int c;
    int maxf;
    int freq[26] = {0};  /* English alphabet - 26 letters */
    
    while((c = getchar()) != EOF) {
        if(c == 'a' || c == 'A')
            ++freq[0];
        if(c == 'b' || c == 'B')
            ++freq[1];
        if(c == 'c' || c == 'C')
            ++freq[2];
        if(c == 'd' || c == 'D')
            ++freq[3];
        if(c == 'e' || c == 'E')
            ++freq[4];
        if(c == 'f' || c == 'F')
            ++freq[5];
        if(c == 'g' || c == 'G')
            ++freq[6];
        if(c == 'h' || c == 'H')
            ++freq[7];
        if(c == 'i' || c == 'I')
            ++freq[8];
        if(c == 'j' || c == 'J')
            ++freq[9];
        if(c == 'k' || c == 'K')
            ++freq[10];
        if(c == 'l' || c == 'L')
            ++freq[11];
        if(c == 'm' || c == 'M')
            ++freq[12];
        if(c == 'n' || c == 'N')
            ++freq[13];
        if(c == 'o' || c == 'O')
            ++freq[14];
        if(c == 'p' || c == 'P')
            ++freq[15];
        if(c == 'q' || c == 'Q')
            ++freq[16];
        if(c == 'r' || c == 'R')
            ++freq[17];
        if(c == 's' || c == 'S')
            ++freq[18];
        if(c == 't' || c == 'T')
            ++freq[19];
        if(c == 'u' || c == 'U')
            ++freq[20];
        if(c == 'v' || c == 'V')
            ++freq[21];
        if(c == 'w' || c == 'W')
            ++freq[22];
        if(c == 'y' || c == 'Y')
            ++freq[23];
        if(c == 'x' || c == 'X')
            ++freq[24];
        if(c == 'z' || c == 'Z')
            ++freq[25];
    }
    /* find maximum frequenchary */
    maxf = 0;
    for(int i = 0; i < 26; ++i)
            if(freq[i] > maxf)
                maxf = freq[i];
    /* print histogram */
    printf("Character (A-Z) frequency histogram\n");
    for(int j = maxf; j > 0; --j) {
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= j)
                printf("_ ");
            else
                printf("  ");
        }
        printf("\n");
    }
    /* x axis lebels */
    printf("a b c d e f g h i j k l m n o p q r s t u v w x y z");
    
    return 0;
}