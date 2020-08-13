#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <class T>
bool compare(const pair<string, int>& a, const pair<string, int>& b, T c)
{
    return c(a.second, b.second);
}

class Solution {
private:
    int sortNum;
    unordered_map<int, function<bool(int, int)>> sortFunction;
    vector<pair<string, int>> nameScores;

public:
    Solution(/* args */);
    ~Solution();
    void slove();

    friend ostream& operator<<(ostream& os, const Solution& s);
    friend istream& operator>>(istream& is, Solution& s);
};

Solution::Solution(/* args */)
{
    sortFunction[0] = greater<int>();
    sortFunction[1] = less<int>();
}

Solution::~Solution()
{
}

void Solution::slove()
{
    function<bool(int, int)> c = sortFunction[sortNum];
    sort(this->nameScores.begin(), this->nameScores.end(), compare<c>);
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const pair<string, int>& i : s.nameScores) {
        cout << i.second << " " << i.second << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int num;
    cin >> num;
    cin >> s.sortNum;
    for (size_t i = 0; i < num; i++) {
        string name;
        int score;
        cin >> name >> score;
        s.nameScores.push_back(make_pair(name, score));
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
