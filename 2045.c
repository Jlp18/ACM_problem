#include <stdio.h>
int main()
{
	int n;
	long long a[50];
	while(scanf("%d",&n)!=EOF)
	{
		a[0] = 0;
		a[1] = 3;
		a[2] = 6;
		a[3] = 6;
		for(int i = 4 ; i <= n ; i++)
		{
			a[i] = a[i-1] + 2*a[i-2];
		}
		printf("%lld\n",a[n]);
	} 
	return 0;
}
