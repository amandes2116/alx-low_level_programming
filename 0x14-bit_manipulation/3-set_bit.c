#include "main.h"

/**
* set_bit - Set of Bit at Given Index to 1
* @p: Pointer To Change Numbers
* @ind: Index of Bit To Set 1
*
* Return: Success 1, -1 To Failure
*/
int set_bit(unsigned long int *p, unsigned int ind)
{
if (ind > 63)
return (-1);
*p = ((1UL << ind) | *p);
return (1);
}
