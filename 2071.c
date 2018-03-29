#include <stdio.h>
double find_max(double s[] , int n)
{
	double max ;
	max = s[0];
	for(int i = 1; i < n; i++)
	{
		if(s[i] > max)
		{
			max = s[i];
		}
	}
	return max;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
            int m;
            scanf("%d",&m);
		    double c[m];
		    for (int j = 0; j < m ;j++)
		    {
		        scanf("%lf",&c[j]);
		    }
		    printf("%.2lf\n",find_max(c , m));
		}	
	}
	return 0;
}
