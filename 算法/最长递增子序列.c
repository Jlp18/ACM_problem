#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int array[10000];
int B[10000]; 
int len;  
  
int LIS(int *array, int n); 
int BiSearch(int *b, int len, int w); 
  
int main()  
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&array[i]);
		}
		printf("%d\n", LIS(array, n)); 
	} 
    return 0;  
}  
  
int LIS(int *array, int n)  
{  
    len = 1;  
    B[0] = array[0];  
    int i, pos = 0;  
  
    for(i=1; i<n; ++i)  
    {  
        if(array[i] > B[len-1]) 
        {  
            B[len] = array[i];  
            ++len;  
        }  
        else  
        {  
            pos = BiSearch(B, len, array[i]);
            B[pos] = array[i];  
        }  
    }  
  
    return len;  
}   
int BiSearch(int *b, int len, int w)  
{  
    int left = 0, right = len - 1;  
    int mid;  
    while (left <= right)  
    {  
        mid = left + (right-left)/2;  
        if (b[mid] > w)  
            right = mid - 1;  
        else if (b[mid] < w)  
            left = mid + 1;  
        else  
            return mid;  
    }  
    return left; 
}
