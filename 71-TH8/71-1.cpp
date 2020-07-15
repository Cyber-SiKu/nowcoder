/**
 * 算法思想：
 *  当找到顶点时 (两边比他小)，计算长度，找出最大的
 * 运行时间：219ms
 * 占用内存：36064k
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 获取顶点为pos时的长度
    int getLength(int pos, const vector<int>& num)
    {
        // 求最左
        int left = pos - 1;

        // 求最右
        int right = pos + 1;
        int max = num.size() - 1;

        while (num[left - 1] < num[left] && left != 0 && num[right + 1] < num[right] && right != max) {
            --left;
            ++right;
        }

        while (num[left - 1] < num[left] && left != 0) {
            --left;
        }

        while (num[right + 1] < num[right] && right != max) {
            ++right;
        }

        return right - left + 1;
    }

    /**
     * 
     * @param n int整型 
     * @param num int整型vector 
     * @return int整型
     */
    int getMaxLength(int n, vector<int>& num)
    {
        // write code here

        // 获取最高点
        // vector<int> high_point; // 存储顶点的位置
        int ret = 0;
        for (size_t i = 1, e = num.size() - 2; i < e; i++) {
            if (num[i - 1] < num[i] && num[i + 1] < num[i]) {
                /* 顶点 */
                int tmp = this->getLength(i, num);
                if (tmp > ret) {
                    ret = tmp;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    int n1 = 4;
    vector<int> data1 = { 1, 2, 3, 1 };
    cout << s.getMaxLength(n1, data1) << endl;
    int n2 = 5;
    vector<int> data2 = { 1, 5, 3, 3, 1 };
    cout << s.getMaxLength(n2, data2) << endl;

    return 0;
}
