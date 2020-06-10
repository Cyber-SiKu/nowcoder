/**
 * 暴力求解
 * 使用正则表达替换xy
 * 
 * bug:超时
*/

#include <iostream>
#include <iterator>
#include <regex>
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
};

Solution::Solution(const string& str)
    : str(str)
    , re("xy")
    , replace("yyx")
    , number(0)
{
    regex_token_iterator<string::const_iterator> split(this->str.cbegin(), this->str.cend(), re);
    int count = vector<string>(split, sregex_token_iterator()).size();

    while (count != 0) {
        number = (count + number) % MAGIC_NUMBER;
        this->str = string(regex_replace(this->str, re, replace));
        split = regex_token_iterator<string::const_iterator>(this->str.cbegin(), this->str.cend(), re);
        count = vector<string>(split, sregex_token_iterator()).size();
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

int main(int argc, char* argv[])
{
    string str;
    cin >> str;

    Solution s(str);

    cout << s << endl;

    return 0;
}