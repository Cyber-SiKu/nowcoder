/**
 * 算法思想暴力计算
 * 
 * 时间复杂度过大
 * 20.00%
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int outs;

public:
    Solution(const int& n);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // 返回 1!*2!*...*n！后面有几个0
    int sum(const int& n);

    // 返回 n！后面有几个0
    int num(const int& n);

    // n%10 == 0返回n中有多少0
    int len(int n);
};

Solution::Solution(const int& n)
{
    this->outs = this->sum(n);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int Solution::sum(const int& n)
{
    int ret = 0;
    for (size_t i = 1; i <= n; i++) {
        ret += this->num(i);
    }
    return ret;
}

int Solution::num(const int& n)
{
    // 存储上次的计算结果，因为只计算一次，所以不用数组保存
    static int ret = 0;
    if (n % 10 == 5) {
        ret++;
    } else if (n % 10 == 0) {
        ret += this->len(n);
    }

    return ret;
}

int Solution::len(int n)
{
    int ret = 0;
    while (n % 10 == 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    Solution s(n);

    cout << s << endl;
    return 0;
}