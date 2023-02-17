#include <stdio.h>
/**
*main - A programe that prints in lowercase and uppercase
*Return:0(success)
*/
int main(void)
{
for (char c = 'a'; c <= 'z'; c++)
{
putchar(c);
}
for (char c = 'A'; c <= 'Z'; c++)
{
putchar(c);
}
putchar('\n');
return (0);
}
