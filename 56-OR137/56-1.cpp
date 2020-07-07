#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int out;

public:
    Solution(const vector<vector<int>>& man, const vector<vector<int>>& woman);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<vector<int>>& man, const vector<vector<int>>& woman)
{
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
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