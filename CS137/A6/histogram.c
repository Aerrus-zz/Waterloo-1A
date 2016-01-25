#include <stdio.h>

int histogram(const int *a, int n, int *m)
{
	int max = a[0];
	for(int i = 1; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}

	int *histo = (int*)malloc((max+1)*sizeof(int));
	
	for(int i = 0; i < max + 1; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[j] == i)
			{
				histo[i] = histo[i] + 1;
			}
		}
	}
	
	*m = max + 1;

	return histo;
}