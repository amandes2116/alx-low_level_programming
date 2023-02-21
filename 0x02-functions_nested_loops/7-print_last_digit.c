#include "main.h"
/**
*main - check the code.
*print_last_digit - prints the last digit
*Return:0 value of the last digit
*/
int main(void)
{
int r;
print_last_digit(98);
print_last_digit(0);
r = print_last_digit(-1024);
_putchar('0' + r);
_putchar('\n');
return (0);
}
