#include "main.h"
#include <unistd.h>
/**
* _putchar - Write the char c at stdout
* @c: the char to be print
*
* Return: Success 1.
* error -1 Return, errno is set appropriat.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
