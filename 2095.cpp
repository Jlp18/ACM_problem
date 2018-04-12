#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

long long int a[1000010]; 

int main()
{
	int n;
	while (scanf("%d",&n) && n)
	{
		for (int i = 0; i<n; i++)
			scanf("%lld",&a[i]);
		sort(a, a+n);
		int i;
		for (i = 1; i<n; i++)
		{
			if (a[i] != a[i-1]  &&  a[i] != a[i+1])
				break;
		}
		printf("%lld\n",a[i]);
	}
	return 0;
}