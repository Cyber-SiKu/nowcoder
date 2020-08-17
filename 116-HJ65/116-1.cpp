#include <iostream>

using namespace std;

class Solution {
private:
    string str1;
    string str2;

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
}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s << endl;
    return 0;
}
