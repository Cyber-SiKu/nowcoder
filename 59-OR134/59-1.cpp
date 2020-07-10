#include <iostream>

using namespace std;

class Solution {
private:
    int out;

public:
    Solution(const int& a, const int& b);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    bool isLuckyNumer(int n);
};

Solution::Solution(const int& a, const int& b)
{
    if (a > b) {
        out = -1;
        return;
    }
}

Solution::~Solution()
{
}

bool Solution::isLuckyNumer(int n)
{
    bool ret = true;
    while (n != 0) {
        int tmp = n % 10;
        if (tmp != 6 && tmp != 8) {
            ret = false;
            break;
        }
    }
    return ret;
}

ostream& operator<<(ostream& os, const Solution& s)
{
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