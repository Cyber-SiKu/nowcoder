#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 返回最后要输出的答案
     * @param n int整型 表示牛牛的数字
     * @param m int整型 表示牛妹的数字
     * @return int整型
     */
    int solve(int n, int m)
    {
        if (m < n) {
            return n - m;
        }

        queue<int> data;
        unordered_set<int> sett;
        data.push(n);
        int count = 0;
        while (!data.empty()) {
            count++;
            vector<int> row;
            while (!data.empty()) {
                row.push_back(data.front());
                data.pop();
            }

            vector<int> tmp;
            for (const int& i : row) {
                // -1
                tmp.push_back(i - 1);
                int i_2 = i * i;
                if (abs(i_2 - m) > abs(i + 1 - m)) {
                    tmp.push_back(i + 1);
                } else {
                    tmp.push_back(i_2);
                }
            }

            // 检查新增的数字
            for (const int& i : tmp) {
                if (i == m) {
                    // 找到数字
                    return count;
                }
                if (sett.find(i) == sett.end()) {
                    // 数字数字计算出来过
                    data.push(i);
                    sett.insert(i);
                }
            }
        }

        return count;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().solve(3, 10) << endl;

    cout << Solution().solve(1, 10) << endl;

    return 0;
}
