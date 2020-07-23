#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> data;
    string in;
    int out;

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
    data.clear();
    data.resize(128, 0);
    for (const char& i : in) {
        if (i >= 0 && i <= 127) {
            data[i] = 1;
        }
    }
    out = accumulate(data.begin(), data.end(), 0);
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
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
