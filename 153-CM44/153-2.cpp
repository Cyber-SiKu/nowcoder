#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare1(const int& a, const int& b)
{
    return a > b;
}

bool compare2(const vector<int>& a, vector<int>& b)
{
    bool ret = true;
    if (a.size() > b.size()) {
    } else if (a.size() < b.size()) {
        ret = false;
    } else {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < b[i]) {
                ret = false;
            }
        }
    }
    return ret;
}

class Subset {
public:
    vector<vector<int>> getSubsets(vector<int> A, int n)
    {
        // write code here
        vector<vector<int>> dp[2]; // dp[0]含当前结点，dp[1]不含
        dp[0].push_back(vector<int>(1, A[0]));
        for (int i = 1; i < n; ++i) {
            vector<vector<int>> tmp[2] { dp[0], dp[1] };
            dp[1].insert(dp[1].end(), tmp[0].begin(), tmp[0].end());
            dp[i].push_back(vector<int>());
            for (vector<int>& j : dp[1]) {
                j.insert(j.end(), A[i]);
            }
            dp[0].insert(dp[0].end(), dp[1].begin(), dp[1].end());
        }
        // dp[1].insert(dp[1].end(), dp[0].begin(), dp[0].end());
        for (vector<int>& i : dp[1]) {
            sort(i.begin(), i.end(), compare1);
        }
        sort(dp[1].begin(), dp[1].end(), compare2);
        unique(dp[1].begin(), dp[1].end());
        return dp[1];
    }
};

int main()
{
    Subset s;
    vector<int> data { 123, 456, 789 };
    vector<vector<int>> output = s.getSubsets(data, data.size());
    for (vector<int>& i : output) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}