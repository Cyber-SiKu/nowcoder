#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ins;
    vector<int> outs;
    vector<int> data;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
    : data { 0, 1 }
{
}

Solution::~Solution()
{
}

void Solution::slove()
{
    for (const int month : ins) {
        for (size_t i = data.size(); i <= month; i++) {
            /* code */
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
    cout << s << endl;
    return 0;
}
