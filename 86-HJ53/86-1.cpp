#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ins;
    vector<int> outs;

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
    for (const int& i : ins) {
        if (i <= 2) {
            outs.push_back(-1);
        } else if (i % 2 == 1) {
            outs.push_back(2);
        } else {
            if (i % 4 == 0) {
                outs.push_back(3);
            } else {
                outs.push_back(4);
            }
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        os << i << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int x;
    while (is >> x) {
        s.ins.push_back(x);
    }

    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s;
    return 0;
}
