class Robot {
private:
    const int MOD = 1000000007;

public:
    int countWays(vector<vector<int>> map, int x, int y)
    {
        // write code here
        vector<vector<int>> dp(x, vector<int>(y, 0));
        for (size_t i = 0; i < y; ++i) {
            if (map[0][i] != 1) {
                break;
            }
            dp[0][i] = 1;
        }
        for (size_t i = 0; i < x; ++i) {
            if (map[i][0] != 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for (size_t i = 1; i < x; ++i) {
            for (size_t j = 1; j < y; ++j) {
                if (map[i][j] != 1) {
                    continue;
                }
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        return dp[x - 1][y - 1];
    }
};