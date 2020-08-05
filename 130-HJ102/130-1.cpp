#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
};

class Solution {
private:
    string input;
    vector<char> output;

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
    output.clear();
    unordered_map<char, int> char_count;

    for (size_t i = 0; i < input.size(); i++) {
        if (char_count.find(input[i]) == char_count.end()) {
            char_count[input[i]] = 1;
        } else {
            char_count[input[i]]++;
        }
    }

    set<pair<char, int>, compare> sort;
    for (const pair<char, int>& i : char_count) {
        sort.insert(i);
    }

    for (const pair<char, int>& i : sort) {
        output.push_back(i.first);
    }
}

ostream&
operator<<(ostream& os, const Solution& s)
{
    for (const char& i : s.output) {
        os << i;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    getline(is, s.input);
    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    while (cin >> s) {
        s.slove();
        cout << s << endl;
    }
    return 0;
}
