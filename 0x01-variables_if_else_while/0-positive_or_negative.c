#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
*main - A program that prints random number.
*the number stored in the variable n is positive or negative.
*Return:0 (success)
*/
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX /2;
if((n % 10)> 5)
{
printf("The last digit of %d is %d and is graterthan 5\n", n, n%10);
}
else if((n % 10) < 6 && (n % 10) !=0)
{
printf("The last digit of %d is %d and less than 6 and not 0\n", n, n%10);
}
else
{
printf("The last digit of %d is %d and is 0\n", n, n%10);
}
return 0;
}
