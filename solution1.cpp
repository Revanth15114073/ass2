#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int max(int i, int j) 
{ 
	return (i > j) ? i : j;
}
int zig_zag(int a[], int n)
{
	int zz[n][2];
	
	for (int i = 0; i < n; i++)
		zz[i][0] = zz[i][1] = 1;
		
	int length = 1;
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && zz[i][0] < zz[j][1] + 1)
				zz[i][0] = zz[j][1] + 1;

			if( a[j] > a[i] && zz[i][1] < zz[j][0] + 1)
				zz[i][1] = zz[j][0] + 1;
		}

		if (length < max(zz[i][0], zz[i][1]))
			length = max(zz[i][0], zz[i][1]);
	}

	return length;
}

int main()
{
	int n;
	int A[n];
	cin>>n;
	for(int i=0; i<n ; i++)
	{
		cin>>A[i];
	}
	printf("Length of Longest Zig-Zag subsequence is %d\n",
			zig_zag(A, n) );
	return 0;
}
