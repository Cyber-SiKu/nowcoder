#include <bits/stdc++.h>

using namespace std;

class Coins
{
    const vector<int> coins{1, 5, 10, 25};
    const int MOD = 1000000007;

public:
    int countWays(int n)
    {
        // write code here
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i : coins)
        {
            for (size_t j = i; j <= n; ++j)
            {
                dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }

        return dp[n];
    }
};

int main()
{
    int n = 0;
    cin >> n;
    cout << Coins().countWays(n) << endl;
    return 0;
}