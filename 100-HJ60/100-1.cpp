#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    int in;
    int out[2];

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    bool isMean(int n);

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
    out[0] = in / 2;
    out[1] = in - out[0];
    while (!isMean(out[0]) || !isMean(out[1])) {
        out[0]--;
        out[1] = in - out[0];
    }
}

bool Solution::isMean(int n)
{
    bool ret = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ret = false;
            break;
        }
    }
    return ret;
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out[0] << endl
       << s.out[1];
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.in;
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
