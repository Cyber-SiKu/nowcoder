#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
    const int MOD = 998244353;

public:
    /**
     * 返回可以被压缩为长度为 N 的不同消息的数量
     * @param N int整型 数据包的总字节数
     * @return int整型
     */
    int messageCount(int N)
    {
        // write code here
        int count = N / 5;
        vector<vector<int>> dp(N + 1, vector<int>(count + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= count; j++) {
                if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int start = max(4, i - (j - 1) * 5);
                    for (int k = start; k >= 5; k--) {
                        dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % MOD;
                    }
                }
            }
        }
        int out = 0;
        for (size_t i = 1; i <= count; i++) {
            out = (out + dp[N][i]) % MOD;
        }
        return out;
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    // cout << s.messageCount(10) << endl;
    cout << s.messageCount(11) << endl;
    cout << s.messageCount(15) << endl;

    return 0;
}
