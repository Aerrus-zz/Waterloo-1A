#include <stdio.h>
#include "event.h"

int freetime(struct event schedule[], int n, int hour, int min)
{
	for(int i = 0; i < n; i++)
	{
		if(schedule[i].start.hour == hour && schedule[i].start.minute <= min)
		{
			if(hour < schedule[i].end.hour)
			{
				return 0;
			}
			else if(hour == schedule[i].end.hour)
			{
				if(min < schedule[i].end.minute)
				{
					return 0;
				}
			}
		}
		
		if(schedule[i].start.hour < hour && hour <= schedule[i].end.hour)
		{
			if(hour < schedule[i].end.hour)
			{
				return 0;
			}
			else if(hour == schedule[i].end.hour)
			{
				if(schedule[i].start.minute <= min && min < schedule[i].end.minute)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}