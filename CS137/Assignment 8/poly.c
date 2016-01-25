#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

struct poly *polyCreate()
{
	struct poly *temp = malloc(sizeof(struct poly));
    temp->num = malloc(sizeof(double));
	temp->size = 1;
	temp->num[0] = 0.0;
	return temp;
}
struct poly *polyDelete(struct poly *p)
{
    if(p)
    {
        free(p->num);
        free(p);
    }
    
	return 0;
}
struct poly *polySetCoefficient(struct poly *p, int i, double value)
{
    int temp = p->size;
	
    while(p->size <= i)
    {
        p->size = p->size + 1;
        p->num = (double *)realloc(p->num, p->size * sizeof(double));
    }
    
    for(int j = temp; j < p->size; j++)
    {
        p->num[j] = 0.0;
        //Fills extra points to where we want with coefficient zero
    }
    p->num[i] = value;
    //What we actually want;
    
    return p;
}
double polyGetCoefficient(struct poly *p, int i)
{
	if(p->size < i) {return 0.0;}
    else
    {
        return p->num[i];
    }
}
int polyDegree(struct poly *p)
{
	return (int)(p->size - 1);
}
void polyPrint(struct poly *p)
{
	//Stole Chantelle's
	double *a = p->num;
	int n = p->size;
	int i, allZero = 1;
	if (n == 0)
	{
		printf ("0\n");
		return;
	}
	for (i = n - 1; i >= 0; --i){
		//print the sign
		if (a[i] < 0)
			if (allZero)
				printf ("-");
			else
				printf (" - ");
		else if (a[i] > 0 && !allZero)
		printf (" + ");
		//print the coefficient
		if (a[i] == 0) {
			if (i == 0 && allZero)
				printf ("%g", 0.0);
			} else if (fabs(a[i]) == 1) {
		if (i == 0)
			printf ("%g", 1.0);
		} else
			printf ("%g", fabs(a[i]));
	
	//print x^i
		if (i != 0 && a[i] != 0)
			if (i == 1)
				printf ("x");
			else
				printf ("x^%d", i);
		if (a[i] != 0)
		allZero = 0;
	}
	printf ("\n");

    
}
struct poly *polyCopy(struct poly *p)
{
	struct poly *temp= malloc(sizeof(struct poly));
	int n = p->size;
	double holder;

	for(int i = 0; i < n + 1; i++)
	{
		temp->num = realloc(temp->num, (i+1)*sizeof(double));
		holder = p->num[i];
		temp->num[i]= holder;
	}

	temp->size = n;
	
	return temp;
}
	
	
struct poly *polyAdd(struct poly *p0, struct poly *p1)
{
	int n;
	
	struct poly *temp;
	
	if(p0->size >= p1->size)
	{
		n = p1->size; //Gets smaller value so we know at which point the value exists
		temp = polyCopy(p0); //Fills the last digits as well
	}
	else
	{
		n = p0->size;
		temp = polyCopy(p1);
	}
	
	double holder0 = 0.0;
	double holder1 = 0.0;
	double holder = 0.0;
	
	for(int i = 0; i <= n; i++)
	{
		//Overrides all of the values that are different
		holder0 = polyGetCoefficient(p0, i);
		holder1 = polyGetCoefficient(p1, i);
		holder = holder0 + holder1;
		
		temp = polySetCoefficient(temp, i, holder);
	}
	
	return temp;
}
struct poly *polyMultiply(struct poly *p0, struct poly *p1)
{
	int size = p1->size + p0->size;
	struct poly *temp = polyCreate();
	
	double holder0 = 0.0;
	double holder1 = 0.0;
	double holder = 0.0;
	
	for(int i = 0; i < size; i++)
	{
		temp = polySetCoefficient(temp, i, 0.0);
	}
	
	temp->size = size - 1;
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < p0->size; j++)
		{
			for(int k = 0; k < p1->size; k++)
			{
				if(j+k == i) 
				{
					holder0 = polyGetCoefficient(p0, j);
					holder1 = polyGetCoefficient(p1, k);
					holder = holder + holder0 * holder1;
				}
			}
		}
		
		temp = polySetCoefficient(temp, i, holder);
		holder = 0.0;
	}
	
	return temp;
}
struct poly *polyPrime(struct poly *p)
{
	struct poly *temp = polyCreate();
	
	double holderCoef = 0.0;
	double holder = 0.0;
	
	for(int i = 1; i < p->size; i++)
	{
		holderCoef = polyGetCoefficient(p, i);
		holder = i * holderCoef;
		
		temp = polySetCoefficient(temp, i - 1, holder);
	}
	
	return temp;
}
double polyEval(struct poly *p, double x)
{
	double holder = 0.0;
	double coef = 0.0;
	double xpower = 0.0;
	
	for(int i = 0; i < p->size; i++)
	{
		coef = polyGetCoefficient(p, i);
		xpower = pow(x, i);
		holder = holder + (xpower * coef);
	}
	
	return holder;
}