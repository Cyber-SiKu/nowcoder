/**
 * 算法思想：
 *  最苯的方法：挨个试
*/

/**
 * 内存超出限制
*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
private:
    const vector<int> ADD_NUM = { 2, 3, 5 };

public:
    /**
     * 返回最终的答案
     * @param s1 string字符串 表示初始的字符串
     * @param s2 string字符串 表示目标的字符串
     * @return int整型
     */
    int solve(string s1, string s2)
    {
        queue<string> qs;
        qs.push(s1);
        int count = 0; // 计算变换了第几次
        while (!qs.empty()) {
            count++;
            string s = qs.front();
            qs.pop();
            for (size_t i = 0; i < s.size(); i++) {
                /* 选择的位置为i */
                string replace(s);
                for (size_t j = 0, k = 0; j < s.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    replace[j] = (replace[j] - 'a' + ADD_NUM[k]) % 26 + 'a'; // 替换
                    k++;
                }

                if (replace == s2) {
                    return count;
                } else {
                    qs.push(replace);
                }
            }
        }
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().solve("aaaa", "ccgk") << endl;
    return 0;
}
