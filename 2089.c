

//³¬Ê± 

#include<stdio.h>

int cal(int n,int m)
{
    int count=0;
	for(int i=m;i>=n;i--)
	{
		if(i % 10 == 4 || i / 10 % 10 == 4 || i / 100 % 10 == 4 || i / 1000 % 10 == 4 || i / 10000 % 10 == 4 || i / 100000 % 10 == 4 || i % 100 == 62 || i / 10 % 100 == 62 || i / 100 % 100 == 62 || i / 1000 % 100 == 62 || i / 10 % 10000 == 62)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int n,m;
	while( (scanf("%d %d",&n, &m)!=EOF) && ((m!=0)||(n!=0)) )
	{
		printf("%d\n",m-n+1-cal(n,m));
	} 
	return 0;
}

/*--------------¸Ä½ø°æ-----------------------------------------------------*/
#include <cstdio>
int m, n, arr[1000010];
int main()
{
    arr[1] = 1;
    for (int i = 2; i <= 1000000; i++)
        if (i % 10 == 4 || i / 10 % 10 == 4 || i / 100 % 10 == 4 || i / 1000 % 10 == 4 || i / 10000 % 10 == 4 || i / 100000 % 10 == 4 || i % 100 == 62 || i / 10 % 100 == 62 || i / 100 % 100 == 62 || i / 1000 % 100 == 62 || i / 10 % 10000 == 62)
            arr[i] = arr[i - 1];
        else
            arr[i] = arr[i - 1] + 1;
    while (~scanf("%d%d", &m, &n) && (m || n))
        printf("%d\n", arr[n] - arr[m - 1]);
    return 0;
}
