#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num)
{
	int divisor = 2;
	if(num <= 1) {return false;}
	while((num/divisor) >= divisor)
	{
		if((num%divisor) == 0) {return false;}
		divisor++;
	}
	return true;
}

void factor(int number)
{
	printf("%d = ", number);
	
	if(isPrime(number))
	{
		printf("%d\n", number);
		return;
	}
	
	//Remove number of 2s, 
	while(number%2 == 0)
	{
		printf("%d*", 2);
		number = number/2;
	}
	
	for(int i = 3; i <= sqrt(number); i = i+2)
	{
		while(number%i == 0)
		{
			printf("%d", i);
			number = number/i;
			if(number == 0 || number == 1)
			{
				break;
			}
			printf("*");
		}
	}
	if(number != 0 && number != 1)
	{
		printf("%d",number);
	}
	printf("\n");
}

//COPY PASTA
/*
int main (void)
{
  factor (100);
  factor (21);
  factor (123392);
  factor (2769);
  return 0;
}
*/