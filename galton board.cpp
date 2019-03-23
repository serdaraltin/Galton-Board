
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <pthread.h>

using namespace std;



int main()
{

srand(time(0));
	int* counts[20];
	int tl = 0 ;
	 

	for(int i =0; i<20; i++)
	{
		counts[i] = new int[i+1];
		for(int j = 0; j<= i; j++)
		{
				tl += i*j;
			counts[i][j] = 0;
		}
	}
	
	const int RUNS = 1000000;
	
	
	for(int run = 0; run < RUNS; run++)
	{
		counts[0][0]++;
		
		int j=0;
		for(int i=1; i<20; i++)
		{
			int r = rand() % 2;
			if(r==1)
			{
				j++;
			}		
			counts[i][j]++;
		}
	}
	
	
	



for (int i=19; i <20; i++)
{
	for(int j=0; j<=i; j++)
	{
	
		cout << j << " : " << counts[i][j] << endl ;	
	}
	cout << endl;
}

for (int i=0; i <20; i++)
{
	delete[] counts[i];
}

cout << "Value  : " << RUNS << endl << "Thread : " << tl;


getch();
return 0 ;
}












