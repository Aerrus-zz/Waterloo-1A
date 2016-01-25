#include <stdio.h>
#include <stdbool.h>

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


int main(void){

	int n1, n2, gcd, mult;
	int sign = 1;
	
	scanf("%d\n%d",&n1,&n2);
	
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

