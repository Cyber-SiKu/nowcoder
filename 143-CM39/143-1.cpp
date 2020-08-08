#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const int MOD = 1000000007;

public:
    int countWays(int n)
    {

        vector<int> dp { 0, 1, 2, 4, 7 };
        for (size_t i = 5; i <= n; i++) {
            dp.push_back((dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD);
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    cout << s.countWays(1) << endl;
    cout << s.countWays(3) << endl;
    cout << s.countWays(4) << endl;
    cout << s.countWays(5) << endl;

    return 0;
}
