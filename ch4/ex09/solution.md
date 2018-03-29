## The C Programming Language - 2nd Edition, Exercise 4-9.

EOF is an implementation-defined negative integer (C99 definition), therefore there will be implicit conversion when storing EOF inside a char array. If the system representation for char is not able to represent the value of EOF (e.g.: chars are represented as unsigned integers), information will be lost and the backwards conversion will not recover EOF, in this case causing the program to be stuck in an endless while loop.

The way to fix this is storing characters as (signed) integers and converting to chars as needed. In this specific case, all we need to do is change buf to an array of integers.