/**
 * 算法思想：
 *  建立两个表：1. 有限域数表; 2. 素数表(不包含1)
 * 
 *  利用已有的数据填充上述两个表
 * 
 *  判断是否大于37
 *      小于 查表即可
 *      大于 从 38 开始到输入的数一次判断是否是有限域数，是添加进有限域数表
 *          最后输出有限域数表大小
 *          
 *          判断有限域的函数：
 *              首先判断是否是素数，是返回真，并添加进素数表
 *              若不是素数，判断是否是某个素数的方幂，
 *                  若是返回 true 否则 false
 * 
 * 
 * 
 * 运行时间：3ms
 * 占用内存：376k
*/
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> data;
    vector<int> prime;
    int out;

public:
    Solution(const int& n);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    bool isFitNumber(const int& n);
};

Solution::Solution(const int& n)
    : data({ 2, 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19, 23, 25, 27, 29, 31, 32, 37 })
    , prime({ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 })
{
    out = 0;
    if (n <= 31) {
        for (const int& i : data) {
            if (i > n) {
                break;
            }
            out++;
        }
        return;
    }

    // 大于37
    for (int i = (*data.rbegin()) + 1; i <= n; i++) {
        if (this->isFitNumber(i) == true) {
            this->data.push_back(i);
        }
    }
    out = this->data.size();
}

Solution::~Solution()
{
}

bool Solution::isFitNumber(const int& n)
{
    bool ret = true;

    // 判断 n 是否是素数
    int sqrt_num = sqrt(n);
    for (int i = 2; i <= sqrt_num; i++) {
        if ((n / i) * i == n) {
            // 不是素数
            ret = false;
            break;
        }
    }

    // n不是素数时，判断 n 是否是某个素数的整数幂
    if (ret == false) {
        for (int i = 0; this->prime[i] <= sqrt_num; i++) {
            int tmp = this->prime[i];
            while (tmp < n) {
                // 循环判断
                tmp *= this->prime[i];
            }
            if (tmp == n) {
                ret = true;
                break;
            }
        }
    } else {
        prime.push_back(n);
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
    int n;
    cin >> n;
    Solution s(n);

    cout << s << endl;
    return 0;
}