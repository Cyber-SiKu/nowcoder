/**
 * 暴力求解
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 n个人
     * @param a int整型vector ai代表第i个人的高度
     * @return long长整型
     */
    long long solve(int n, vector<int>& a);
};

long long Solution::solve(int n, vector<int>& a)
{
    long long ret = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[i]) {
                ret += (j + 1);
                break;
            }
        }
    }
    return ret;
}

int main(int argc, char const* argv[])
{
    // vector<int> data = { 1, 2, 3, 4, 5 };

    vector<int> data = { 5, 4, 3, 2, 1 };

    Solution s;
    cout << s.solve(data.size(), data) << endl;

    return 0;
}
