#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int x, y, z;
    int& row1 = x;
    int& column1 = y;
    int& row2 = y;
    int& column2 = z;
    int& row3 = x;
    int& column3 = z;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<vector<int>> out;

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
    out.clear();
    out.resize(row3, vector<int>(column3, 0));

    for (size_t i = 0; i < row3; i++) {
        for (size_t j = 0; j < column3; j++) {
            for (size_t k = 0; k < column1; k++) {
                out[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (size_t i = 0; i < s.row3; i++) {
        os << s.out[i][0];
        for (size_t j = 1; j < s.column3; j++) {
            os << " " << s.out[i][j];
        }
        os << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    is >> s.x >> s.y >> s.z;
    s.matrix1.clear();
    s.matrix2.clear();
    s.matrix1.resize(s.row1, vector<int>(s.column1, 0));
    s.matrix2.resize(s.row2, vector<int>(s.column2, 0));
    for (size_t i = 0; i < s.row1; i++) {
        for (size_t j = 0; j < s.column1; j++) {
            is >> s.matrix1[i][j];
        }
    }

    for (size_t i = 0; i < s.row2; i++) {
        for (size_t j = 0; j < s.column2; j++) {
            is >> s.matrix2[i][j];
        }
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
