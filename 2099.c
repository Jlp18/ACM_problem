#include<stdio.h>
int main()
{
	int a , b;
	while(scanf("%d%d",&a,&b)!=EOF &&(a!=0||b!=0))
	{
		int flag = 0;
		for(int i =0; i<100 ; i++)
		{
			if((a*100+i)%b==0)
			{
				if(flag)
				{
					printf(" ");
				}
				if(i<10)
				{
					printf("0%d",i);
				}
				else
				{
					printf("%d",i);
				}
				flag = 1;
			}
		}
		printf("\n");
	}
	return 0;
}
