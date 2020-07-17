/**
 * 运行时间：2ms
 * 占用内存：376k
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> data;
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
    vector<int> dp(this->data.size(), 0); // dp[i]:到第i个数最长子序列的长度
    dp[0] = 1;
    int max_pos = 0;
    for (size_t i = 1; i < this->data.size(); ++i) {
        // 寻找第一个比当前小子序列最长的数
        int max = 0;
        if (this->data[max_pos] >= this->data[i]) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] > max && this->data[j] < this->data[i]) {
                    max = dp[j];
                }
            }
        } else {
            max = dp[max_pos];
        }

        dp[i] = max + 1;
        if (dp[i] > dp[max_pos]) {
            max_pos = i;
        }
    }
    out = dp[max_pos];
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int x;
    while (cin >> x) {
        s.data.push_back(x);
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
