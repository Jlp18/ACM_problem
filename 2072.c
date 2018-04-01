#include<stdio.h>
#include<string.h>
char s[1000],a[1000][1000];
int main()
{
	int i,k,j;
	while(gets(s))
	{
		if(strcmp(s,"#")==0)  //结束条件 
			break;
		char *p;
		p=strtok(s," "); //按空格分割 
		for(i=0;p!=NULL;i++)
		{
			strcpy(a[i],p); //存到二维数组中 
			p=strtok(NULL," ");
		}
		int n=0;
		for(k=0;k<i;k++)
		{
			for(j=k+1;j<i;j++)
			{
				if(strcmp(a[k],a[j])==0) //查重 
				{
					n++;
					break;
				}
			}
		}
		printf("%d\n",i-n);
	}
}