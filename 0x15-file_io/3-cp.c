#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);
/**
*create_buffer - Allocate 1024 byte To  Buffer.
*@files: Name Of The File a Buffer Is Storing Char
*
*Return: Pointer The Newly-Allocate Buffer.
*/
char *create_buffer(char *files)
{
char *buffer;
buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", files);
exit(99);
}
return (buffer);
}
/**
*close_file - To File Close Descriptor.
*@filedes: File Descriptors To be Close.
*/
void close_file(int filedes)
{
int c;
c = close(filedes);
if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close filedes %d\n", filedes);
exit(100);
}
}
/**
* main - The Content  of Copy File To Another Files.
* @arc: Number Of The Argument Supplie To Program.
* @arv: The Array Of Pointer To The Argument.
*
* Return:Success 0.
*
* Description: The Argument count If Incorrect - Exit Code is 97.
* The File From Is  not Exist Or Can't Read - Exit Code is 98.
* The File To Can't Create Or Writeen - Exit Code is 99.
* The File To File From can't Be Close - Exit Code is 100.
*/
int main(int arc, char *arv[])
{
int from, to, r, w;
char *buffer;
if (arc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(arv[2]);
from = open(arv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(arv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", arv[1]);
free(buffer);
exit(98);
}
w = write(to, buffer, r);
if (to == -1 || w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", arv[2]);
free(buffer);
exit(99);
}
r = read(from, buffer, 1024);
to = open(arv[2], O_WRONLY | O_APPEND);
} while (r > 0);
free(buffer);
close_file(from);
close_file(to);
return (0);
}
