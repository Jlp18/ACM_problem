#include <stdio.h>
int main()
{
	int n;
	long long a;   //long long是64位整数，范围 -9223372036854775808~9223372036854775807
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lld",&a);
		printf("%d\n",(int)(a%100000)+600000);
	}
}
 
