#include <stdio.h>
/**
*main - A programe that prints the size of various computer types
*Return: 0 (success)
*/
int main(void)
{
pritf("Size of a char:%zu byte(s)\n", (unsigned long) sizeof(char));
printf("Size of a int:%zu byte(s)\n", (unsigned long) sizeof(int));
printf("Size of a long int:%zu byte(s)\n", (unsigned long) sizeof(long int));
printf("Size of a long long int:%zu byte(s)\n", (unsigned long) sizeof(long long int));
printf("Size of a float:%zu byte(s)\n", (unsigned long) sizeof(float));
return (0);
}
