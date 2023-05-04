#include "main.h"

/**
* flip_bits - it Count  Number of Bit To Change
* Get One Number To Another
* @p: 1st Number
* @s: 2nd Number
*
* Return: Number of Bit To MakeNew
*/
unsigned int flip_bits(unsigned long int p, unsigned long int s)
{
int i, count = 0;
unsigned long int current;
unsigned long int exclusive = p ^ s;
for (i = 63; i >= 0; i--)
{
current = exclusive >> i;
if (current & 1)
count++;
}
return (count);
}
