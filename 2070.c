#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n != -1)
	{
		long long f , f1 , f2;
		f1 = 1;
		f2 = 1;
		if(n == 0)
		{
			printf("0\n");
		}
		else if(n == 1 || n == 2)
		{
			printf("1\n");
		}
		else
		{
			for(int i = 2 ; i < n ; i++)
			{
				f = f1 + f2;
				f1 = f2;
				f2 = f;
			}
			printf("%lld\n",f);
		}
	}
	return 0;
}
