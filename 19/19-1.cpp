/**
 * 算法思想：
 * 枚举，挨个计算与其他数冲突最多的数依次删除
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> S;
    int K;

    // conflict[i] 表示与第i个数冲突的数的位置组成的数组
    vector<vector<int>> conflict;

    // del[i] 表示 第 i 个数是否被删除
    vector<bool> del;

    // 保存被删除数的下标
    vector<int> recycle;

public:
    Solution(const vector<int>& S, int K);
    ~Solution();
    int slove();

    // 返回与其他数冲突最多的数的位置
    int max_conflict(const vector<int>& S);

    // 返回 a 和 b是否冲突
    bool is_conflict(int a, int b);
};

Solution::Solution(const vector<int>& S, int K)
    : S(S)
    , K(K)
    , conflict(S.size())
    , del(S.size(), false)
{
    for (size_t i = 0, e_i = S.size(); i < e_i; i++) {
        for (size_t j = i + 1, e_j = S.size(); j < e_j; j++) {
            if (this->is_conflict(S[i], S[j])) {
                // S[i] S[j] 存在冲突
                this->conflict[i].push_back(j);
                this->conflict[j].push_back(i);
            }
        }
    }
}

Solution::~Solution()
{
}

int Solution::slove()
{
    int max_con_pos;
    while ((max_con_pos = this->max_conflict(S)) != -1) {
        int conflict_number = conflict[max_con_pos].size();
        // 当前数组仍存在冲突, 删除冲突最多的数
        recycle.push_back(max_con_pos);
        del[max_con_pos] = true; // 标记冲突最多的数为以删除
        for (const int& i : this->conflict[max_con_pos]) {
            // 与冲突最多的数的冲突中删除冲突最多的数
            this->conflict[i].erase(remove(this->conflict[i].begin(), this->conflict[i].end(), max_con_pos), this->conflict[i].end());
        }
    }

    return this->S.size() - this->recycle.size();
}

int Solution::max_conflict(const vector<int>& S)
{
    int pos = -1;
    int max = 0;
    for (size_t i = 0, e = S.size(); i < e; i++) {
        if (del[i] == false && (max < conflict[i].size())) {
            // 第 i 个数没有被删除，并且与它冲突的数比标杆多
            max = conflict[i].size();
            pos = i;
        }
    }
    return pos;
}

bool Solution::is_conflict(int a, int b)
{
    bool ret;
    if ((a + b) % K == 0) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int N, K;
    cin >> N >> K;
    vector<int> S(N);
    for (size_t i = 0; i < N; i++) {
        cin >> S[i];
    }
    Solution s(S, K);
    cout << s.slove() << endl;

    return 0;
}