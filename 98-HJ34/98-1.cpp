#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string str;

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
    sort(str.begin(), str.end());
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.str;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
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
