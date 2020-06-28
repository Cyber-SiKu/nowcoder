/**
 * 算法思想：
 *  首先将数据按照左值进行排序
 *  然后一次访问观察每个区间和右边第一个是否可以合并
 * 
 * 运行时间：3ms
 * 占用内存：408k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class range {
public:
    int left;
    int right;
    range(int left, int right)
        : left(left)
        , right(right)
    {
    }
    friend bool operator<(const range& a, const range& b);
};

bool operator<(const range& a, const range& b)
{
    return a.left < b.left;
}

class Solution {
private:
    vector<range>& outs;

public:
    Solution(vector<range>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(vector<range>& data)
    : outs(data)
{
    sort(data.begin(), data.end());
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = i + 1; j < data.size(); j++) {
            if (data[i].right < data[j].left) {
                break;
            } else {
                // data[i].right >= data[j].left
                data[i].right = max(data[i].right, data[j].right);
                data.erase(data.begin() + j);
                i--;
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const range& i : s.outs) {
        os << i.left << "," << i.right << " ";
    }
    return os;
}

int main(int argc, char* argv[])
{
    int x, y;
    char tmp;
    vector<range> data;
    while (cin >> x >> tmp >> y) {
        data.push_back(range(x, y));
    }

    Solution s(data);

    cout << s << endl;
    return 0;
}