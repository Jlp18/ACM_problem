#include <stdio.h>
int main()
{
	int N,n;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		int sum = 3;
		for(int i = 0 ; i < n ; i++)
		{
			sum = (sum-1)*2;
		} 
		printf("%d\n",sum);
	}
	return 0;
}
