/**
 * 算法优化：
 *  1. new 占用时间过大 故对mn判断
 *  2. 改vector为 二维数组节省开辟内存的时间
 * 运行时间：2234ms
 * 占用内存：35696k
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

const int MAXSIZE = 3000;

int data[MAXSIZE][MAXSIZE];

class Solution {
private:
    string outs;

public:
    Solution((const int& m,(const int& n, const int& k);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const int& k)
{
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int main(int argc, char* argv[])
{
    int m, n;
    cin >> m >> n;

    return 0;
}