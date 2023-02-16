#include <stdio.h>
/**
*main - A size of various computer types
*Return:0(success)
*/
int main(void)
{
char a;
int b;
long int c;
long long int d;
float e;
printf("Size of a char: %i byte(s)\n", (unsigned long)sizeof(a));
printf("Size of an int: %i byte(s)\n", (unsigned long)sizeof(b));
printf("Size of a long int: %i byte(s)\n", (unsigned long)sizeof(c));
printf("Size of a long long int: %i byte(s)\n", (unsigned long)sizeof(d));
printf("Size of a float: %i byte(s)\n", (unsigned long)sizeof(e));
return (0);
}
