/**
 * 运行时间：8ms
 * 占用内存：632k
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int M, N;
    vector<vector<int>> map;
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
    vector<vector<int>> dp(this->M, vector<int>(this->N, 0)); // 保存到 (i,j) 上一不所需的最少动力
    for (int i = this->M - 1; i >= 0; --i) {
        for (int j = this->N - 1; j >= 0; --j) {
            if (i == this->M - 1 && j == this->N - 1) {
                dp[i][j] = max(1, 0 - this->map[i][j]);
                continue;
            }
            if (i == this->M - 1 && j != this->N - 1) {
                dp[i][j] = max(1, dp[i][j + 1] - this->map[i][j]);
                continue;
            }
            if (j == this->N - 1 && i != this->M - 1) {
                dp[i][j] = max(1, dp[i + 1][j] - this->map[i][j]);
                continue;
            }
            dp[i][j] = min(max(1, dp[i][j + 1] - this->map[i][j]), max(1, dp[i + 1][j] - this->map[i][j]));
        }
    }

    this->out = dp[0][0];
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.M >> s.N;
    s.map.resize(s.M, vector<int>(s.N));
    for (size_t i = 0; i < s.M; i++) {
        for (size_t j = 0; j < s.N; j++) {
            is >> s.map[i][j];
        }
    }

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
