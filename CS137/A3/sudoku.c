#include <stdio.h>

int sudoku(int grid[9][9])
{
	int tester=0;
	
	//Tests for all the rows and columns for duplicates
	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			for(int k = 0; k < 9; k++)
			{
				if(0<= grid[j][k] || grid[j][k] >= 10)
				{
					return 0;
				}
				
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			for(int k = 0; k < 9; k++)
			{
				if(0<= grid[k][j] || grid[k][j] >= 10)
				{
					return 0; //Double check because why not
				}
				
				if(i == grid[k][j])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Tests top left box
	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Top middle
	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 3; k < 6; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Top right
	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 6; k < 9; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Middle left
	for(int i = 1; i < 10; i++)
	{
		for(int j = 3; j < 6; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Middle middle
	for(int i = 1; i < 10; i++)
	{
		for(int j = 3; j < 6; j++)
		{
			for(int k = 3; k < 6; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Middle right
	for(int i = 1; i < 10; i++)
	{
		for(int j = 3; j < 6; j++)
		{
			for(int k = 6; k < 9; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Bottom left
	for(int i = 1; i < 10; i++)
	{
		for(int j = 6; j < 9; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Bottom middle
	for(int i = 1; i < 10; i++)
	{
		for(int j = 6; j < 9; j++)
		{
			for(int k = 3; k < 6; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	tester = 0;
	
	//Bottom right
	for(int i = 1; i < 10; i++)
	{
		for(int j = 6; j < 9; j++)
		{
			for(int k = 6; k < 9; k++)
			{
				if(i == grid[j][k])
				{
					if(tester = 1)
					{
						return 0;
					}
					else
					{
						tester = 1;
					}
				}
			}
		}
		tester = 0;
	}
	
	return 1;
}
/*
int main (void)
{
      int testGrid[9][9] = {
        {5,3,4,6,7,8,9,1,2},
	{6,7,2,1,9,5,3,4,8},
	{1,9,8,3,4,2,5,6,7},
	{8,5,9,7,6,1,4,2,3},
	{4,2,6,8,5,3,7,9,1},
	{7,1,3,9,2,4,8,5,6},
	{9,6,1,5,3,7,2,8,4},
	{2,8,7,4,1,9,6,3,5},
	{3,4,5,2,8,6,1,7,9} };

      printf ("%d\n", sudoku (testGrid));
}
*/