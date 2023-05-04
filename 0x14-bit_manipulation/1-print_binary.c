#include "main.h"

/**
* Print_Binary - Print Binary Equivalent sets of Decimal Numbers
* @p: Print Numbers at Binary
*/
void print_binary(unsigned long int p)
{
int i, count = 0;
unsigned long int current;
for (i = 63; i >= 0; i--)
{
current = p >> i;
if (current & 1)
{
_putchar('1');
count++;
}
else if (count)
_putchar('0');
}
if (!count)
_putchar('0');
}
