#include <stdio.h>
/**
*main - A program that print numbers base 16 in lowercase.
*Return:0(success)
*/
int main(void)
{
char a;
int b;
a = 'a';
b = '0';
while
(b < 10)
{
putchar(b + '0');
b++;
}
while
(a <= 'f')
{
putchar(a);
a++;
}
putchar('\n');
return (0);
}
