#include<stdio.h>
int main()
{
	char a,c[40][80];
	int b,flag=0;
	while((scanf("%c %d",&a,&b)!=EOF)&&(a!='@'))
	{
		getchar();
		if(flag)   //除了第一个图形，其余前面空一行 
		{
			printf("\n");
		}
		for(int i=0;i<b-1;i++)
		{
			for(int j=0;j<b+i;j++)
			{
				c[i][j]=' ';
			}
		}
		for(int i=0;i<b-1;i++)
		{
			c[i][b-1+i]=a;
			c[i][b-1-i]=a;
		}
		for(int j=0;j<2*b-1;j++)
		{
			c[b-1][j]=a;
		}
		for(int p=0;p<b;p++)
		{
			for(int q=0;q<p+b;q++)
			{
				if(q==p+b-1)
				{
					printf("%c\n",c[p][q]);
				}
				else
				{
					printf("%c",c[p][q]);
				}
			}
		}
		flag=1;
	}
	return 0;
}




