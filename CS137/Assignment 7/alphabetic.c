#include <stdio.h>
#include <string.h>

char *alphabetic(const char *s)
{
	if(s == NULL)
	{
		return s;
	}
	
	char *letters = (char *)malloc((strlen(s)+1)*sizeof(char));
	int place = 0;
	
	for(int i = 0; i < strlen(s); i++)
	{
		if((s[i] >= 65) && (s[i] <= 90) || (s[i] >= 97) && (s[i] <= 122))
		{
			letters[place] = s[i];
			place++;
		}
	}
	
	return letters;
}