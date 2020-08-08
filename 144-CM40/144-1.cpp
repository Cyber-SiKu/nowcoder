#include <iostream>

using namespace std;

class Solution {
public:
    int countWays(int x, int y)
    {
        // write code here
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        for (size_t i = 1; i <= x; ++i) {
            for (size_t j = 1; j <= y; ++j) {
                if (i == 1 || j == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[x][y];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.countWays(2, 2);
    return 0;
}
