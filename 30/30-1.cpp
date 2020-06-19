/**
 * 算法思想：
 *  暴力穷举
 * 
 * 运行时间：3ms
 * 占用内存：496k
*/
#include <iostream>

using namespace std;

class Solution {
private:
    int count;

public:
    Solution(const long& value);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const long& value)
    : count(0)
{
    long tmp = value;
    while (tmp != 0) {
        tmp = tmp & (tmp - 1);
        this->count++;
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.count;
    return os;
}

int main(int argc, char* argv[])
{

    long value;
    cin >> value;
    Solution s(value);

    cout << s << endl;
    return 0;
}