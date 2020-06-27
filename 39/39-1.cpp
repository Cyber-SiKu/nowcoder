/**
 * 运行时间：5ms
 * 占用内存：484k
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using array = vector<vector<int>>; // [体积]，first:数量， second：价值

class Solution {
private:
    int max_value;

public:
    Solution(array data, int v);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(array data, int v)
{
    vector<int> dp(v + 1, 0);
    for (size_t i = 0, e_i = data.size(); i < e_i; i++) {
        for (size_t j = 0; j < data[i][0]; j++) {
            for (size_t k = v; k >= data[i][1]; k--) {
                dp[k] = max(dp[k], dp[k - data[i][1]] + data[i][2]);
            }
        }
    }
    this->max_value = dp[v];
}
Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.max_value;
    return os;
}

int main(int argc, char* argv[])
{
    int n, v;
    cin >> n >> v;
    array data(n, vector<int>(3, 0));
    for (size_t i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    Solution s(data, v);

    cout << s << endl;
    return 0;
}