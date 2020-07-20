#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> triangle; // 保存三角形
    vector<int> pos; // 保存第一次出现偶数的位置
    vector<int> ins;
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
    triangle.push_back(vector<int>(1, 1));
    pos.push_back(-1);
    triangle.push_back(vector<int>(3, 1));
    pos.push_back(-1);
    for (const int& i : ins) {
        if (i < pos.size()) {
            // 已经计算过
            outs.push_back(pos[i]);
        } else {
            // 尚未计算
            size_t start = pos.size();
            triangle.resize(i + 1);
            pos.resize(i + 1, 0);

            for (size_t j = start; j <= i; j++) {
                // 第j行
                int pos_first = -1;
                int length = 2 * j + 1;
                triangle[j].resize(length, 0);
                for (size_t k = 0; k < length; k++) {
                    if (k == 0) {
                        triangle[j][k] = 1;
                    } else {
                        triangle[j][k] = (triangle[j - 1][k - 1] + triangle[j - 1][k] + triangle[j][k + 1]) % 2;
                        if (pos_first == -1 && triangle[j][k] == 0) {
                            pos_first = k;
                        }
                    }
                }
                pos[j] = pos_first;
            }
            outs.push_back(pos[i] + 1);
        }
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        os << i << endl;
    }

    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    int x;
    while (is >> x) {
        --x;
        s.ins.push_back(x);
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
