#include<stdio.h>
#include<string.h>
char s[1000],a[1000][1000];
int main()
{
	int i,k,j;
	while(gets(s))
	{
		if(strcmp(s,"#")==0)  //�������� 
			break;
		char *p;
		p=strtok(s," "); //���ո�ָ� 
		for(i=0;p!=NULL;i++)
		{
			strcpy(a[i],p); //�浽��ά������ 
			p=strtok(NULL," ");
		}
		int n=0;
		for(k=0;k<i;k++)
		{
			for(j=k+1;j<i;j++)
			{
				if(strcmp(a[k],a[j])==0) //���� 
				{
					n++;
					break;
				}
			}
		}
		printf("%d\n",i-n);
	}
}