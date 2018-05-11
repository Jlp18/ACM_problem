#include <stdio.h>
int main()
{
	int a , b;
	while(scanf("%d%d",&a , &b)!=EOF && (a != 0 || b != 0))  //aµÄb´Î·½ 
	{
		int sum = 1;
		while(b--)
		{
			sum *= a;
			sum %= 1000;
		} 
		printf("%d\n",sum);
	} 
	return 0;
}