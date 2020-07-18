/**
 * 算法思想：
 *  最苯的方法：挨个试
*/

/**
 * 内存超出限制
*/
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

class Solution {
private:
public:
    /**
     * 返回最终的答案
     * @param s1 string字符串 表示初始的字符串
     * @param s2 string字符串 表示目标的字符串
     * @return int整型
     */
    int solve(string s1, string s2)
    {
        int num = 0;
        queue<string> q;
        q.push(s1);
        set<string> sett;
        sett.insert(s1);
        while (s1 != s2) {
            num++;
            vector<string> vec;
            while (!q.empty()) {
                string temp = q.front();
                q.pop();

                string tt = temp;
                tt[1] = (tt[1] - 'a' + 2) % 26 + 'a';
                tt[2] = (tt[2] - 'a' + 3) % 26 + 'a';
                tt[3] = (tt[3] - 'a' + 5) % 26 + 'a';
                vec.push_back(tt);

                tt = temp;
                tt[0] = (tt[0] - 'a' + 2) % 26 + 'a';
                tt[2] = (tt[2] - 'a' + 3) % 26 + 'a';
                tt[3] = (tt[3] - 'a' + 5) % 26 + 'a';
                vec.push_back(tt);

                tt = temp;
                tt[0] = (tt[0] - 'a' + 2) % 26 + 'a';
                tt[1] = (tt[1] - 'a' + 3) % 26 + 'a';
                tt[3] = (tt[3] - 'a' + 5) % 26 + 'a';
                vec.push_back(tt);

                tt = temp;
                tt[0] = (tt[0] - 'a' + 2) % 26 + 'a';
                tt[1] = (tt[1] - 'a' + 3) % 26 + 'a';
                tt[2] = (tt[2] - 'a' + 5) % 26 + 'a';
                vec.push_back(tt);
            }
            vector<string>::iterator it;
            int flag = 0;
            for (it = vec.begin(); it != vec.end(); it++) {
                cout << *it << " ";
                if (*it == s2) {
                    flag = 1;
                    break;
                } else if (sett.find(*it) == sett.end()) {
                    q.push(*it);
                    sett.insert(*it);
                }
            }
            cout << endl;
            if (flag == 1)
                break;
        }
        return num;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution().solve("aaaa", "ccgk") << endl;
    cout << Solution().solve("fjdj", "jlas") << endl;
    return 0;
}
