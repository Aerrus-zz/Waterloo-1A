#include <stdio.h>

void main(){
	int dig[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
		//Fill it with -1 because some compilers take empty arrays to be filled with zero
	int input;
	int holder;
	int counter = 0;
	int reduced;
	int printflag = 0;
	
	scanf("%d", &input);
	
	while(input > 0)
	{
		printflag = 0;
		reduced = input;
		while(reduced > 0)
		{
			holder = reduced%10;
			if(holder != dig[0] && holder != dig[1] && holder != dig[2] && holder != dig[3] && holder != dig[4] && holder != dig[5] && holder != dig[6] && holder != dig[7] && holder != dig[8] && holder != dig[9])
			{
				printflag = 1;
			}
			reduced = reduced/10;
		}
		
		if(printflag == 1)
		{
			printf("%d\n", input);
			reduced = input;
			while(reduced > 0)
			{
				holder = reduced%10;
				if(holder != dig[0] && holder != dig[1] && holder != dig[2] && holder != dig[3] && holder != dig[4] && holder != dig[5] && holder != dig[6] && holder != dig[7] && holder != dig[8] && holder != dig[9])
				{
					dig[counter] = holder;
					counter++;
				}
				reduced = reduced/10;
			}
		
		}
		
		scanf("%d", &input);
	}

}