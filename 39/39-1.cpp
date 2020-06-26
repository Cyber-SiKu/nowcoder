#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class goods {
public:
    int m;
    int w;
    int s;
    goods(int m, int w, int s)
        : m(m)
        , w(w)
        , s(s)
    {
    }
};

struct compare_good {
    bool operator()(goods a, goods b)
    {
        return a.w < b.w;
    }
};

using array = multiset<goods, compare_good>; // [体积]，first:数量， second：价值

class Solution {
private:
    int max_value;

public:
    Solution(array data, int v);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    int getMaxValue(array data, int v); // 货物情况如data时，体积为v时可以拿到的最大物品价值总和
};

Solution::Solution(array data, int v)
{
    max_value = this->getMaxValue(data, v);
}
Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.max_value;
    return os;
}

int Solution::getMaxValue(array data, int v)
{
    if (v == 0) {
        return 0;
    }
}

int main(int argc, char* argv[])
{
    int n, v;
    cin >> n >> v;
    array data;
    int m, w, s;
    for (size_t i = 0; i < n; i++) {
        cin >> m >> w >> s;
        data.insert(goods(m, w, s));
    }

    Solution s(data, v);

    cout << s << endl;
    return 0;
}