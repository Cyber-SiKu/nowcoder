#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 101;
struct P {
    int id, t;
};
vector<P> G[N];
vector<int> M(N), v1(N), v2(N);
int n, m, k;
double F(vector<int> v)
{
    double dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            double s = 0;
            int cnt = 0;
            if (j >= M[i])
                dp[i][j] += v[i];
            for (int u = 0; u < G[i].size(); u++) {
                if (j >= G[i][u].t + M[i] + M[G[i][u].id]) {
                    s += dp[G[i][u].id][j - G[i][u].t - M[i]];
                    cnt++;
                }
            }
            if (s)
                dp[i][j] += s / cnt;
        }
    }
    double r = 0;
    for (int i = 1; i <= n; i++) {
        r += dp[i][k];
    }
    return r / n;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> M[i] >> v1[i] >> v2[i];
    }
    int x, y, t;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t;
        G[x].push_back({ y, t });
        G[y].push_back({ x, t });
    }
    printf("%.5f %.5f\n", F(v1), F(v2));
    return 0;
}