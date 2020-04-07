/*
算法：使用深度优先遍历数顶点
计算每个顶点数过的次数
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::pair;
using std::max;

class Solution;

using pij = pair<int, int>; // 
using llong = long long;
class Solution {
private:
    llong max_weight;
    int allcnt;
    vector<vector<pij>> matrix;
    
    vector<int> child_cnt;
public:
    /**
     * 
     * @param n int整型 城市个数
     * @param u int整型vector 
     * @param v int整型vector 
     * @param w int整型vector 
     * @return long长整型
     */
    llong solve(int n, vector<int>& u, vector<int>& v, vector<int>& w);
    void convert(int n, vector<int>& u, vector<int>& v, vector<int>& w);
    void dfs(int x, int j);
};


int main(int args, char* argv[]) {
    // 150
    int n = 5;
    vector<int> u = {1,4,5,4};
    vector<int> v = {5,1,2,3};
    vector<int> w = {9,25,30,8};

    // // 216
    // int n = 7;
    // vector<int> u = {7,1,4,6,5,3};
    // vector<int> v = {6,6,6,3,7,2};
    // vector<int> w = {8,15,36,9,30,3};

    Solution s;
    cout << s.solve(n, u, v, w) << endl;

    return 0;
}

void Solution::convert(int n, vector<int>& u, vector<int>& v, vector<int>& w) {
    for(int i = 0; i < n-2; ++i) {
        int temp_u = u[i], temp_v = v[i], temp_w = w[i];
        matrix[temp_u].push_back({temp_v, temp_w});
        matrix[temp_v].push_back({temp_u, temp_w});
    }
}

llong Solution::solve(int n, vector<int>& u, vector<int>& v, vector<int>& w) {
    allcnt = n;
    convert(n,u,v,w);
    dfs(1, 0); 
    return max_weight;
}


void Solution::dfs(int x, int j) {
    child_cnt[x] = 1;
    for (auto temp : matrix[x]) {
        int y = temp.first, w = temp.second;
        if (y == j) {
            continue;
        }
        dfs(y, x);

        child_cnt[x] += child_cnt[y];
        llong temp_weight = llong(w) * llong(allcnt - child_cnt[y])*llong(child_cnt[y]);
        max_weight = max(max_weight, temp_weight);
    }
    
}