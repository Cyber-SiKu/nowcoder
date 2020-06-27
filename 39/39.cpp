#include <cstdio>
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n, v;
    int i, j, k;
    int m[2005], w[2005], s[2005];
    int dp[505];
    // memset(dp,0,sizeof(dp));
    scanf("%d %d", &n, &v);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &m[i], &w[i], &s[i]);
        for (j = 0; j < m[i]; j++) {
            for (k = v; k >= w[i]; k--) {
                dp[k] = max(dp[k], dp[k - w[i]] + s[i]);
            }
        }
    }
    printf("%d", dp[v]);
    return 0;
}