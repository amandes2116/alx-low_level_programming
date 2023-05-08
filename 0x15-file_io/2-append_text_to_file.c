#include "main.h"

/**
*append_text_to_file - Append a Text at The End Of  File
*@fn: The Pointer The Name File
*@texcont: String To Add at The End Of The File
*
*Return: The Function If Fails Or FileName Is NULL - -1
*The File If it Not Exist The User Can't Write Permission - -1
*Or Return -1
*/
int append_text_to_file(const char *fn, char *texcont)
{
int o, w, len = 0;
if (fn == NULL)
return (-1);
if (texcont != NULL)
{
for (len = 0; texcont[len];)
len++;
}
o = open(fn, O_WRONLY | O_APPEND);
w = write(o, texcont, len);
if (o == -1 || w == -1)
return (-1);
close(o);
return (1);
}
