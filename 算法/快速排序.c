#include <stdio.h>

int Partition(int a[] , int p , int r)
{
	int i = p;
	int j = r + 1;
	int x = a[p];
	//将<x的元素交换到左边区域
	//将>x的元素交换到右边区域
	while(1)
	{
		while(a[++i] < x && i < r);
		while(a[--j] > x);
		if(i >= j)
		{
			break;
		}
		int temp;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[p] = a[j];
	a[j] = x;
	return j; 
}

void QuickSort(int a[] , int p , int r)
{
	if(p < r)
	{
		int q = Partition(a , p , r);
		QuickSort(a , p , q-1);  //对左半段排序 
		QuickSort(a , q+1 , r);  //对右半段排序 
	} 
}

int main()
{
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	QuickSort(a , 0 , 9);
	int i;
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0; 
}

