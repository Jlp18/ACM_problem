#include <stdio.h>
#include <math.h>
// ��ʱ��ܹؼ� 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		int x1 , y1 , x2 , y2 , x3 , y3;
		double sum , a , b , c , p;   //a��b��cΪ���������߳���pΪ���ܳ� 
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		sum = 0.0; 
		for(int i = 0 ; i < n-2 ; i++)
		{
			scanf("%d%d",&x3,&y3);
			a = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
			b = sqrt(pow((x3-x2),2)+pow((y3-y2),2));
			c = sqrt(pow((x3-x1),2)+pow((y3-y1),2));
			p = (a+b+c)/2.0;
			sum += sqrt(p*(p-a)*(p-b)*(p-c));  //���׹�ʽ 
			x2 = x3;   //��ʱ�� 
			y2 = y3;
		} 
		printf("%.1lf\n",sum);
	}
	return 0;
} 
