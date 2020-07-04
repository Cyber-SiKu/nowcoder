#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> data;

public:
    Solution(const int& n, const int& m);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const int& n, const int& m)
    : data(n, vector<int>(m, 0))
{
    int max = n >= m ? n : m;
    int k = 1, end = n * m;
    while (k <= end) {
        int a = 0;
        for (; a < max; a++) {
            for (int i = 0, j = a; i <= a && j >= 0; i++, j--) {
                if (j > m || i > n) {
                    continue;
                } else {
                    data[i][j] = k;
                    k++;
                }
            }
        }
        a--;
        for (int b = 1; b < max; b++) {
            for (int i = b, j = a; i <= a && j >= 0; i++, j--) {
                if (j > m || i > n) {
                    continue;
                } else {
                    data[i][j] = k;
                    k++;
                }
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const vector<int>& i : s.data) {
        os << i[0];
        for (int j = 1, e_j = i.size(); j < e_j; j++) {
            os << " " << i[j];
        }
        os << " ";
    }

    return os;
}

int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;
    Solution s(n, m);

    cout << s << endl;
    return 0;
}