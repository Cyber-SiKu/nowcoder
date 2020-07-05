/**
 * 算法思想：
 *  因为颜色是二异的所以从假定 1 节点为黑 然后邻接的是白颜色
 *  白颜色邻接的是黑颜色，依次类推直到所有的节点染色或者出现冲突
 * 
 * 
 * 运行时间：3ms
 * 占用内存：376k
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string outs;
    const int black = 1;
    const int white = 1;
    const int nocolor = 0;

public:
    Solution(const vector<vector<int>>& map);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
};

Solution::Solution(const vector<vector<int>>& map)
{
    outs = "Yes";

    // 保存其子的颜色 黑 1 白 -1 未染色 0
    vector<int> color(map.size(), this->nocolor);
    for (size_t i = 1, e = map.size(); i < e; i++) {
        if (color[i] != this->nocolor) {
            // i 节点与其邻接节点已经上色，跳过
            continue;
        }

        // 节点尚未上色
        color[i] = this->black;
        queue<int> q_points;
        q_points.push(i);

        while (!q_points.empty()) {
            /* 非空时 */
            int pos = q_points.front();
            q_points.pop();

            int tmp_color = color[pos] * (-1);

            // pos 的邻接点
            for (const int& j : map[pos]) {
                if (color[j] == tmp_color * (-1)) {
                    /* 上色颜色与原有颜色相反 */
                    outs = "No";
                    return;
                } else if (color[j] == this->nocolor) {
                    // 未上色
                    color[j] = tmp_color;
                    q_points.push(j);
                }
            }
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.outs;
    return os;
}

int main(int argc, char* argv[])
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N + 1); // map[i] 保存与 i 邻接的节点
    for (size_t i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }

    Solution s(map);

    cout << s << endl;
    return 0;
}