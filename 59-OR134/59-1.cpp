/**
 * 算法思想：
 *      幸运数字与定长二级制数对应（6->0, 8->1）
 *      所以求出a，b的长度区间[min, max]
 *          记区间内的数字i 2^i 为对应长度的幸运数字的个数
 *      然后扣除min中小于a的和max中大于b的
 * 运行时间：2ms
 * 占用内存：376k
*/

#include <iostream>

using namespace std;

class Solution {
private:
    int out;

public:
    Solution(const int& a, const int& b);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // 求出数字的长度
    static int length(int n);

    // 将数字（二进制）转化为对应的幸运数字（0->6, 1->8）
    static int number2lucky(int n, const int& length);

    // 长度为length中的额幸运数字小于 n 的有多少个
    static int lessNumber(int n, const int& length);

    // 长度为length中的额幸运数字小于等于 n 的有多少个
    static int lessEqualNumber(int n, const int& length);
};

Solution::Solution(const int& a, const int& b)
{
    if (a > b) {
        out = -1;
        return;
    }
    int min = this->length(a);
    int max = this->length(b);
    this->out = 0;
    for (int i = min; i < max; ++i) {
        this->out += long(1 << i);
    }

    // 扣除min中不符合规则的
    this->out -= Solution::lessNumber(a, min);
    this->out += Solution::lessEqualNumber(b, max);
}

Solution::~Solution()
{
}

int Solution::length(int n)
{
    int ret = 0;
    while (n != 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

int Solution::number2lucky(int n, const int& length)
{
    int ret = 0;
    for (int i = 0, e = length; i < e; i++) {
        ret *= 10;
        // if ((1<<i) & n == 0) {
        //     ret += 6;
        // } else {
        //     ret += 8;
        // }
        ret += (6 + 2 * ((1 << i) & n));
    }

    return ret;
}

int Solution::lessNumber(int n, const int& length)
{
    int ret = 0;
    for (int i = 0, end = ((1 << (length + 1)) - 1); i < end; i++) {
        int tmp = Solution::number2lucky(i, length);
        if (tmp < n) {
            ret++;
        } else {
            break;
        }
    }
    return ret;
}
int Solution::lessEqualNumber(int n, const int& length)
{
    int ret = 0;
    for (int i = 0, end = ((1 << (length + 1)) - 1); i < end; i++) {
        int tmp = Solution::number2lucky(i, length);
        if (tmp <= n) {
            ret++;
        } else {
            break;
        }
    }
    return ret;
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}

int main(int argc, char* argv[])
{
    int a, b;
    cin >> a >> b;
    Solution s(a, b);

    cout << s << endl;
    return 0;
}