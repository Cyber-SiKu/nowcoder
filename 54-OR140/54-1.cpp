/**
 * 运行时间：42ms
 * 占用内存：5912k
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
    const int MAXSIZE = 1000000;

public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    int get_a_pos(const int& pos);
};

Solution::Solution(const vector<int>& data)
{
    a.resize(MAXSIZE, -1);
    a[1] = 1, a[2] = 2;
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
        os << i << endl;
    }

    return os;
}

int Solution::get_a_pos(const int& pos)
{
    int ret = 0;
    if (this->a[pos] == -1) {
        ret = (2 * get_a_pos(pos - 1) + get_a_pos(pos - 2)) % this->MOD;
        a[pos] = ret;
    } else {
        ret = a[pos];
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> data(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> data[i];
    }

    Solution s(data);

    cout << s;
    return 0;
}