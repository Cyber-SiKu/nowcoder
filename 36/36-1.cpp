/**
 * 内存超限
 * 20.0%
*/
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const unsigned MAX = 2147483647;

class Solution {
private:
    int outs;

public:
    Solution(unsigned n);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(unsigned n)
    : outs(0)
{
    // dp[0][i] 整数 i 有多少个 1
    // dp[1][i] 1-i 有多少 1
    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));
    for (unsigned i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i / 10] + (i % 10 == 1 ? 1 : 0);
        dp[1][i] = dp[1][i - 1] + dp[0][i];
    }
    outs = dp[1][n];
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
    unsigned n;
    cin >> n;
    Solution s(n);

    cout << s << endl;
    return 0;
}