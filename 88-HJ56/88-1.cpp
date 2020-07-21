#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_set>
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

    bool isPerfect(int n)
    {
        if (n == 1) {
            return false;
        }
        unordered_set<int> tmp;
        tmp.insert(1);
        for (size_t i = 2, e = sqrt(n); i <= e; i++) {
            if ((n / i) * i == n) {
                tmp.insert(i);
                tmp.insert(n / i);
            }
        }
        int sum_tmp = accumulate(tmp.begin(), tmp.end(), 0);
        return sum_tmp == n;
    }

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
    for (const int& e : n) {
        int ans = 0;
        for (size_t i = 1; i <= e; i++) {
            if (isPerfect(i)) {
                ans++;
            }
        }
        out.push_back(ans);
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
    cout << s;
    return 0;
}
