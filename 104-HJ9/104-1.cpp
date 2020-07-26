#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string in;
    vector<bool> number_used;
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
    out.clear();
    number_used.clear();
    number_used.resize(10, false);
    for (string::const_reverse_iterator i = in.crbegin(); i != in.crend(); ++i) {
        if (!number_used[*i - '0']) {
            out.push_back(*i);
            number_used[*i - '0'] = true;
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.in;
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
