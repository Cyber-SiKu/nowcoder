/**
 * 运行时间：3ms
 * 占用内存：416k
*/

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

class Solution {
private:
    string outs;

public:
    Solution(string str1, string str2);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    string stringMulc(const string& str, int c);
    string str1PlusStr2(string str1, string str2);
};

Solution::Solution(string str1, string str2)
{
    string base(str2.rbegin(), str2.rend());

    while (*base.rbegin() == '0') {
        base.pop_back();
    }

    while (*str1.begin() == '0') {
        str1.erase(str1.begin());
    }

    string carry = "";
    for (string::reverse_iterator i = str1.rbegin(), e = str1.rend(); i != e; i++) {
        string ans = this->stringMulc(base, *i - '0');
        ans.insert(ans.begin(), carry.begin(), carry.end());
        outs = this->str1PlusStr2(this->outs, ans);
        carry.push_back('0');
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (string::const_reverse_iterator i = s.outs.crbegin(), e = s.outs.crend(); i != e; i++) {
        os << *i;
    }

    return os;
}

string Solution::stringMulc(const string& str, int c)
{
    string ret(str);
    int carry = 0; // 保存进位
    for (string::iterator i = ret.begin(), e = ret.end(); i != e; i++) {
        int ans = ((*i) - '0') * c + carry;
        carry = ans / 10;
        *i = ans % 10 + '0';
    }
    if (carry != 0) {
        ret.push_back(carry + '0');
    }
    return ret;
}

string Solution::str1PlusStr2(string str1, string str2)
{
    if (str2.size() > str1.size()) {
        string tmp(str1);
        str1 = str2;
        str2 = tmp;
    }
    int carry = 0;
    string::iterator i = str1.begin(), e_i = str1.end();
    for (string::iterator j = str2.begin(), e_j = str2.end(); i != e_i && j != e_j; ++i, ++j) {
        int ans = (*i - '0') + (*j - '0') + carry;
        carry = ans / 10;
        *i = ans % 10 + '0';
    }

    if (i != e_i) {
        while (carry != 0 && i != e_i) {
            int ans = (*i - '0') + carry;
            carry = ans / 10;
            *i = ans % 10 + '0';
            ++i;
        }
    }

    if (carry != 0) {
        str1.push_back(carry + '0');
    }

    return str1;
}

int main(int argc, char* argv[])
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    Solution s(str1, str2);

    cout << s << endl;
    return 0;
}