/**
 * 算法优化：
 *  new 占用时间过大 故对mn判断
 * 运行时间：2226ms
 * 占用内存：43544k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

const int MAXSIZE = 3000;

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
        vector<int>::const_reverse_iterator rbegin = i.crbegin();
        if (*rbegin < k) {
            continue;
        }
        vector<int>::const_iterator begin = i.cbegin();
        if (*begin > k) {
            break;
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
    if (m * n > MAXSIZE) {
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
    } else {
        vector<vector<int>> data(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                int x;
                cin >> x;
                data[i][j] = x;
            }
        }
        int k;
        cin >> k;

        Solution s(data, k);
        cout << s << endl;
    }

    return 0;
}