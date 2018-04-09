#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int count = 0;
		int i , p , q;
		for(i = 2; i <= n/2 ; i++)
		{
			int k = 0;
			int x = sqrt(i);
			for(p = 2; p<=x; p++)
			{
				if(i%p==0)
				{
					break;
				}
			}
			if(p>x)
			{
				k++;
			}
			int y = sqrt(n-i);
			for(q = 2; q<=y; q++)
			{
				if((n-i)%q==0)
				{
					break;
				}
			}
			if(q>y && (n-i)!=n/2)
			{
				k++;
			}
			if(k==2)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
