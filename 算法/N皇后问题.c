#include <stdio.h>
#include <stdlib.h>
int sum = 0;
void add(int max , int queen[])
{
    sum++;
}

//�˺��������жϻʺ�ǰ�ʺ��Ƿ���Է��ڴ�λ��
int PLACE(int n , int queen[]) /* ��鵱ǰ���ܷ���ûʺ� */
{
    //queen[i] == queen[n]���ڱ�֤Ԫ�ز�����ͬһ��
    //abs(queen[i] - queen[n]) == abs(n - i)����Լ��Ԫ�ز�����ͬһ���Ҳ�����ͬһ��б����
    int i;
    for(i = 0; i < n; i++) /* �����źͶԽ������Ƿ���Է��ûʺ� */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == abs(n - i))
        {
            return 0;
        }
    }
    return 1;
}

//���ĺ��������ݷ���˼��
void NQUEENS(int n , int max , int queen[]) /* ���ݳ��Իʺ�λ��,nΪ������ */
{
    int i;
    for(i = 0; i < max; i++)
    {
        queen[n] = i;
        if(PLACE(n , queen))
        {
            if(n == max - 1)
            {
                add(max,queen);
            }
            else
            {
                NQUEENS(n + 1, max , queen);
            }
        }
    }
}
int main()
{
	int max;
	while(scanf("%d",&max)!=EOF)
	{
		sum = 0;
		int queen[max];
    	NQUEENS(0,max,queen);
    	printf("%d\n",sum);
	}
    return 0;
}