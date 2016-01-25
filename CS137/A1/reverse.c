#include <stdio.h>

int main(void){

	int i;

	scanf("%d",&i);

	if(i<0)
	{
		printf("-");
		i = -i;
	}

	if(i ==0){printf("0");}

	while(i!=0)
	{
		printf("%d", i%10);
		i = i/10;
	}

	printf("\n");
return 0;
}
