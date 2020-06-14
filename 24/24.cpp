#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long dp[2][2];
    memset(dp, 0, sizeof dp);
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j >= 0; j--) {
            long sum = dp[1 - j][0] + (j ? a[i] : -a[i]);
            long cnt = dp[1 - j][1] + 1;
            // dp[j][0] = dp[j][0];
            // dp[j][1] = dp[j][1];
            if (sum > dp[j][0] || (sum == dp[j][0] && cnt < dp[j][1])) {
                dp[j][0] = sum;
                dp[j][1] = cnt;
            }
        }
    printf("%ld %ld\n", dp[0][0], dp[0][1]);
    return 0;
}