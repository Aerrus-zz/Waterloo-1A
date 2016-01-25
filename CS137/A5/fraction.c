#include <stdio.h>
#include "fraction.h"



struct fraction fractionCreate(int numerator, int denominator)
{
	struct fraction a = {.numerator = numerator, .denominator = denominator};
	return a;
}

struct fraction fractionAdd(struct fraction a, struct fraction b)
{
	struct fraction c;
	c.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
	c.denominator = a.denominator*b.denominator;
	return c;
}

struct fraction fractionSubtract(struct fraction a, struct fraction b)
{
	struct fraction c;
	c.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
	c.denominator = a.denominator*b.denominator;
	return c;
}

struct fraction fractionMultiply(struct fraction a, struct fraction b)
{
	struct fraction c;
	c.numerator = a.numerator*b.numerator;
	c.denominator = a.denominator*b.denominator;
	return c;
}

struct fraction fractionDivide(struct fraction a, struct fraction b)
{
	struct fraction c;
	c.numerator = a.numerator*b.denominator;
	c.denominator = a.denominator*b.numerator;
	return c;
}

int GCD(int a, int b)
{
	int r = a%b;
	while(r!=0)
	{
	a = b;
	b = r;
	r = a%b;
	}
	return b;
}

void fractionPrint(struct fraction f)
{
	int n1, n2, gcd, mult;
	int sign = 1;
	
	n1 = f.numerator;
	n2 = f.denominator;
	
	if(n1<0 && n2<0)
		{
		sign = 1;
		n1 = -n1;
		n2 = -n2;
		}
	else if(n1<0 && n2>0)
		{
		sign = 0;
		n1 = -n1;
		}
	else if(n1>0 && n2<0)
		{
		sign = 0;
		n2 = -n2;
		}
	
	if(n2 == 0)
		{printf("Divide by zero!\n");}
	else if(n1 == 0)
		{printf("0\n");}
	else if((n1/n2)>0)
		{
		if((n1%n2) == 0)
			{
			if(sign == 1){printf("%d\n",n1/n2);}
			else{printf("%d\n",-n1/n2);}
			}
		else
			{
			gcd = GCD(n1,n2);
			mult = n1/n2;
			n1 = n1-(n2*(n1/n2));
			if(sign==1){printf("%d  %d/%d\n",mult,n1/gcd,n2/gcd);}
			else{printf("%d  %d/%d\n",-mult,n1/gcd,n2/gcd);}
			}
		}
	else
		{
		gcd = GCD(n1,n2);
		if(sign==1){printf("%d/%d\n",n1/gcd,n2/gcd);}
		else{printf("%d/%d\n",-n1/gcd,n2/gcd);}
		}

	return 0;

}