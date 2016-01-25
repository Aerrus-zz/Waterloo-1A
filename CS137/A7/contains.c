#include <stdio.h>
#include <string.h>

int contains(char *s, char *t)
{
	if(strcmp(s, t) == 0)
	{
		return 1;
	}
	
	//int counter = 0;
	int occurrence = 0;
	
	int sl = strlen(s);
	int tl = strlen(t);
	
	char *holder = (char *)malloc((strlen(t)+1)*sizeof(char));
	
	int i, j;
	
	for(int i = 0; i < sl - tl + 1; i++) //Don't count NULL character
	{
		strncpy(holder, &s[i], tl);
		
		if(strcmp(holder, t) == 0)
		{
			occurrence++;
		}
		
	}
	
	return occurrence;
}