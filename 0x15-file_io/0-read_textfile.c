#include "main.h"
#include <stdlib.h>

/**
* read_textfile- read Text File Print To an STDOUT.
* @fn: The File Text Being To Read
* @let: The Numbers Of letter Are To Be Read
* Return: w- The Actual Numbers Of Byte Read & Printe
*When 0 Functions Fail 0 FileName Is To  NULL
*/
ssize_t read_textfile(const char *fn, size_t let)
{
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;
fd = open(fn, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * let);
t = read(fd, buf, let);
w = write(STDOUT_FILENO, buf, t);
free(buf);
close(fd);
return (w);
}
