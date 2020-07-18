/**
 * 运行时间：204ms
 * 占用内存：8668k
*/
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
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
        if (s1 == s2) {
            return 0;
        }
        queue<string> q;
        set<string> sett;
        q.push(s1);
        sett.insert(s1);
        int count = 0; // 计算变换了第几次

        while (!q.empty()) {
            count++;
            queue<string> qs(q);

            while (!q.empty()) {
                qs.push(q.front());
                q.pop();
            }
            while (!qs.empty()) {
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
                        if (sett.find(replace) == sett.end()) {
                            q.push(replace);
                            sett.insert(replace);
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().solve("aaaa", "ccgk") << endl;
    cout << Solution().solve("fjdj", "jlas") << endl;
    return 0;
}
