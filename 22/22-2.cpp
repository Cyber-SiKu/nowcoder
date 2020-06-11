/**
 * 暴力求解
 * 挨个匹配
 * 
 * bug:超时 33.33%、
 * */

#include <iostream>
#include <iterator>
#include <regex>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    /* data */
    regex re;
    string str;
    string replace;
    const int MAGIC_NUMBER = 10e9 + 7;
    int number; // 记录数值

public:
    Solution(const string& str);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // ab 字符是否可替换
    bool isReplace(char a, char b);
};

Solution::Solution(const string& str)
    : str(str)
    , re("xy")
    , replace("yyx")
    , number(0)
{
    stack<char> s_front;
    stack<char> s_back;
    for (int e = -1, i = str.size() - 1; i > e; i--) {
        s_back.push(str[i]);
    }
    s_front.push(s_back.top());
    s_back.pop();
    while (!s_back.empty()) {
        if (s_front.empty()) {
            /* 前面栈为空，字符被匹配完毕 */
            s_front.push(s_back.top());
            s_back.pop();
        } else {
            /* 仍有未判断的字符 */
            char a = s_front.top();
            char b = s_back.top();
            if (!this->isReplace(a, b)) {
                // 不可以替换
                s_front.push(b);
                s_back.pop();
            } else {
                // 可以替换
                this->number++;
                // 替换
                s_front.pop();
                s_back.pop();
                s_back.push('x');
                s_back.push('y');
                s_back.push('y');
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.number;
    return os;
}

bool Solution::isReplace(char a, char b)
{
    return (a == 'x') && (b == 'y');
}

int main(int argc, char* argv[])
{
    string str;
    cin >> str;

    Solution s(str);

    cout << s << endl;

    return 0;
}