#include <cstring>
#include <iostream>

using namespace std;
const int MAXSIZE = 100 + 1;

class Solution {
private:
    int n;
    int matrix[MAXSIZE][MAXSIZE];

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
    memset(matrix, 0, sizeof(matrix));
    int tmp = 1;
    for (int k = 0; k < n; k++) {
        for (int i = k, j = 0; j <= k && i >= 0; j++, i--) {
            matrix[i][j] = tmp++;
        }
    }
}

ostream&
operator<<(ostream& os, const Solution& s)
{
    for (size_t i = 0; i < s.n; i++) {
        os << s.matrix[i][0];
        for (size_t j = 1; j < s.n - i; j++) {
            os << " " << s.matrix[i][j];
        }
        os << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.n;
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
