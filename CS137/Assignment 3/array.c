#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Sort(int array[], int howMany)
{

	int i = 0;
	int swapped = 0;

	while(1)
	{
		swapped = 0;
		for(i=0; i < howMany - 1; i++)
		{
		if(array[i] > array[i+1])
		{
			int temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			swapped=1;
			}
		}
		if(swapped == 0)
		{
			break;
		}
	}

}


int max(int array[], int n)
{
        if(n == 0)
        {
                return 0;
        }

        int max = array[0];

        for(int i = 1; i < n; i++)
        {
                if(array[i] > max)
                {
                        max = array[i];
                }
        }

        return max;
}

int countValue(int array[], int n, int value)
{
        int count = 0;

        if(n == 0)
        {
                return 0;
        }

        for(int i = 0; i < n; i++)
        {
                if(array[i] == value)
                {
                        count++;
                }
        }

        return count;
}

void absolute(int array[], int n)
{
        if(n == 0)
        {
                return;
        }

        for(int i = 0; i < n; i++)
        {
                array[i] = abs(array[i]);
        }

        return;
}

int isSorted(int array[], int n)
{
        if(n == 0)
        {
                return 1;
        }

        for(int i = 1; i < n; i++)
        {
                if(array[i-1] <= array[i])
                {
                        //Do nothing
                }
                else
                {
                        return 0;
                }
        }

        return 1;
}

int isPermutation(int array[], int n)
{
        if(n == 0)
        {
                return 1;
        }
		
		int b[n];
		
		for(int i = 0; i < n; i++)
		{
			b[i] = array[i];
		}

        Sort(b,n); //send over copy

        for(int i = 1; i <= n; i++)
        {
                if(b[i-1] == i) //note array[i-1]
                {
//      Seems to be bug testing                  printf("array %d   i %d", array[i], i);
                        //DO NOTHING
                }
                else
                {
                        return 0;
                }
        }

        return 1;
}


//COPY PASTA
/*
int main (void)
{
  int i;
  int a[5] = {5,3,2,4,1};
  int b[5] = {-1, 0, 0, 0, 1};
  int c[5] = {-10, 9, -8 , 7, -6};

  printf("max(a, 5) = %d\n", max(a, 5));
  printf("countValue (a, 5, 1) = %d\n", countValue (a, 5, 1));
  printf("countValue (a, 5, 0) = %d\n", countValue (a, 5, 0));
  printf("isSorted (a, 5) = %d\n", isSorted (a, 5));

printf("isPermutation (a, 5) = %d\n", isPermutation (a, 5));

  printf("max(b, 5) = %d\n", max(b, 5));
  printf("countValue (b, 5, 1) = %d\n", countValue (b, 5, 1));
  printf("countValue (b, 5, 0) = %d\n", countValue (b, 5, 0));
  printf("isSorted (b, 5) = %d\n", isSorted (b, 5));
  printf("isPermutation (b, 5) = %d\n", isPermutation (b, 5));

  absolute (c, 5);
  for (i = 0; i < 5; i++)
    printf ("c[%d] = %d\n", i, c[i]);


  return 0;
}
*/