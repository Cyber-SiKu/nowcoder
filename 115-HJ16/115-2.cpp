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
        vector<int> dp_N(max(N + 1, 6), 0);
        vector<int> dp_count;
        dp_count.push_back(0);
        dp_N[5] = 1;
        for (int i = 6; i <= N; i++) {
            if (i % 5 == 0) {
                ++count;
            }
            dp[i] = (dp[i - 1] + count) % MOD;
        }

        return dp[N];
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    cout << s.messageCount(4) << endl;
    cout << s.messageCount(10) << endl;
    cout << s.messageCount(11) << endl;
    cout << s.messageCount(15) << endl;
    cout << s.messageCount(20) << endl;

    return 0;
}
