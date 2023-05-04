#include "main.h"

/**
* clear_bit - The Value of Given Bit To 0
* @p: This is Pointer To Change Number
* @ind: Index The Bit To Clear
*
* Return: Success 1 , -1 To Failure
*/
int clear_bit(unsigned long int *p, unsigned int ind)
{
if (ind > 63)
return (-1);
*p = (~(1UL << ind) & *p);
return (1);
}
