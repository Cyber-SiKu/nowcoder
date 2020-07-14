/**
 * 算法思路：
 *  出现死锁的条件：
 *      记已写入的内存的大小为 q
 *      当 R > Q && W > L - Q 时
 *      出现死锁
 *   根据死锁出现的条件，计算死锁发生的范围，然后看 W 和 R 的组合能否出现在范围之内
 * 
 * 运行时间：2ms
 * 占用内存：396k
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int L, R, W;
    string out;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    int upper = this->R;
    int lower = this->L - this->W;
    if (lower >= upper) {
        out = "OK";
    } else {
        // [lower, upper]
        int sub = this->L - this->R;
        if (sub < 0) {
            // 减少型
            sub = -sub;
            int tmp_lower = lower;
            int max = (this->L / this->W) * this->W;
            lower = max - upper;
            upper = max - tmp_lower;
        }

        int lower_bound = lower / sub;
        lower_bound += (lower - sub * lower_bound > 0 ? 1 : 0);
        int upper_bound = upper / sub;
        upper_bound += (upper - sub < 0 ? 0 : 1);
        if (upper_bound >= lower_bound) {
            this->out = "DEADLOCK";
        } else {
            this->out = "OK";
        }
    }
}

ostream&
operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}

istream& operator>>(istream& is, Solution& s)
{
    is >> s.L >> s.R >> s.W;
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