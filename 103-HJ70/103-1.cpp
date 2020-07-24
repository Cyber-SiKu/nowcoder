#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    vector<pair<int, int>> matrix;
    int out;
    string accumulate;

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
    out = 0;
    pair<int, int> tmp(0, 0);
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int n, x, y;
    is >> n;
    for (size_t i = 0; i < n; i++) {
        is >> x >> y;
        s.matrix.push_back(make_pair(x, y));
    }
    is >> s.accumulate;
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
