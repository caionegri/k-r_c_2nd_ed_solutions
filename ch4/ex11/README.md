## The C Programming Language - 2nd Edition, Exercise 4-11.

I chose to include the entire calculator code to test the changes in `getop()`. Files are split in the structure suggested by the book. To compile all files into a single executable with gcc use:

    $ gcc -g -o calc main.c stack.c getop.c getch.c