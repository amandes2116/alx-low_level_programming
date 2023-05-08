#include "main.h"

/**
*create_file - To Create File.
*@fn: The Pointer To The Name  The File To Create.
*@texcont: Pointer To an String Write The File.
*
*Return: The Functions If Fail --1
*Or Return This  -1.
*/
int create_file(const char *fn, char *texcont)
{
int fd, w, len = 0;
if (fn == NULL)
return (-1);
if (texcont != NULL)
{
for (len = 0; texcont[len];)
len++;
}
fd = open(fn, O_CREAT | O_RDWR | O_TRUNC, 0600);
w = write(fd, texcont, len);
if (fd == -1 || w == -1)
return (-1);
close(fd);
return (1);
}
