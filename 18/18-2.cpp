/*
* 算法思想：
穷举算法，挨个试
*/

/*
运行时间：4ms

占用内存：484k
*/

#include <algorithm>
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

    // 将数组分为 xiao_ai xiao_xi 两部分 返回最小偏差
    int parting();

    int slove();

    // f返回分配偏差
    int f(const vector<int>& xiao_ai, const vector<int>& xiao_xi);

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
    return this->parting();
}

int Solution::f(const vector<int>& xiao_ai, const vector<int>& xiao_xi)
{
    int ret = 0;
    for (const int& i : xiao_ai) {
        for (const int& j : xiao_xi) {
            ret += abs(i - j);
        }
    }
    return ret;
}

int Solution::parting()
{
    for (size_t i = 0; i < K; i++) {
        xiao_ai.push_back(all[i]);
    }

    for (size_t i = K, e = this->all.size(); i < e; i++) {
        xiao_xi.push_back(all[i]);
    }

    int min = this->f(xiao_ai, xiao_xi);

    for (size_t i = 0, e_i = xiao_xi.size(); i < e_i; i++) {
        for (size_t j = 0, e_j = xiao_ai.size(); j < e_j; j++) {
            /* xiao_xi元素挨个替换xiao_ai中的元素 */
            vector<int> xiao_ai_(xiao_ai);
            vector<int> xiao_xi_(xiao_xi);

            // 交换数据
            int tmp = xiao_ai_[j];
            xiao_ai_[j] = xiao_xi_[i];
            xiao_xi_[i] = tmp;

            int ans = this->f(xiao_ai_, xiao_xi_);

            if (min > ans) {
                // 交换后结果更小
                xiao_ai = xiao_ai_;
                xiao_xi = xiao_xi_;
                min = ans;
            }
        }
    }
    return min;
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