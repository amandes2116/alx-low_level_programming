#include <stdio.h>
/**
*main - A program that print alphabet lowercase except q and e.
*Return:0(success)
*/
int main(void)
{
char a;
a = 'a';
while
(a <= 'z')
{
if ((a != 'q' && a != 'e') && a <= 'z')
putchar(a);
a++;
}
putchar('\n');
return (0);
}
