/**
 * 算法思想：
 * 秋街到某个边时，上一个边已经求解完成部分
 * 仅考虑i 点左右两部分即可
 * 
 * 优化 getConflict 使得返回返回俄数组A满足 A[i][0]是与i冲突小于i的，A[i][1]是与i冲突大于i的
 *      使用点的权值而不是节点保存左右的冲突数
 * 
 * 
 * 运行时间：94ms
 * 占用内存：11268k
*/

#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

using viri = vector<int>::reverse_iterator;

class Solution {
private:
    /* data */
    vector<int> data;
    vector<long> edges;
    unordered_map<int, int> left, right;

public:
    Solution(const vector<int>& a);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    // 获取每个节点相同权重的向量
    void getConflict();
};

Solution::Solution(const vector<int>& a)
    : data(a)
{
    int length = data.size();
    this->getConflict();
    long long pre = 0;
    for (size_t i = 0; i < length - 1; i++) {
        pre += (length - 2 * i - right[data[i]] + left[data[i]]);
        edges.push_back(pre);
        right[data[i]]--;
        left[data[i]]++;
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (int i = 0, e = s.edges.size(); i < e; i++) {
        os << s.edges[i];
        os << (i == e - 1 ? "\n" : " ");
    }
    return os;
}

void Solution::getConflict()
{
    for (int i = data.size() - 1; i >= 0; --i) {
        this->right[this->data[i]]++;
    }
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

    cout << s;
    return 0;
}