/**
 * 算法思路：
 *  首先找到最长的路径
 *  记最长的路径长度为 2l
 *  则方案数量为((l!)^2)*2
 * 
 * 运行时间：2ms
 * 占用内存：348k
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> map;
    int out;

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
    int length = this->map.size();

    int max_length = 0;
    vector<int> path(length, 0); // path[i] 表示以 i 开头的最长路径长度
    for (size_t i = 1; i <= length; i++) {
        if (path[i] != 0) {
            // 已整理路径
            continue;
        }
        if (map[i] == 0) {
            path[i] = 1;
            continue;
        }
        // 有下一个结点
        stack<int> s;
        int next = map[i];
        while (path[next] == 0 && map[next] != 0) {
            /* 未计算出结点，并且未到达终点 */
            s.push(next);
            next = map[next];
        }
        if (path[next] == 0) {
            /* 到达终点 */
            path[next] = 1;
        }

        int now_length = path[next] + 1;
        while (!s.empty()) {
            int pos = s.top();
            s.pop();
            path[pos] = now_length++;
        }
        path[i] = now_length;
        if (now_length > max_length) {
            max_length = now_length;
        }
    }
    max_length /= 2;
    if (max_length % 2 == 1) {
        // 奇数可以后移一个结点
        out = 4;
    } else {
        out = 2;
    }

    for (size_t i = 2; i <= max_length; i++) {
        out *= (i * i);
    }
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}
istream& operator>>(istream& is, Solution& s)
{
    size_t n;
    is >> n;
    s.map.resize(n + 1, 0);
    for (size_t i = 0; i < n - 1; i++) {
        int x, y;
        is >> x >> y;
        s.map[x] = y;
    }

    return is;
}

int main(int argc, char* argv[])
{
    Solution s;
    cin >> s;
    s.slove();
    cout << s << endl;
    return 0;
}