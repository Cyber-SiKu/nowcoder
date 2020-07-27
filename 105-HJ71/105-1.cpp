#include <iostream>
#include <iterator>
#include <regex>
#include <string>

using namespace std;

class Solution {
private:
    string re;
    string str;
    string out;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    out = "false";
    for (size_t i = 0; i < re.size(); i++) {
        if (re[i] == '?') {
            re.insert(i, "[a-zA-Z0-9]");
            i += 11;
            continue;
        }
        if (re[i] == '*') {
            re.insert(i, "[a-zA-Z0-9]");
            i += 11;
            continue;
        }
    }

    regex re_ws(re);
    if (regex_match(str, re_ws)) {
        out = "true";
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.re;
    is >> s.str;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
