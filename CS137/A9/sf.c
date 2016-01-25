#include <stdio.h>
#include "sf.h"

int straightflush(struct card hand[], int n)
{
	struct card temp;
	char suite;
	int value;
	
	//c,d,h,s
	int c[15];
	int d[15];
	int h[15];
	int s[15];
	
	for(int i = 0; i < 15; i++)
	{
		c[i] = 0;
		d[i] = 0;
		h[i] = 0;
		s[i] = 0;
	}
	
	for(int i = 0; i < n; i++)
	{
		temp = hand[i];
		value = temp.value;
		suite = temp.suit;
		
		if(suite == 'c')
		{
			c[value] = 1;
			if(value == 1)
			{
				c[14] = 1;
			}
		}
		else if(suite == 'd')
		{
			d[value] = 1;
			if(value == 1)
			{
				d[14] = 1;
			}
		}
		else if(suite == 'h')
		{
			h[value] = 1;
			if(value == 1)
			{
				h[14] = 1;
			}
		}
		else if(suite == 's')
		{
			s[value] = 1;
			if(value == 1)
			{
				s[14] = 1;
			}
		}
	}
	
	for(int i = 1; i < 11; i++)
	{
		if(c[i] == 1 && c[i+1] == 1 && c[i+2] == 1 && c[i+3] == 1 && c[i+4] == 1)
		{
			return 1;
		}
		else if(d[i] == 1 && d[i+1] == 1 && d[i+2] == 1 && d[i+3] == 1 && d[i+4] == 1)
		{
			return 1;
		}
		else if(h[i] == 1 && h[i+1] == 1 && h[i+2] == 1 && h[i+3] == 1 && h[i+4] == 1)
		{
			return 1;
		}
		else if(s[i] == 1 && s[i+1] == 1 && s[i+2] == 1 && s[i+3] == 1 && s[i+4] == 1)
		{
			return 1;
		}
	}
	
	
	return 0;
}