#include <stdio.h>
int m[6][11]={0};  //前i个物品装入容量为j的背包中获得的最大价值 
int c = 10; //背包容量
const int n = 5;  //物品种类
int x[n+1];  //求解结果
int w[] = {0,2,2,6,5,4};   //物品的重量，从索引序号1开始
int v[] = {0,6,3,5,4,6};   //物品的价值，与重量对应

void package0_1(int m[][11] , int w[] , int v[] , int n)
{
	//采用从低到顶的顺序来设置m[i][j]的值
	//首先放w[n]
	for(int j = 0 ; j <= c ; j++)
	{
		if(j < w[n])
		{
			m[n][j] = 0;   //j小于w[n] , 则不可放置 
		}
		else
		{
			m[n][j] = v[n];
		}
	} 
	
	//考虑对剩余的n-1个物品进行放置
	 int i;
	 for(i = n-1 ; i >=1 ; i--)
	 {
 		for(int j = 0  ; j <= c ; j++)
 		{
		 	if(j < w[i])
		 	{
	 			m[i][j] = m[i+1][j];  //如果j<w[n],则这个物品不能放置，这个位置的值等于存放上一个物品的值
				                      //否则，比较是否放置这个物品的价值的大小，取Max						   
	 		}
	 		else
	 		{
		 		m[i][j] = m[i+1][j] > m[i+1][j-w[i]]+v[i]?m[i+1][j]:m[i+1][j-w[i]]+v[i];
		 	}
		 }
 	}
}

void getSolution(int m[][11] , int n)
{
	int j = c;
	int i;
	for(i = 1 ; i <= n-1 ; i++)
	{
		if(m[i][j] == m[i+1][j])
		{
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			j = j - w[i];
		}
	}
	x[n] = m[i][j]?1:0;
} 


int main()
{
	package0_1(m,w,v,n);
	printf("The Max Value is:\n%d",m[1][c]);
	/*for(int i = 1 ; i <= 5 ; i++)
	{
		for(int j = 0 ; j <= 10 ; j++)
		{
			printf("%2d ",m[i][j]); 
		}
		printf("\n");
	}*/
	getSolution(m,n);
	printf("\n\nThe best solution is:\n");
	for(int i = 1 ; i <= 5 ; i++)
	{
		printf("%d ",x[i]);
	} 
	printf("\n");
	return 0;
}
