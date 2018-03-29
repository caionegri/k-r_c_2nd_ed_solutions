## The C Programming Language - 2nd Edition, Exercise 4-7.

The function ungets() doesn't need to know about buf and bufp. The responsibility for managing buf and bufp is already assigned to getch() and ungetch() and we should keep it that way to avoid conflicts.