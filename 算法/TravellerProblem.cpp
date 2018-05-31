/*
//伪代码
void travel(int t) {

    if(t到达第n层即搜索到叶子结点) {

        if(城市x[t-1]可以到达城市x[t]，并且城市x[t]可以回到城市1，且此时所走的路程cc加上

            x[t-1]与x[t]的距离和x[t]与1的距离小于当前最优值bestc) {

                将最优解记录下来;

                将最优值记录下来;

            }

        return;

    }

    for(int i = t; i < n; i++) {

        if(城市x[t-1]能达到城市x[i]即这两个城市间有边，并当前所走的路程cc加上这两个城市的距离

        没有比当前最优值bestc大) {

        swap(x[i], x[t]);

        修改此时所走的路程cc;

        进入下一层递归;

        恢复原来cc的值;

        swap(x[i], x[t]);

        }

    }

} 



*/

#include<iostream>  
using namespace std;  
  
const int INF = 10000000;  
int n, cc = 0, bestc = INF;  
int **g;  
int *x, *bestx;  
  
void travel(int t) {  
    if (t == n) {  
        if (g[x[t - 1]][x[t]] != INF && g[x[t]][1] != INF &&  
            (cc + g[x[t - 1]][x[t]] + g[x[t]][1] < bestc || bestc == INF)) {  
            for (int i = 0; i < n + 1; i++)  
                bestx[i] = x[i];  
            bestc = cc + g[x[t - 1]][x[t]] + g[x[t]][1];  
        }  
        return;  
    }  
  
    for (int i = t; i < n; i++) {  
        if (g[x[t - 1]][x[i]] != INF && (cc + g[x[t - 1]][x[i]] < bestc  
            || bestc == INF)) {  
            swap(x[i], x[t]);  
            cc += g[x[t - 1]][x[t]];  
            travel(t + 1);  
            cc -= g[x[t - 1]][x[t]];  
            swap(x[i], x[t]);  
        }  
    }  
}  
  
void output() {  
    cout << bestc << endl;  
    cout << bestx[1];  
    for (int i = 2; i < n + 1; i++)  
        cout << " " << bestx[i];  
    cout << " " << bestx[1] << endl;  
}  
  
int main() {  
  
    n = 4;  
    g = new int*[n + 1];  
    x = new int[n + 1];  
    bestx = new int[n + 1];  
  
    for (int i = 0; i < n + 1; i++) {  
        g[i] = new int[n + 1];  
        x[i] = i;  
  
        for (int j = 0; j < n + 1; j++)  
            g[i][j] = INF;  
    }  
  
    g[1][2] = g[2][1] = 30;  
    g[1][3] = g[3][1] = 6;  
    g[1][4] = g[4][1] = 4;  
  
    g[2][3] = g[3][2] = 5;  
    g[2][4] = g[4][2] = 10;  
  
    g[3][4] = g[4][3] = 20;  
  
    travel(2);  
    output();  
  
    return 0;  
}  