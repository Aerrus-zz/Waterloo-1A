#include <stdio.h>
#include <stdbool.h>

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

bool isTwin(int i)
{
	if( isPrime(i) && (isPrime(i+2) || isPrime(i-2)) ) {return true;}
	return false;
}
/*
void testTwin (int number)
{
	if(isTwin(number)) {printf("%d is a twin prime\n", number);}
	else {printf("%d is not a twin prime\n", number);}
}

int main (void)
{
	testTwin(7);
	testTwin(13);
	testTwin(823);
	testTwin(2);
	testTwin(23);
	testTwin(100);
	testTwin(-3);
}
*/