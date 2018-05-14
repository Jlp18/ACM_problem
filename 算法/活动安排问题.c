#include <stdio.h>
void GreedySelector(int n , int s[] , int f[] , bool A[])//活动数量n , 数组s存放开始时间 ， 数组f存放结束时间 
{                                                        //数组A存放参加活动情况 ，true代表参加    
	A[1] = true;                                         //前提是对所有活动按照结束时间从小到大进行排序  
	int j = 1;
	for (int i = 2 ; i <= n ; i++)
	{
		if(s[i] >= f[j])
		{
			A[i] = true;
			j = i;
		}
		else
		{
			A[i] = false;
		}
	}
}
int main()
{
	int n = 11;
	int s[11] = {1,3,0,5,3,5,6,8,8,2,12};
	int f[11] = {4,5,6,7,8,9,10,11,12,13,14};
	bool result[11];
	GreedySelector(n , s , f , result);
	for(int i = 1 ; i <= 11 ; i++)
	{
		printf("%d ",result[i]);
	}
} 