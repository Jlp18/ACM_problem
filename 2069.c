#include<stdio.h>

int coin[]={50,25,10,5,1};
int count; //ways of making change 
int coin_num;
int amount; //ÊäÈë½ğ¶î,<=250 
void change(int sum, int j, int coin_num)
{
	if(sum == amount && coin_num<=100)
	{
		count++;
	}
	else if(sum > amount || coin_num > 100)
	{
		return;
	}
	else
	{                 
		for(int i = j; i < 5 ; i++ )
		{
			coin_num +=1;
			j=i;                                        //µİ¹é 
			change(sum+coin[i] , j , coin_num );
			coin_num -=1;
		}
	}
}
int main()
{
	while(~scanf("%d",&amount))
	{
		count = 0;
		change(0,0,0);
		printf("%d\n",count);
	}
	return 0;
}
