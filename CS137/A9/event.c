#include <stdio.h>
#include "event.h"

int available(struct event schedule[], int n, struct event e)
{
	int startminutes[n];
	int endminutes[n];
	
	for(int i = 0; i < n; i++)
	{
		startminutes[i] = (schedule[i].start.hour)*60 + (schedule[i].start.minute);
		endminutes[i] = (schedule[i].end.hour)*60 + (schedule[i].end.minute);
	}
	
	int estart = e.start.hour*60 + e.start.minute;
	int eend = e.end.hour*60 + e.end.minute;
	
	for(int i = 0; i < n; i++)
	{
		if(estart > startminutes[i] && estart < endminutes[i])
		{
			return 0;
			//If the starting time is within a block
		}
		if(eend > startminutes[i] && eend < endminutes[i])
		{
			return 0;
			//If the ending time is within a block
		}
		if(startminutes[i] > estart && startminutes[i] < eend)
		{
			return 0;
			//If there is an event happenging inside our event
		}
	}
	
	return 1;
}

void sortSchedule(struct event schedule[], int n)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < (n-1); j++)
		{
			if(schedule[j+1].start.hour < schedule[j].start.hour)
			{
				int tempsh = schedule[j+1].start.hour;
				int tempsm = schedule[j+1].start.minute;
				int tempeh = schedule[j+1].end.hour;
				int tempem = schedule[j+1].end.minute;
				
				schedule[j+1].start.hour = schedule[j].start.hour;
				schedule[j+1].start.minute = schedule[j].start.minute;
				schedule[j+1].end.hour = schedule[j].end.hour;
				schedule[j+1].end.minute = schedule[j].end.minute;
				
				schedule[j].start.hour = tempsh;
				schedule[j].start.minute = tempsm;
				schedule[j].end.hour = tempeh;
				schedule[j].end.minute = tempem;
			}
			else if(schedule[j].start.hour == schedule[j+1].start.hour)
			{
				if(schedule[j+1].start.minute < schedule[j].start.minute)
				{
					int tempsh = schedule[j+1].start.hour;
					int tempsm = schedule[j+1].start.minute;
					int tempeh = schedule[j+1].end.hour;
					int tempem = schedule[j+1].end.minute;
				
					schedule[j+1].start.hour = schedule[j].start.hour;
					schedule[j+1].start.minute = schedule[j].start.minute;
					schedule[j+1].end.hour = schedule[j].end.hour;
					schedule[j+1].end.minute = schedule[j].end.minute;
				
					schedule[j].start.hour = tempsh;
					schedule[j].start.minute = tempsm;
					schedule[j].end.hour = tempeh;
					schedule[j].end.minute = tempem;
				}
			}
		}
	}
}