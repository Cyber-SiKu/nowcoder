/*
算法思想:
    递归：
    假设有1..n-1排列 p'[], $\sum_{i=1}^{n-2}(s(p[i], p[i+!]))$最大
    则选择一个位置插入n即可
*/

#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <list>
#include <iostream>
#include <array>
#include <map>

using std::vector;
using std::pair;
using std::iterator;
using std::min;
using std::list;
using std::max_element;
using std::cout;
using std::endl;
using std::array;
using std::map;

using llong = long long;
using pathvector = vector<vector<pair<int, llong>>>;
using pill = pair<int, llong>;
using veclliter = vector<llong>::iterator;
using liiter = list<int>::iterator;
using mimil = map<int, map<int, llong>>;

class Solution {
private:
    pathvector path;
    list<int> p; // 保存排列
    mimil S; // 用来存储s(x, y)的值
public:
    /**
     * @param n int整型 
     * @param seed1 long长整型 
     * @param seed2 long长整型 
     * @param seed3 long长整型 
     * @return long long长整型
     */
    llong work(int n, llong seed1, llong seed2, llong seed3);
    
    /**
     * x到y路径上边权值最小值
     * 不存在则返回 0
     * @param x int 整型 
     * @param y int 长整型 
     */
    llong s(int x, int y);

    /**
     * 对数据初始化
     * @param n int整型 
     * @param seed1 long长整型 
     * @param seed2 long长整型 
     * @param seed3 long长整型 
     * @return void
     */
   void init(int n, llong seed1, llong seed2, llong seed3);

    /**
     * 返回 $\sum_{i=1}^{n-2}(s(p[i], p[i+!]))$最大值
     * @param n int整型 
     * @return long长整型
     */
   llong sumsp(int n);
   llong sumsp(int n, int m);
};

int main(int argc, char *argv[]) {
    // int input[] = {3, 6, 7, 5};
    // Solution s;
    // llong ans = s.work(input[0], input[1],input[2],input[3]);
    // cout << ans << endl;

    int input[] = {4, 3, 9, 6};
    Solution s;
    llong ans = s.work(input[0], input[1],input[2],input[3]);
    cout << ans << endl;
    return 0;
}

llong Solution::work(int n, llong seed1, llong seed2, llong seed3) {
    // write code here
    init(n, seed1, seed2, seed3);
    return sumsp(n);
}

void Solution::init(int n, llong seed1, llong seed2, llong seed3) {
    llong seed4 = 0;
    path.resize(n);
    // p.resize(n);
    int u,v;
    llong w;
    for (int i = 1; i <= n-1; i++) {
        seed4 = ((seed1 + seed2) % 998244353)* seed3 % 998244353;
        u = i;
        v = seed4 % i;
        w = seed2 * seed3 % 12131415;
        path[u].push_back({v, w});
        path[v].push_back({u, w});
        S[u][v] = S[v][u] = w;
        seed3 = seed2;
        seed2 = seed1;
        seed1 = seed4;
    }
}

llong Solution::s(int x, int y) {
    /*
    根据 s(x,y)的定义：
        1. 若x到y不存在的路径设定为0
        2. 若x到y存在路径且路径唯一(树状结构)，假设路径为x，i，...，y
            则s(x, y) = min(d(x,i), s(i, y))
            其中d(x,y)为x到邻接节点y的边权
    */
    if (S[x][y] != 0) {
        // 已经计算过 S(x, y)
        // 或者x, y相邻
        return S[x][y];
    }
    if (path[x].size() == 0) {
        // x 是叶子节点
        return 0;
    }
    // 从与x邻接的点中单项寻找路径(因为是树，所以有且仅有一条)
    for (pill i :  path[x]) {
        llong tmp = s(i.first, y);
        if (tmp != 0) {
            // 找不到路径的都为0且路径唯一
            S[i.first][y] = tmp;
            S[x][y] =  min(i.second, tmp); // 根据定义
            break;
        }
    }

    // 找到路径或者没有路径
    return S[x][y];
}

llong Solution::sumsp(int n) {
    /**
     * 
    */
    if (n == 2) {
        // 仅有两个元素 找到边权最大的边即可
        llong tmp = s(0, 1);
        p.push_back(0);
        p.push_back(1);
        return tmp;
    }

    llong pre_value = sumsp(n-1);
    // 在头部插入的话
    liiter i = p.begin();
    llong max = s(n-1, *i) + pre_value;
    liiter posi = i;
    liiter pre = i;
    i++;
    for (liiter e = p.end(); i != e; i++) {
        // 在 pre 和 i之前插入 n
        llong tmp = pre_value \
            - s(*pre, *i) \
            + s(*pre, n-1) + s(n-1, *i);
        if (tmp > max) {
            max = tmp;
            posi = i;
        }
        pre = i;
    }
    p.insert(posi, n);
    return max;
}

llong Solution::sumsp(int n, int m) {
    llong pre_value = 0;
    for (int i = 1; i < n; ++i) {}
}