/**
 * 算法思想：
 * 数数
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
    long a = 1, b = 3;
    while (a < t) {
        a += b;
        b *= 2;
    }

    if (a == t) {
        this->value = b;
    } else {
        this->value = a - t;
    }
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