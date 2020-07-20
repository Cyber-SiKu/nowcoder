/**
 * 不满足每首歌都要播放一次`
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    long N, M, P;
    long out;
    const long MOD = 1000000007l;

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
    vector<vector<long>> dp(P + 1, vector<long>(N + 1, 0)); // dp[i][j]:已播放i首歌，所有歌曲中已播放j首时的方案数(i>=j)
    dp[1][1] = N;
    for (size_t i = 2; i < P + 1; i++) {
        for (size_t j = 1; j < N + 1; j++) {
            if (j > i) {
                break;
            }

            if (j < M + 2 && i == j) {
                // 此时播放的i首歌不允许有重复所以只能是i == j才能形成播放列表
                dp[i][j] = (dp[i - 1][j - 1] * (N - i + 1) / i) % MOD;
                continue;
            }
            // j >= M+2, 此时有重复的歌曲数量为j-M-1 则此时歌曲数量最多可以达j + j-M-1
            // 歌曲的数量可以支撑播放列表
            dp[i][j] = (dp[i - 1][j - 1] * (N - j + 1) + dp[i - 1][j] * (j - M)) % MOD;
        }
    }
    out = dp[P][N];
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.N >> s.M >> s.P;
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
