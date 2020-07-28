#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string A;
    string B;
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
    out = 0;
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (size_t i = 1; i <= m; ++i) {
        dp[0][i] = i;
    }
    for (size_t i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            vector<int> tmp;
            tmp.push_back(dp[i][j - 1] + 1);
            tmp.push_back(dp[i - 1][j] + 1);
            if (A[i - 1] == B[j - 1]) {
                tmp.push_back(dp[i - 1][j - 1]);
            } else {
                tmp.push_back(dp[i - 1][j - 1] + 1);
            }
            dp[i][j] = *min_element(tmp.begin(), tmp.end());
        }
    }
    out = dp[n][m];
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.A >> s.B;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
