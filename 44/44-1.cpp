/**
 * 取巧算法，不和提议
 * 运行时间：4ms
 * 占用内存：388k
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> outs;

public:
    Solution(const vector<int>& data, const int& k);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<int>& data, const int& k)
    : outs(data)
{
    if (k <= data.size()) {
        vector<int>::iterator start = outs.begin();
        for (int i = 0, e_i = data.size(); i + k <= e_i; i += k) {
            reverse(start + i, start + i + k);
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        os << i << " ";
    }

    return os;
}

int main(int argc, char* argv[])
{
    int k;
    vector<int> data;
    while (cin >> k) {
        data.push_back(k);
    }
    data.pop_back();

    Solution s(data, k);

    cout << s << endl;
    return 0;
}