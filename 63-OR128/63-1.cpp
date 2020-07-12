/**
 * 运行时间：3ms
 * 占用内存：376k
*/
#include <iostream>

using namespace std;

class Solution {
private:
    int out;

public:
    Solution(const int& n);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const int& n)
{
    out = -1;
    for (int six = 0, eight = n / 8; eight >= 0; eight--) {
        six = (n - 8 * eight) / 6;
        if (n == six * 6 + eight * 8) {
            out = six + eight;
            break;
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os << s.out;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    cout << Solution(n) << endl;
    return 0;
}