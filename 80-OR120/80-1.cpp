/**
 * 不满足每首歌都要播放一次
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
    if (M > N) {
        out = 0;
        return;
    }

    long dp = N;
    for (size_t i = 1; i < P; i++) {
        if (i <= M) {
            dp = (dp * (N - i)) % MOD;
        } else {
            dp = (dp * (N - M)) % MOD;
        }
    }
    out = dp;
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
