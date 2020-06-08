/**
 * 算法思想：
 * 数列法：
 * 规律是：3×2^0+ \dots +3×2^{n-1}>= t
 * 求出n后value = t - 3*(2^n - 1) + 1
*/
#include <iostream>
// #include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    // value 表示 t 时刻的数字
    long value;

public:
    Solution(unsigned long long t);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(unsigned long long t)
{
    long n = log2(t / 3 + 1);
    this->value = 3 * pow(2, n) - t - 2;
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.value;
    return os;
}

int main(int argc, char* argv[])
{
    unsigned long long t;
    cin >> t;
    Solution s(t);
    cout << s << endl;
    return 0;
}