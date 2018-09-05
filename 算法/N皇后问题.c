#include <stdio.h>
#include <stdlib.h>
int sum = 0;
void add(int max , int queen[])
{
    sum++;
}

//此函数用于判断皇后当前皇后是否可以放在此位置
int PLACE(int n , int queen[]) /* 检查当前列能否放置皇后 */
{
    //queen[i] == queen[n]用于保证元素不能再同一列
    //abs(queen[i] - queen[n]) == abs(n - i)用于约束元素不能再同一行且不能再同一条斜线上
    int i;
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == abs(n - i))
        {
            return 0;
        }
    }
    return 1;
}

//核心函数，回溯法的思想
void NQUEENS(int n , int max , int queen[]) /* 回溯尝试皇后位置,n为横坐标 */
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