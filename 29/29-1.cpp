#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os;
}

int main(int argc, char* argv[])
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> cost_time(n, 0);
    vector<int> youyou_happiness(n, 0);
    vector<int> mate_happiness(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> cost_time[1] >> youyou_happiness[i] >> mate_happiness[i];
    }
    for (size_t i = 0; i < m; i++) {
    }

    Solution s;

    cout << s << endl;
    return 0;
}