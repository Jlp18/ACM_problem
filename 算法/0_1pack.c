#include <stdio.h>
void Traceback(int n ,int w[] ,int v[], int **p, int *head, int x[])
{
	int j = p[head[0] - 1][0];
	int m = p[head[0] - 1][1];
	for(int i = 1 ; i <= n ; i++)
	{
		x[i] = 0;
		for(int k = head[i+1] ; k <= head[i] - 1 ; k++)
		{
			if(p[k][0] + w[i] == j && p[k][1] + v[i] == m)
			{
				x[i] = 1;
				j = p[k][0];
				m = p[k][1];
				break;
			}
		}
	}
}


int Knapack(int n ,int c ,int v[] ,int w[] ,int **p ,int x[])
{
	int *head = new int[n+2];
	head[n+1] = 0;
	p[0][0] = 0;
	p[0][1] = 0;
	int left = 0 , right = 0 , next = 1;
	head[n] = 1;
	for(int i = n ; i >= 1 ; i--)
	{
		int k = left;
		for(int j = left ; j <= right ; j++)
		{
			if(p[j][0]+w[i]>c)
			{
				break;
			}
			int y = p[j][0] + w[i];
			int m = p[j][1] + v[i];
			while(k <= right && p[k][0] < y)
			{
				p[next][0] = p[k][0];
				p[next++][1] = p[k++][1];
			}
			if(k <= right && p[k][0] == y)
			{
				if(m < p[k][1])
				{
					m = p[k][1];
				}
				k++;
			}
			if(m > p[next-1][1])
			{
				p[next][0] = y;
				p[next++][1] = m;
			}
			while(k <= right && p[k][1] <= p[next-1][1])
			{
				k++;
			}
		}
		while(k <= right)
		{
			p[next][0] = p[k][0];
			p[next++][1] = p[k++][1];
		}
		left = right + 1;
		right = next - 1;
		head[i-1] = next;
	}
	Traceback(n, w, v, p, head, x);
	return p[next-1][1];
}



int main()
{
	int n = 5;
	int c = 10;
	int w[] = {2,2,6,5,4};
	int v[] = {6,3,5,4,6};
	int m[6][11]={0};
	int x[6];
	//int **p;
	//p = (int**)m; 
	printf("%d\n",Knapack(n,c,v,w,(int **)m,x));
	return 0;
}
