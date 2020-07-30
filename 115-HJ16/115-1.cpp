#include <algorithm>
#include <iostream>
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
        vector<vector<int>> dp(count + 1, vector<int>(N + 1, 0));
        for (size_t i = 1; i <= count; i++) {
            for (size_t j = 1; j <= N; i++) {
                if (i == 1 | j == 1) {
                    dp[i][j] = 1;
                } else {
                }
            }
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    cout << s.messageCount(10) << endl;
    cout << s.messageCount(11) << endl;

    return 0;
}
