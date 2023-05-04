#include "main.h"

/**
*binary_to_uint - Convert  Binary Numbers into unsigned int
*@c: String Contain The Binary Numbers
*
*Return: Converted Numbers
*/
unsigned int binary_to_uint(const char *c)
{
int i;
unsigned int dec_val = 0;
if (!c)
return (0);
for (i = 0; c[i]; i++)
{
if (c[i] < '0' || c[i] > '1')
return (0);
dec_val = 2 * dec_val + (c[i] - '0');
}
return (dec_val);
}
