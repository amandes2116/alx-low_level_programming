#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
*main - A program that prints random number to the variable n each time it is executed.
*the number stored in the variable n is positive or negative.
*Return:0 (success)
*/
int main(void)
{
int n;
srand(time(0));
n = rand() % 201 - 100;
if (n >= 0)
{
putchar('P');
putchar('o');
putchar('s');
putchar('i');
putchar('t');
putchar('i');
putchar('v');
putchar('e');
}
else
{
putchar('N');
putchar('e');
putchar('g');
putchar('a');
putchar('t');
putchar('i');
putchar('v');
putchar('e');
}
return 0;
}
