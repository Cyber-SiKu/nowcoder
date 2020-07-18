/**
 * 算法思想：
 *  可能出现的情况
 *     0 | 1 | 2 | 3
 *  k0     2   3   5
 *  k1 2       3   5
 *  k2 2   3       5
 *  k3 2   3   5
 * 
 * 取A=\matrix{ 0, 2, 3, 5 \\ 
 *              2, 0, 3, 5 \\
 *              2, 3, 0, 5 \\
 *              2, 3, 5, 0}
 * 
 * 然后sum(pinv(A)*[str2-str1])
*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
private:
    int A_[4][4] = { { -12, 3, 3, 3 }, { 7, -8, 2, 2 }, { 5, 5, -5, 1 }, { 3, 3, 3, -3 } };

public:
    /**
     * 返回最终的答案
     * @param s1 string字符串 表示初始的字符串
     * @param s2 string字符串 表示目标的字符串
     * @return int整型
     */
    bool isCorrect()
    {
    }
    int solve(string s1, string s2)
    {
        int a[4] = { 0 };
        for (size_t i = 0; i < 4; i++) {
            a[i] = (s2[i] - s1[i]);
        }

        int ans[4] = { 0 };
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                ans[i] += (A_[i][j] * a[j]);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().solve("fjdj", "jlas") << endl;
    return 0;
}
