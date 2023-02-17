#include <stdio.h>
/**
*main - A programe that prints in lowercase and uppercase
*Return:0(success)
*/
int main(void)
{
char a;
char b;
a = 'a';
b = 'A';
while
(a <= 'z')
{
putchar(a);
a++;
}
while
(b <= 'Z')
{
putchar(b);
b++;
}
putchar('\n');
return (0);
}
