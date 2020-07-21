#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ms;
    vector<string> outs;

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
    for (const int& m : ms) {
        int sum = 0;
        queue<int> q;
        for (int i = 1, e = 2 * m - 1; i <= e; i += 2) {
            q.push(i);
            sum += i;
        }

        int target = m * m * m;
        while (sum < target) {
            // TODO
            int next = q.back() + 2;
            sum -= q.front();
            q.pop();
            q.push(next);
            sum += next;
        }

        string out;
        out += to_string(q.front());
        q.pop();
        while (!q.empty()) {
            out += string("+");
            out += to_string(q.front());
            q.pop();
        }
        outs.push_back(out);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const string& i : s.outs) {
        os << i << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int x;
    while (is >> x) {
        s.ms.push_back(x);
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
