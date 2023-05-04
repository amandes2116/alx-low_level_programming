#include "main.h"

/**
* get_bit - Return a Value Bit at in Index in Decimal Number
* @s: Search Number
* @ind: index of  Bit
*
* Return: Value of  The Bit
*/
int get_bit(unsigned long int s, unsigned int ind)
{
int bit_val;
if (ind > 63)
return (-1);
bit_val = (s >> ind) & 1;
return (bit_val);
}
