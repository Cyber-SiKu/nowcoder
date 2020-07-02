/**
 * 算法思想
 *  计算n!计算有多少个5（因式分解后）
 * 
 * 运行时间：9ms
 * 占用内存：608k
*/
#include <cmath>
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
    int ret = 0, pre = 0;
    for (int i = 5; i <= n; i++) {
        int tmp = 5;
        while (i / tmp >= 1) {
            ret += (i / tmp);
            tmp *= 5;
        }
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