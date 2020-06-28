/**
 * 运行时间：5ms
 * 占用内存：492k
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int outs;

public:
    Solution(int n, int m);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(int n, int m)
{
    vector<int> dp(m + 1, 0); // dp[i] 求和等于i时组合数
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (dp[j] != 0 && i + j <= m) {
                // dp[j] 可以组合成功
                dp[i + j] += dp[j];
            }
        }
        dp[i] += 1;
    }
    this->outs = dp[m];
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;
    Solution s(n, m);

    cout << s << endl;
    return 0;
}