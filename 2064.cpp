#include<iostream>
#include<cmath>
using namespace std;
__int64 hanoi(int n)
{
	if(n == 1)
	return 2;
	else
	return hanoi(n - 1) * 3 + 2;
}
int main()
{
	__int64 n;
	while(cin >> n)
	{
		cout << hanoi(n) << endl;
	}
}
/*#include <stdio.h>
int count = 0;
void move (int a , int b)
{
	count++;
}
void hanoi(int n , int a , int b , int c) //从a移动到b上，借助于c 
{
	if(n > 0)
	{
		hanoi(n-1 , a , c , b); //n-1个从a到c，借助于b 
		move(a , b); //把“最大的”从a移动到b 
		hanoi(n-1 , c , b , a);
	}
}
int main()+
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		hanoi(n , 1 , 2 ,3);
		printf("%d\n",count);
	}
	return 0;
}*/
