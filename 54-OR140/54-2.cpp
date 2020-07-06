/**
 * 算法优化：
 *  改递归为迭代
 * 
 * 
 * 运行时间：32ms
 * 占用内存：952k
*/
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MAXSIZE = 1000000 + 1;

class Solution {
private:
    /* data */
    const int MOD = 32767;
    int a[MAXSIZE]; // 数列
    int size; // 计算到哪个节点
    vector<int> outs;

public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    int get_a_pos(const int& pos);
};

Solution::Solution(const vector<int>& data)
{
    memset(this->a, -1, sizeof(a));
    a[1] = 1;
    a[2] = 2;
    this->size = 2;
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
    if (this->a[pos] != -1) {
        return this->a[pos];
    }

    // 尚未计算到pos
    for (int i = this->size + 1; i <= pos; i++) {
        int tmp = (2 * a[i - 1] + a[i - 2]) % this->MOD;
        a[i] = tmp;
    }
    size = pos;
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