#include <stdio.h>

void polyPrint(double a[], int n)
{
	double cf = 0.0;
	int ncount = 0;
	int incs = 2;
	
	if(n == 1)
	{
		cf = a[n-1];
		printf("%g\n", cf);
		return;
	}
	else if(n <= 0)
	{
		printf("0\n");
		return;
	}
	else
	{
		if(a[n-1] < 0)
		{
			cf = a[n-1];
			if(cf == -1)
			{
				printf("-x^%d", n-1);
			}
			else
			{
				printf("-%gx^%d", -cf, n-1);
			}
		}
		else if(a[n-1] == 0)
		{
			for(int i = n-2; i > 1; i--)
			{
				if(a[i] != 0)
				{
					incs++;
					if(a[i] == 1)
					{
						printf("x^%d", i);
						break;
						
					}
					else if(a[i] == -1)
					{
						printf("-x^%d", i);
						break;
					}
					else
					{
						printf("%gx^%d", cf, i);
						break;
					}
				}
			}
			ncount++;
		}
		else if(a[n-1] > 0)
		{
			cf = a[n-1];
			if(cf == 1)
			{
				printf("x^%d", n-1);
			}
			else
			{
				printf("%gx^%d", cf, n-1);
			}
		}
	}
	
	for(int i = n-incs; i > 1; i--)
	{
		if(a[i] < 0)
		{
			cf = a[i];
			printf(" - %gx^%d", -cf, i);
		}
		else if(a[i] == 0)
		{
			//Do Nothing
			ncount++;
		}
		else if(a[i] > 0)
		{
			cf = a[i];
			if(cf == 1)
			{
				printf(" + x^%d", i);
			}
			else
			{
				printf(" + %gx^%d", cf, i);
			}
		}
	}
	
	cf = a[1];
	if(cf < 0)
	{
		printf(" - %gx", -cf);
	}
	else if(cf == 0)
	{
		//Do Nothing
		ncount++;
	}
	else if(cf > 0)
	{
		if(cf == 1)
		{
			printf(" + x");
		}
		else
		{
			printf(" + %gx", cf);
		}
	}
	
	
	cf = a[0];
	if(cf < 0)
	{
		printf(" - %g", -cf);
	}
	else if(cf == 0)
	{
		//Do Nothing
		ncount++;
	}
	else if(cf > 0)
	{
		printf(" + %g", cf);
	}
	
	if(ncount == n) {printf("0");}
	
	printf("\n");
}



//COPY PASTA
/*
int main (void)
{
  double a[] = {2.0, 3.0, 4.0};
  double b[] = {0.0, 3.0, 0.0};
  double c[] = {2.0, -2.0, 9.0, -1.0, 8.0, -7.0};
  double d[] = {2.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  double e[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double f[] = {2.0/3.0, 1.0/7.0, 9.0/13.0};

  polyPrint (a, sizeof(a)/sizeof(a[0]));
  polyPrint (b, sizeof(b)/sizeof(b[0]));
  polyPrint (c, sizeof(c)/sizeof(c[0]));
  polyPrint (d, sizeof(d)/sizeof(d[0]));
  polyPrint (e, sizeof(e)/sizeof(e[0]));
  polyPrint (f, sizeof(f)/sizeof(f[0]));

  return 0;
}
*/
/*
4x^2 + 3x + 2
3x
-7x^5 + 8x^4 - x^3 + 9x^2 - 2x + 2
x^5 + 2
0
0.692308x^2 + 0.142857x + 0.666667
*/