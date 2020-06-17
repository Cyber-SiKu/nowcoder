/**
 * 算法思想：
 * 秋街到某个边时，上一个边已经求解完成部分仅考虑新于加入的点i冲突的点即可
 *  i边比i-1边相比：
 *      匹配的重新考虑
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
    int pre = length - 1 - conflict[0].size();
    this->edges[0] = pre;
    for (size_t i = 1, e = this->edges.size(); i < e; ++i) {
        // i 左边原来能与i配对的现在不能配对
        pre -= i;
        // i 右边原来不能与i配对的现在可以配对
        pre += (length - i - 1);
        for (const int& j : conflict[i]) {
            if (j < i) {
                // 左边与 i 冲突的多减一次
                pre++;
            } else if (j > i) {
                // 右边与 i 冲突多加一次
                pre--;
            }
        }
        this->edges[i] = pre;
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