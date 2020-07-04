/**
 * 运行时间：3ms
 * 占用内存：612k
*/

#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using vecii = vector<pair<int, int>>;

const int MAX = 10;

class Solution {
private:
    vector<int> outs;
    // int dp[MAX + 1][MAX + 1];

public:
    Solution(const vecii& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    int getNumer(int m, int n, int pre);
};

Solution::Solution(const vecii& data)
{

    // memset(dp, 0, sizeof(dp)); // 初始化
    for (const pair<int, int>& i : data) {
        this->outs.push_back(this->getNumer(i.first, i.second, i.first));
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        os << i << endl;
    }
    return os;
}

int Solution::getNumer(int m, int n, int pre)
{
    if (m == 1 || n == 1 || m == 0) {
        // this->dp[m][n] = 1;
        return 1;
    }

    int ret = 0;

    int f;
    if (m >= pre) {
        f = pre;
    } else {
        f = m;
    }

    while (f >= m - m * (n - 1) / n) {
        ret += this->getNumer(m - f, n - 1, f);
        f--;
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int x;
    cin >> x;
    vecii data(x, pair<int, int>(0, 0));

    for (size_t i = 0; i < x; i++) {
        cin >> data[i].first >> data[i].second;
    }

    Solution s(data);

    cout << s;
    return 0;
}