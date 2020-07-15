/**
 * 算法思想：
 *  当找到顶点时 (两边比他小)，计算长度，找出最大的
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 获取顶点为pos时的长度
    int getLength(int pos, const vector<int>& num)
    {
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
        vector<int> high_point; // 存储顶点的位置
        for (size_t i = 1, e = num.size() - 1; i < e; i++) {
            if (num[i - 1] < num[i] && num[i + 1] < num[i]) {
                /* 顶点 */
                high_point.push_back(i);
            }
        }
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
