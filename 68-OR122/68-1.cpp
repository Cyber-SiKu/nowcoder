#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> map;

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
    int length = this->map.size() - 1;
}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    size_t n;
    is >> n;
    s.map.reserve(n + 1);
    for (size_t i = 0; i < n; i++) {
        int x, y;
        is >> x >> y;
        s.map[x] = y;
    }

    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    cout << s << endl;
    return 0;
}