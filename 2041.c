#include <stdio.h>
int main()
{
	int m , n;
	int a[40];
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for(int i = 3 ; i <= 40 ; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		if(m == 1)
		{
			printf("%d\n",a[0]);
		}
		else
		{
			printf("%d\n",a[m]);
		}	
	}
	return 0;
}
