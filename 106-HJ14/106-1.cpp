#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> in;
    vector<string>& out = in;

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
    sort(in.begin(), in.end());
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const string& i : s.out) {
        os << i << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int n;
    is >> n;
    string str;
    for (size_t i = 0; i < n; i++) {
        is >> str;
        s.in.push_back(str);
    }

    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s;
    }
    return 0;
}
