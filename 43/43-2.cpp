/**
 * 算法思想：
 * 要想能够成功组班不同班的需求不能有三角形
 * 
 * 90.91%
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int out;

public:
    Solution(const vector<vector<int>>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<vector<int>>& data)
{
    out = 1;
    for (int i = 1, e_i = data.size(); i < e_i; ++i) {
        for (const int& j : data[i]) {
            for (const int& k : data[j]) {
                if (find(data[k].begin(), data[k].end(), i) != data[k].end()) {
                    out = 0;
                    return;
                }
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}

int main(int argc, char* argv[])
{
    int children = 0, requests = 0; // 小朋友人数, 请求数
    cin >> children >> requests;
    vector<vector<int>> data(children + 1);
    for (size_t i = 0; i < requests; i++) {
        int n, m;
        cin >> n >> m;
        data[n].push_back(m);
        data[m].push_back(n);
    }

    Solution s(data);

    cout << s << endl;
    return 0;
}