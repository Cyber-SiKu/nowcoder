/**
 * 时间复杂度过大
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    /* data */
    long max_income; // 最大收益
    long min_transations; // 最小交易次数
public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<int>& data)
{

    long dp[2][2] = { 0 };
    int length = data.size();
    for (int i = length - 1; i >= 0; i--) {
        for (int j = 1; j >= 0; j--) {
            // cout << i << endl;
            long sum = dp[1 - j][0] + (j ? data[i] : -data[i]);
            long cnt = dp[1 - j][1] + 1;
            if (sum > dp[j][0] || (sum == dp[j][0] && cnt < dp[j][1])) {
                dp[j][0] = sum;
                dp[j][1] = cnt;
            }
        }
    }

    this->max_income = dp[0][0];
    this->min_transations = dp[0][1];
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.max_income << " " << s.min_transations;
    return os;
}

int main(int argc, char* argv[])
{
    vector<int> data;
    int n;
    cin >> n;
    data.resize(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> data[i];
    }

    Solution s(data);

    cout << s << endl;
    return 0;
}