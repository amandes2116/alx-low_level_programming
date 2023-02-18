#include <stdio.h>
/**
*main - A program that print different commbinations of three digits.
*Return:0(success)
*/
int main(void)
{
int a = '0';
int b = '0';
int c = '0';
for (c = '0'; c <= '9'; c++)
{
for (b = '0'; b <= '9'; b++)
{
for (a = '0'; a <= '9'; a++)
{
if (!((a == b) || (b == c) || (b > a) || (c > b)))
{
putchar(c);
putchar(b);
putchar(a);
if (!(a == '9' && c == '7' && b == '8'))
{
putchar(',');
putchar(' ');

}
}
}
}
}
putchar('\n');
return (0);
}
