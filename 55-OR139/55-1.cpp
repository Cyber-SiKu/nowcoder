/**
 * 运行时间：1ms
 * 占用内存：376k
*/
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
    unsigned out;

public:
    Solution(const vector<int>& prices, const vector<pair<int, int>>& goods);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<int>& prices, const vector<pair<int, int>>& goods)
    : out(0)
{
    for (const pair<int, int>& i : goods) {
        out += i.second * prices[i.first];
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    // os << s.out;
    printf("%d", s.out);
    return os;
}

int main(int argc, char* argv[])
{
    int n;
    // cin >> n;
    scanf("%d", &n);
    vector<int> prices(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        // cin >> prices[i];
        scanf("%d", &prices[i]);
    }

    int m;
    // cin >> m;
    scanf("%d", &m);
    vector<pair<int, int>> goods(m, make_pair(0, 0));
    for (size_t i = 0; i < m; i++) {
        // cin >> goods[i].first >> goods[i].second;
        scanf("%d %d", &goods[i].first, &goods[i].second);
    }

    Solution s(prices, goods);

    cout << s << endl;
    return 0;
}