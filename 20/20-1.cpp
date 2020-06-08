/**
 * 算法思想：
 * 暴力求解
 * bug: t 过大时内存不够
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // value[i] 表示 i+1 时刻的数字
    vector<int> value;

public:
    Solution(int t);
    ~Solution();
    int slove() const;
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(int t)
{
    value.resize(t);
    int init = 3;
    int number = init;
    for (size_t i = 0; i < t; i++) {
        value[i] = number;
        number--;
        if (number == 0) {
            init *= 2;
            number = init;
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.slove();
    return os;
}

int Solution::slove() const
{
    return *(this->value.rbegin());
}

int main(int argc, char* argv[])
{
    int t;
    cin >> t;
    Solution s(t);
    cout << s << endl;
    return 0;
}