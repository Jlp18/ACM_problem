#include <stdio.h>
int m[6][11]={0};  //ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ 
int c = 10; //��������
const int n = 5;  //��Ʒ����
int x[n+1];  //�����
int w[] = {0,2,2,6,5,4};   //��Ʒ�����������������1��ʼ
int v[] = {0,6,3,5,4,6};   //��Ʒ�ļ�ֵ����������Ӧ

void package0_1(int m[][11] , int w[] , int v[] , int n)
{
	//���ôӵ͵�����˳��������m[i][j]��ֵ
	//���ȷ�w[n]
	for(int j = 0 ; j <= c ; j++)
	{
		if(j < w[n])
		{
			m[n][j] = 0;   //jС��w[n] , �򲻿ɷ��� 
		}
		else
		{
			m[n][j] = v[n];
		}
	} 
	
	//���Ƕ�ʣ���n-1����Ʒ���з���
	 int i;
	 for(i = n-1 ; i >=1 ; i--)
	 {
 		for(int j = 0  ; j <= c ; j++)
 		{
		 	if(j < w[i])
		 	{
	 			m[i][j] = m[i+1][j];  //���j<w[n],�������Ʒ���ܷ��ã����λ�õ�ֵ���ڴ����һ����Ʒ��ֵ
				                      //���򣬱Ƚ��Ƿ���������Ʒ�ļ�ֵ�Ĵ�С��ȡMax						   
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
