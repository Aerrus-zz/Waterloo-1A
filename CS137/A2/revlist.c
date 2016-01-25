#include <stdio.h>

void revList()
{
	int i = 0;
	scanf("%d", &i);
	if(i != 0) {revList();}
	printf("%d\n", i);
}

void main()
{
	revList();
}
