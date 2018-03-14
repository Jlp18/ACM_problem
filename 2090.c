#include<stdio.h>
int main()
{
	char a[20];
	double b,c;
	double sum = 0;
	while(scanf("%s %lf %lf ",a,&b,&c)!=EOF)
	{
		sum+=b*c;
	}
	printf("%.1lf\n",sum);
	return 0;
}