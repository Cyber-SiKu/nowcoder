/*
* 算法思想：
小爱拿的数应该是最接近平均数的数
*/

// #include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> all;
    int K;
    vector<int> xiao_ai;
    vector<int> xiao_xi;

public:
    Solution(const vector<int>& all, int K);
    ~Solution();

    // 返回平均数
    int get_means(const vector<int>& all);

    // 将数组分为 xiao_ai xiao_xi 两部分
    void parting();

    int slove();

    // f返回分配偏差
    int f();

    // 返回距posi最远元素下标
    int farthest(const vector<int>& vec, int pos);
};

Solution::Solution(const vector<int>& all, int K)
    : all(all)
    , K(K)
{
}

Solution::~Solution()
{
}

int Solution::get_means(const vector<int>& all)
{
    int ret = 0;
    int sum = accumulate(all.begin(), all.end(), 0);
    ret = round(sum / all.size()); // 四舍五入
    return ret;
}

int Solution::slove()
{
    this->parting();
    return this->f();
}

int Solution::f()
{
    int ret = 0;
    for (const int& i : xiao_ai) {
        for (const int& j : xiao_xi) {
            ret += abs(i - j);
        }
    }
    return ret;
}

void Solution::parting()
{
    int means = this->get_means(this->all);
    for (size_t i = 0; i < K; i++) {
        xiao_ai.push_back(all[i]);
    }

    for (size_t i = K, e = this->all.size(); i < e; i++) {
        size_t max_pos = farthest(xiao_ai, means);
        if (abs(all[i] - means) < abs(xiao_ai[max_pos] - means)) {
            // 当前元素all[i]比小爱中距离平均数最远的元素近
            xiao_xi.push_back(xiao_ai[max_pos]);
            xiao_ai[max_pos] = all[i];
        } else {
            xiao_xi.push_back(all[i]);
        }
    }
}

int Solution::farthest(const vector<int>& vec, int pos)
{
    int ret = 0;
    int max_len = abs(vec[ret] - pos);
    for (size_t i = 1, e = vec.size(); i < e; i++) {
        int len = abs(vec[i] - pos);
        if (len > max_len) {
            ret = i;
            max_len = len;
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int N, K;
    cin >> N >> K;
    vector<int> all(N);
    for (size_t i = 0; i < N; i++) {
        cin >> all[i];
    }
    Solution s(all, K);

    cout << s.slove() << endl;

    return 0;
}