#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Solution {
private:
    string str;
    vector<string> outs;

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
    regex ws_re(" ");
    vector<string> split(sregex_token_iterator(str.begin(), str.end(), ws_re, -1), sregex_token_iterator());

    for (size_t i = 0; i < split.size(); i++) {
        string tmp = split[i];
        while (*tmp.begin() == '"' && *tmp.rbegin() != '"') {
            // 使用 “” 包裹的字符中间有空格
            ++i;
            tmp = tmp + " " + split[i];
        }
        outs.push_back(tmp);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs.size() << endl;
    for (const string& i : s.outs) {
        os << i << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    // is >> s.str;
    getline(is, s.str);
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s;
    return 0;
}
