#include <stdio.h>
int main()
{
	int m , n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		for(int i = 0 ; i < n+2 ; i++)
		{
			if(i == 0 || i == n+1)
			{
				printf("+");
				for(int j = 0 ; j < m ; j++)
				{
					printf("-");
				}
				printf("+\n");
			}
			else
			{
				printf("|");
				for(int j = 0 ; j < m ; j++)
				{
					printf(" ");
				}
				printf("|\n");
			}
		}
		printf("\n");
	}
	return 0;
}
