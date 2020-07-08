#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAXSIZE = 10000;
class Solution {
private:
    int out;
    int map[MAXSIZE][MAXSIZE];
    int man_number;
    int woman_number;

public:
    Solution(const vector<vector<int>>& man, const vector<vector<int>>& woman);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    void translate2Matrix(const vector<vector<int>>& man, const vector<vector<int>>& woman);
};

Solution::Solution(const vector<vector<int>>& man, const vector<vector<int>>& woman)
    : man_number(man.size())
    , woman_number(woman.size())
{
    memset(this->map, 0, sizeof(this->map));
    translate2Matrix(man, woman);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}

void Solution::translate2Matrix(const vector<vector<int>>& man, const vector<vector<int>>& woman)
{
    for (size_t i = 0, e_i = man.size(); i < e_i; ++i) {
        for (size_t j = 0, e_j = man[i].size(); j < e_j; ++j) {
            this->map[i][j]++;
        }
    }

    for (size_t i = 0, e_i = woman.size(); i < e_i; ++i) {
        for (size_t j = 0, e_j = woman[i].size(); j < e_j; ++j) {
            this->map[j][i]++;
        }
    }
}

int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> man(n);
    for (size_t i = 0; i < n; i++) {
        int k;
        cin >> k;
        man[i].resize(k, 0);
        for (size_t j = 0; j < k; j++) {
            cin >> man[i][j];
            man[i][j]--;
        }
    }

    vector<vector<int>> woman(m);
    for (size_t i = 0; i < m; i++) {
        int k;
        cin >> k;
        woman[i].resize(k, 0);
        for (size_t j = 0; j < k; j++) {
            cin >> woman[i][j];
            woman[i][j]--;
        }
    }

    Solution s(man, woman);

    cout << s << endl;
    return 0;
}