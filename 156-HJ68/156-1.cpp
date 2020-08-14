#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b, function<bool(int, int)> c)
{
    return c(a.second, b.second);
}

class Solution
{
private:
    int sortNum;
    unordered_map<int, function<bool(pair<string, int>, pair<string, int>)>> sortFunction;
    vector<pair<string, int>> nameScores;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream &operator<<(ostream &os, const Solution &s);
    friend istream &operator>>(istream &is, Solution &s);
};

Solution::Solution(/* args */)
{
    sortFunction[0] = bind(compare, placeholders::_1, placeholders::_2, greater<int>());
    sortFunction[1] = bind(compare, placeholders::_1, placeholders::_2, less<int>());
}

Solution::~Solution()
{
}

void Solution::slove()
{
    function<bool(pair<string, int>, pair<string, int>)> c = sortFunction[sortNum];
    stable_sort(this->nameScores.begin(), this->nameScores.end(), c);
}

ostream &operator<<(ostream &os, const Solution &s)
{
    for (const pair<string, int> &i : s.nameScores)
    {
        cout << i.first << " " << i.second << endl;
    }

    return os;
}
istream &operator>>(istream &is, Solution &s)
{
    int num;
    cin >> num;
    cin >> s.sortNum;
    s.nameScores.clear();
    s.nameScores.resize(num);
    for (size_t i = 0; i < num; i++)
    {
        int score;
        cin >> s.nameScores[i].first >> s.nameScores[i].second;
    }

    return is;
}

int main(int argc, char *argv[])
{
    Solution s;
    while (cin >> s)
    {
        s.slove();
        cout << s;
    }
    return 0;
}
