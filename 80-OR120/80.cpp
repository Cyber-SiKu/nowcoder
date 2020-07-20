#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int mod = 1000000007;
int n, m, p;
long long f[maxn][maxn];
int main()
{
    int m, n, p;
    cin >> n >> m >> p;
    f[0][0] = 1; //f[n][p] 表示用n首歌，填满p个位置的方法数量
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= p; j++) {
            //在p>n情况中，在第p位置填入一个在第p位置之前已经填写过的歌曲
            if (j > i && i > m)
                f[i][j] += (i - m) * f[i][j - 1];
            //在p==n的情况中，有n的阶乘种方法填满所有p个位置
            f[i][j] += f[i - 1][j - 1] * i; //diff
            if (f[i][j] >= mod)
                f[i][j] %= mod;
        }
    }
    cout << f[n][p];

    return 0;
}