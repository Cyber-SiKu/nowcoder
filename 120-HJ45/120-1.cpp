#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class compare {
public:
    bool operator()(const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second > b.second;
    }
};

class Solution {
private:
    vector<string> strs;
    vector<int> outs;

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
    outs.clear();
    for (const string& str : strs) {
        unordered_map<char, int> m;
        for (const char& i : str) {
            if (m.find(i) != m.end()) {
                m[i]++;
            } else {
                m[i] = 1;
            }
        }
        vector<pair<char, int>> data;
        for (auto i = m.begin(); i != m.end(); ++i) {
            data.push_back(make_pair(i->first, i->second));
        }
        sort(data.begin(), data.end(), compare());
        int out = 0;
        for (int i = 0, quality = 26; i < data.size(); i++, quality--) {
            out += (data[i].second * quality);
        }
        outs.push_back(out);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int i : s.outs) {
        os << i << endl;
    }
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int n;
    is >> n;
    s.strs.clear();
    for (size_t i = 0; i < n; i++) {
        string str;
        is >> str;
        s.strs.push_back(str);
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
