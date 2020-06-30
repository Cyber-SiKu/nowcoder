/**
 * 算法思想：
 * 要想能够成功组班不同班的需求不能形成奇数个节点的环
 * 
 * 运行时间：6ms
 * 占用内存：476k
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int out;
    vector<vector<int>> data;

public:
    Solution(const vector<vector<int>>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // start->end 在已访问 visited 情况下,可能的步长
    vector<int> numberCircle(const int& start, const int& end, vector<bool> visited);
};

Solution::Solution(const vector<vector<int>>& data)
    : data(data)
{
    out = 1;
    vector<bool> visited(data.size(), false);
    for (size_t i = 1, e_i = data.size(); i < e_i; i++) {
        vector<int> tmp = this->numberCircle(i, i, visited);
        for (const int& j : tmp) {
            if (j % 2 == 1) {
                this->out = 0;
                return;
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

vector<int> Solution::numberCircle(const int& start, const int& end, vector<bool> visited)
{
    vector<int> ret;
    for (const int& i : data[start]) {
        if (visited[i] == true) {
            /* i 已访问 */
            continue;
        }

        if (i == end) {
            // 找到一种路径
            ret.push_back(1);
            continue;
        }
        vector<bool> visited_(visited);
        visited_[i] = true;
        vector<int> tmp = this->numberCircle(i, end, visited_);
        if (tmp.size() != 0) {
            for (const int& i : tmp) {
                ret.push_back(i + 1);
            }
        }
    }
    return ret;
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