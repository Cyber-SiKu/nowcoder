#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> in;
    map<int, int> out;

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
    for (vector<pair<int, int>>::const_iterator i = in.cbegin(); i != in.cend(); i++) {
        if (out.find(i->first) != out.end()) {
            out[i->first] += i->second;
        } else {
            out.insert(make_pair(i->first, i->second));
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (map<int, int>::const_iterator i = s.out.cbegin(); i != s.out.cend(); ++i) {
        os << i->first << " " << i->second << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int n;
    is >> n;
    for (size_t i = 0; i < n; i++) {
        int index, value;
        is >> index >> value;
        s.in.push_back(make_pair(index, value));
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
