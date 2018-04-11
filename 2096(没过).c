#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a , b , sum , x , y , sum2;
		scanf("%d%d",&a,&b);
		sum = a + b;
		x = sum % 10;
		y = sum/10 %10;
		sum2 = y*10+x;
		if(sum < 10)
		{
			printf("%d\n",x);
		}
		else
		{
			printf("%d\n",sum2);
		}
	}
	return 0;
}
