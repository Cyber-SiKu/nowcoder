#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string passwd;
    unordered_map<char, int> char2int;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
    char2int['a'] = char2int['b'] = char2int['c'] = 2;
    char2int['d'] = char2int['e'] = char2int['f'] = 3;
    char2int['g'] = char2int['h'] = char2int['i'] = 4;
    char2int['j'] = char2int['k'] = char2int['l'] = 5;
    char2int['m'] = char2int['n'] = char2int['o'] = 6;
    char2int['p'] = char2int['q'] = char2int['r'] = char2int['s'] = 7;
    char2int['t'] = char2int['u'] = char2int['v'] = 8;
    char2int['w'] = char2int['x'] = char2int['y'] = char2int['z'] = 9;
}

Solution::~Solution()
{
}

void Solution::slove()
{
    for (string::iterator i = passwd.begin(); i != passwd.end(); ++i) {
        if (isupper(*i)) {
            // 大写字母
            *i = tolower(*i) + 1;
            if (*i > 'z') {
                *i = 'a';
            }
        } else if (islower(*i)) {
            *i = char2int[*i] + '0';
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.passwd;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.passwd;
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
