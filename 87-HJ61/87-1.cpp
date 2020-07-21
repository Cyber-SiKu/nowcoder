#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n, m;
    int out;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    vector<vector<int>> dp;
    dp.resize(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 0; i < n + 1; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i][j - 1] + (i < j ? 0 : dp[i - j][j]);
        }
    }
    out = dp[m][n];
}

ostream& operator<<(ostream& os, const Solution& s)
{
    cout << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.m >> s.n;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s << endl;
    return 0;
}
