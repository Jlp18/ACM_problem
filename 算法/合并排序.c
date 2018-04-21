#include <stdio.h>

void Merge(int c[] , int d[] , int l , int m , int r)//合并c[l:m]和c[m+1:r]到d[l:r] 
{
	int i = l , j = m + 1 , k = l;
	while((i <= m) && (j <= r))
	{
		if(c[i] <= c[j])
		{
			d[k++] = c[i++];
		}
		else
		{
			d[k++] = c[j++];
		}
	}
	if(i > m)
	{
		int q;
		for(q = j ; q <= r ; q++)
		{
			d[k++] = c[q];
		}
	}
	else
	{
		int q;
		for(q = i ; q <= m ;q++)
		{
			d[k++] = c[q];
		} 
	}
}


void MergePass(int x[] , int y[] , int s , int n) //合并大小为s的相邻子数组 
{
	int i = 0;
	while(i <= n-2*s)
	{
		//合并大小为s的相邻2段子数组
		Merge(x , y , i , i+s-1 , i+2*s-1);
		i = i + 2 * s; 
	} 
	//剩下的元素个数少于2s
	if(i+s < n)
	{
		Merge(x , y , i , i+s-1 , n-1);
	}
	else
	{
		int j;
		for(j = i ; j <= n-1 ; j++)
		{
			y[j] = x[j];
		}
	} 
}


void MergeSort(int a[] , int n)
{
	int *b;
	int o[n];
	b = o;
	int s = 1;
	while(s < n)
	{
		MergePass(a , b , s , n); //合并到数组b
		s += s;
		MergePass(b , a , s , n); //合并到数组a
		s += s; 
	}
}



int main()
{
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	MergeSort(a , 10);
	int i;
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0; 
}
