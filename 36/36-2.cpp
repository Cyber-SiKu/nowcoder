/**
 * dp 
 * 时间复杂度过大
 * 80.0%
*/
#include <iostream>
#include <vector>

using namespace std;
const unsigned MAX = 2147483647;

class Solution {
private:
    int outs;

public:
    Solution(unsigned n);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    inline unsigned get_1_number(unsigned n);
};

Solution::Solution(unsigned n)
    : outs(0)
{
    // dp 1到 i-1 有多少 1
    int dp = 0;
    // memset(dp, 0, sizeof(dp));
    for (unsigned i = 1; i <= n; i++) {
        dp += this->get_1_number(i);
    }
    outs = dp;
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

unsigned Solution::get_1_number(unsigned n)
{
    unsigned ret = 0;
    while (n != 0) {
        ret += (n % 10 == 1 ? 1 : 0);
        n /= 10;
    }
    return ret;
}

int main(int argc, char* argv[])
{
    unsigned n;
    cin >> n;
    Solution s(n);

    cout << s << endl;
    return 0;
}