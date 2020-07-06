/**
 * 算法优化：
 *  改递归为迭代
 *  改cin cout --> printf scanf
 * 
 * 运行时间：运行时间：9ms
 * 占用内存：928k
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    /* data */
    const int MOD = 32767;
    vector<int> a; // 数列
    vector<int> outs;
    // const int MAXSIZE = 1000000;

public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    int get_a_pos(const int& pos);
};

Solution::Solution(const vector<int>& data)
    : a { 0, 1, 2 }
{
    for (const int& i : data) {
        this->outs.push_back(this->get_a_pos(i));
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.outs) {
        // os << i << endl;
        printf("%d\n", i);
    }

    return os;
}

int Solution::get_a_pos(const int& pos)
{
    if (this->a.size() > pos) {
        return this->a[pos];
    }

    // 尚未计算到pos
    for (int i = a.size(); i <= pos; i++) {
        int tmp = (2 * a[i - 1] + a[i - 2]) % this->MOD;
        a.push_back(tmp);
    }

    return a[pos];
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> data(n, 0);
    for (size_t i = 0; i < n; i++) {
        // cin >> data[i];
        scanf("%d", &data[i]);
    }

    Solution s(data);

    cout << s;
    return 0;
}