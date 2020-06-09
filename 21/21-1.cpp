#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> strs;

public:
    Solution(string s);
    friend ostream& operator<<(ostream& os, const Solution& s);
    ~Solution();
};

Solution::Solution(string s)
{
    // 将字符串分割
    const regex ws_re(":");
    // strs = vector<string>(regex_token_iterator<string::iterator>(s.begin(), s.end(), ws_re, -1), regex_token_iterator<string::iterator>());
    strs = vector<string>(sregex_token_iterator(s.begin(), s.end(), ws_re, -1), sregex_token_iterator());

    // 取出带标志的最后一组
    vector<string>::reverse_iterator i_r = strs.rbegin();
    string flag(i_r->begin() + 2, i_r->end()); // 保存上午下午的标志位
    *i_r = i_r->substr(0, 2); // 去掉标志
    if (flag[0] == 'P') {
        /* 下午 */
        int i = stoi(*strs.begin()); // 将第一个数转化为整数
        i += 12;
        if (i == 24) {
            *strs.begin() = string("12");
        } else {
            *strs.begin() = to_string(i);
        }
    } else {
        /* 上午午 flag[0] == 'A' */
        int i = stoi(*strs.begin()); // 将第一个数转化为整数
        if (i == 12) {
            *strs.begin() = string("00");
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    vector<string>::const_iterator i = s.strs.begin();
    os << *i;
    vector<string>::const_iterator e = s.strs.end();
    for (i++; i != e; i++) {
        os << ":" << *i;
    }

    return os;
}

int main(int argc, char* argv[])
{
    string str;
    cin >> str;
    Solution s(str);
    cout << s << endl;
    return 0;
}
