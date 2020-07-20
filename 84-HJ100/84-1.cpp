#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> n;
    vector<int> out;

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
    for (const int& i : n) {
        int sum = (2 * 2 + (i - 1) * 3) * i / 2;
        out.push_back(sum);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.out) {
        os << i << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int x;
    while (is >> x) {
        s.n.push_back(x);
    }

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
