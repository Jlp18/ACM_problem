#include <stdio.h>
void GreedySelector(int n , int s[] , int f[] , bool A[])//�����n , ����s��ſ�ʼʱ�� �� ����f��Ž���ʱ�� 
{                                                        //����A��Ųμӻ��� ��true����μ�    
	A[1] = true;                                         //ǰ���Ƕ����л���ս���ʱ���С�����������  
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