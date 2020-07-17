#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int M, N;
    vector<vector<int>> map;

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

void Solution::slove() {}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.M >> s.N;
    s.map.resize(s.M, vector<int>(s.N));
    for (size_t i = 0; i < s.M; i++) {
        for (size_t j = 0; j < s.N; j++) {
            is >> s.map[i][j];
        }
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
