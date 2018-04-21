#include <stdio.h>

void Merge(int c[] , int d[] , int l , int m , int r)//�ϲ�c[l:m]��c[m+1:r]��d[l:r] 
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


void MergePass(int x[] , int y[] , int s , int n) //�ϲ���СΪs������������ 
{
	int i = 0;
	while(i <= n-2*s)
	{
		//�ϲ���СΪs������2��������
		Merge(x , y , i , i+s-1 , i+2*s-1);
		i = i + 2 * s; 
	} 
	//ʣ�µ�Ԫ�ظ�������2s
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
		MergePass(a , b , s , n); //�ϲ�������b
		s += s;
		MergePass(b , a , s , n); //�ϲ�������a
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
