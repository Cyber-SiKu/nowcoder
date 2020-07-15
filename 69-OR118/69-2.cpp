/**
 * 算法思想：
 *  B = [1 1    , A_n = [a_{n+q}, a_n]
 *       1 0]
 * => A_{n+1} = A_n * B
 * 
 * 运行时间：2ms
 * 占用内存：504k
*/

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
private:
    int k;
    int out = 0;

public:
    Solution(/* args */);
    ~Solution();
    void slove();
    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);

protected:
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    int e = this->k - 2;
    int pre[2] = { 1, 1 };
    for (size_t i = 0; i < e; i++) {
        int tmp = pre[1];
        pre[1] += pre[0];
        pre[0] = tmp;
    }

    out = pre[1];
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.k;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s << endl;
    return 0;
}