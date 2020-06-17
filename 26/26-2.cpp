/**
 * 算法思想：暴力求解
 * 
 * 46.67%
 * 超时
*/

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

using viri = vector<int>::reverse_iterator;

class Solution {
private:
    /* data */
    vector<long> edges;

public:
    Solution(const vector<int>& a);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    // 获取每个节点相同权重的向量
    vector<vector<int>> getConflict(const vector<int>& a);
};

Solution::Solution(const vector<int>& a)
    : edges(a.size() - 1, 0)
{
    int length = a.size();
    vector<vector<int>> conflict = this->getConflict(a);
    for (size_t i = 0, e = edges.size(); i < e; i++) {
        long count = (length - i - 1) * (i + 1);
        for (size_t j = 0; j < i + 1; j++) {
            long count_over = 0;
            for (viri z = conflict[j].rbegin(), e = conflict[j].rend(); z != e; z++) {
                if (*z <= i) {
                    break;
                }
                count_over++;
            }
            count -= count_over;
        }
        edges[i] = count;
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.edges) {
        os << i << " ";
    }
    return os;
}

vector<vector<int>> Solution::getConflict(const vector<int>& a)
{
    vector<vector<int>> ret(a.size(), vector<int>());

    for (size_t i = 0, e = a.size(); i < e; ++i) {
        for (size_t j = i + 1; j < e; j++) {
            if (a[i] == a[j]) {
                ret[i].push_back(j);
                ret[j].push_back(i);
            }
        }
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution s(a);

    cout << s << endl;
    return 0;
}