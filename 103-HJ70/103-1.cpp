#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    vector<pair<int, int>> matrix;
    int out;
    string formula;

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
    out = 0;
    pair<int, int> tmp;
    stack<pair<int, int>> s_ans;
    for (size_t i = 0; i < formula.size(); i++) {
        if (formula[i] == '(' || formula[i] == ')') {
            if (tmp.first == 0 && tmp.second == 0) {
                continue;
            }
            s_ans.push(tmp);
            tmp.first = tmp.second = 0;
            continue;
        } else {
            // formula[i] != '(' && formula[i] != ')'
            int pos = formula[i] - 'A';
            if (tmp.first == 0 && tmp.second == 0) {
                tmp.first = matrix[pos].first;
                tmp.second = matrix[pos].second;
            } else {
                out += (tmp.first * matrix[pos].second * tmp.second);
                tmp.second = matrix[pos].second;
            }
        }
    }

    vector<pair<int, int>> left;
    while (!s_ans.empty()) {
        left.push_back(s_ans.top());
        s_ans.pop();
    }

    for (size_t i = 0; i < left.size(); i++) {
        if (i == 0) {
            tmp = left[i];
        } else {
            out += (left[i].first * tmp.second * left[i].second);
            tmp.first = left[i].first;
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int n, x, y;
    is >> n;
    s.matrix.clear();
    for (size_t i = 0; i < n; i++) {
        is >> x >> y;
        s.matrix.push_back(make_pair(x, y));
    }
    is >> s.formula;
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
