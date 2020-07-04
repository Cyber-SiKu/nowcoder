/**
 * 运行时间：2624ms
 * 占用内存：52396k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string outs;

public:
    Solution(const vector<vector<int>>& data, const int& k);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<vector<int>>& data, const int& k)
{
    outs = "false";
    for (const vector<int>& i : data) {
        vector<int>::const_iterator begin = i.cbegin();
        if (*begin > k) {
            break;
        }
        vector<int>::const_reverse_iterator rbegin = i.crbegin();
        if (*rbegin < k) {
            continue;
        }
        if (find(i.cbegin(), i.cend(), k) != i.cend()) {
            outs = "true";
            break;
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int main(int argc, char* argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>>* data = new vector<vector<int>>(m, vector<int>(n, 0));
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            int x;
            cin >> x;
            (*data)[i][j] = x;
        }
    }
    int k;
    cin >> k;

    Solution s(*data, k);
    delete data;
    cout << s << endl;

    return 0;
}