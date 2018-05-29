#include <stdio.h>
int main()
{
	int n,a,b;
	long long c[50];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		c[1]=0;
	    c[2]=1;
	    c[3]=2;
	    for(int i =4 ; i <= b-a+1 ; i++)
	    {
    		c[i] = c[i-1] + c[i-2];
    	}
    	printf("%lld\n",c[b-a+1]);
	}
	return  0;
}
