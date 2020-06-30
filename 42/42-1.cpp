#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
    int min;
    int max;

public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    int getMin(const vector<int>& data) const; // 最少存活人数
    int getMax(const vector<int>& data) const; // 最多存活人数
    int getAliveNumber(const vector<bool>& dp) const;
};

Solution::Solution(const vector<int>& data)
{
    this->min = this->getMin(data);
    this->max = this->getMax(data);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.min << endl
       << s.max << endl;
    return os;
}

int Solution::getMin(const vector<int>& data) const
{
    // 获取最小存活人数
    vector<bool> dp(data.size(), false); // 第 i 个人是否被杀死
    for (size_t i = 0, e_i = data.size(); i < e_i; i++) {
        /* 假设第i个人可以开枪把瞄准的人杀死 */
        if (dp[i] == false) {
            int j = data[i];
            if (j == i) {
                /* 自杀 */
                dp[j] = true;
                continue;
            }

            while (j != i && dp[j] == false) {
                // 尚未进入循环，或者第j个人仍未被杀死
                dp[j] = true;
                j = data[j];
            }
        }
    }

    return this->getAliveNumber(dp);
}

int Solution::getAliveNumber(const vector<bool>& dp) const
{
    int ret = 0;
    for (const bool& i : dp) {
        if (i == false) {
            ret++;
        }
    }
    return ret;
}

int Solution::getMax(const vector<int>& data) const
{
    vector<set<int>> dp(data.size()); // dp[i] 要杀死哪些人

    for (int i = 0, e_i = data.size(); i < e_i; ++i) {

        int j = data[i], j_old = i;
        vector<bool> alive(data.size(), true); // 第i个人是否存活
        while (j != j_old && alive[j] != false) {
            // 存活最多则一个人存活他指向的人必须死亡
            alive[j] = !alive[j_old]; // i存活则其指向的人必须死亡
            if (alive[j] == false) {
                /* 指向j的人存活,j死亡 */
                dp[i].insert(j);
                if (dp[j].size() != 0) {
                    dp[i].insert(dp[j].begin(), dp[j].end());
                    break;
                }
            }
            j_old = j;
        }
    }

    vector<bool> alive(data.size(), true); // 第i个人是否存活
    for (int i = 0, e_i = data.size(); i < e_i; ++i) {
        if (alive[i] == false) {
            continue;
        }
        set<int> a; // 可能存活的点
        for (const int& j : dp[i]) {
            a.insert(dp[j].begin(), dp[j].end());
        }
        if (dp[i].size() < a.size()) {
            for (const int& j : a) {
                alive[j] = false;
            }
        }
    }
    return this->getAliveNumber(alive);
}

int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    // data[i].first:是否有人指向 data[i].second:指向谁
    vector<int> data(N, 0);
    for (size_t i = 0; i < N; i++) {
        cin >> data[i];
        data[i]--;
    }

    Solution s(data);

    cout << s;
    return 0;
}