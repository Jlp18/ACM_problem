#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int x10 , x16 , x12;
		x10 = n%10+n/10%10+n/100%10+n/1000%10;
		x16 = n%16+n/16%16+n/256%16+n/4096%16;
		x12 = n%12+n/12%12+n/144%12+n/1728%12;
		if(x10 == x16 && x16 == x12)
		{
			printf("%d is a Sky Number.\n",n);
		}
		else
		{
			printf("%d is not a Sky Number.\n",n);
		}
	}
	return 0;
} 
