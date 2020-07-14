#include <iostream>

using namespace std;

class Solution {
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
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
    cout << s << endl;
    return 0;
}