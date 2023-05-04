#include "main.h"

/**
* get_endianness - This is To Check if Machine is Little Or Big endian
* Return: Big is 0 , Little is 1
*/
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *) &i;
return (*c);
}
