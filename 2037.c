#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int s[100],f[100];
		bool A[100];
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d %d",&s[i],&f[i]);
		}
		//ÅÅÐò
		for(int p = 0 ; p < n ; p++)
		{
			for(int q = 0 ; q < n-p ; q++)
			{
				if(f[q] > f[q+1])
				{
					int temp1 , temp2;
					temp1 = f[q];
					f[q] = f[q+1];
					f[q+1] = temp1;
					
					temp2 = s[q];
					s[q] = s[q+1];
					s[q+1] = temp2;
				}
			}
		} 
		int x , y , count = 0;
		y = 0;
		for(x = 1 ; x < n ; x++)
		{
			if(s[x] >= f[y])
			{
				y = x;
				count ++;
			}
		}
		printf("%d\n",count+1);
	}
	return 0;
}
