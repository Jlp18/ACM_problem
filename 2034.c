#include <stdio.h>
int main()
{
	int m , n;
	
	while(scanf("%d%d",&n , &m)!=EOF && (n!=0 || m!=0))
	{
		int a[n] , b[m];
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int j = 0 ; j < m ; j++)
		{
			scanf("%d",&b[j]);
		}
		int k = 0;
		int c[100];
		for(int i = 0 ; i < n ; i++)
		{
			int count = 0;
			for(int j = 0 ; j < m ; j++)
			{
				if(a[i] != b[j])
				{
					count++;
				}
				else
				{
					break;
				}			
			}
			if(count == m)
			{
				c[k] = a[i];
				k++;
			}
		}
		if(!k)
		{
			printf("NULL\n");
		}
		else //ÅÅÐò 
		{
			for(int i = 0 ; i < k-1 ; i++)
			{
				for(int j = 0 ; j < k-1 ; j++)
				{
					if(c[j] > c[j+1])
					{
						int temp;
						temp = c[j+1];
						c[j+1] = c[j];
						c[j] = temp;
					}
				}
			}
			for(int i = 0 ; i < k ; i++)
			{
				if(i == k-1)
				{
					printf("%d \n",c[i]);
				}
				else
				{
					printf("%d ",c[i]);
				}
			}
		}
	}
	return 0;
}