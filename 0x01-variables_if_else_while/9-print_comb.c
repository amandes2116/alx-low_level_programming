#include <stdio.h>
/**
*main - A program that print possible combinationa of single digit numbers.
*Return:0(sucess)
*/
int main(void)
{
int a;
for (a = 0; a < 10; a++)
{
putchar(a + '0');
if (a < 9)
{
putchar(',');
putchar(' ');
}
}
putchar('\n');
return (0);
}
