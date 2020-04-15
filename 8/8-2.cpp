/**
 * 从1开始深度优先遍历，找到1时返回
 * 
 * 运行时间：135ms
 * 占用内存：9800k
*/
#include <vector>
#include <string>
#include <iostream>
#include <stack>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::stack;

struct Point;
class Solution;
struct Point {
	int x;
	int y;
    Point(int x, int y): x(x), y(y) {}
};


class Solution {
private:
    vector<vector<int>> map; // map[i] 表示与i所有邻接的顶点
    vector<bool> isVisted; // isVisted[i] 表示节点[i] 是否已访问
public:
    /**
     * 能回到1号点返回 Yes，否则返回 No
     * @param param int整型vector param[0] 为 n，param[1] 为 m
     * @param edge Point类vector Point.x , Point.y 分别为一条边的两个点
     * @return string字符串
     */
    string solve(vector<int>& param, vector<Point>& edge);
    void edge2map(const vector<Point>& edge);
    bool DFS(int start);
};


string Solution::solve(vector<int>& param, vector<Point>& edge) {
    map.resize(param[0]+1);
    isVisted.resize(param[0]+1, false);
    edge2map(edge);
    if (DFS(1)) {
        return "Yes";
    } else {
        return "No";
    }
}

void Solution::edge2map(const vector<Point>& edge) {
    for(Point i : edge) {
        map[i.x].push_back(i.y);
        map[i.y].push_back(i.x);
    }
}

bool Solution::DFS(int start) {
    stack<int> s_point;
    s_point.push(start);
    isVisted[start] = true;
    int pre = 0;
    stack<int> s_pre;
    s_pre.push(pre);
    while (!s_point.empty()) {
        // 栈非空时
        int cur = s_point.top();
        s_point.pop();
        pre = s_pre.top();
        s_pre.pop();
        isVisted[cur] = true;
        for (int i: map[cur]) {
            if (i == pre) {
                continue;
            }
            if (i == start) {
                return true;
            }
            if (isVisted[i] == false) {
                // 当前节点的下一个节点仍未访问时
                s_point.push(i);
                s_pre.push(cur);
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    Solution s;

    // vector<int> param = {4,4};
    // vector<Point> edge = {Point(1,2), Point(2, 3), Point(3,4), Point(4,1)};
    
    vector<int> param = {5,5};
    vector<Point> edge = {Point(1,2), Point(2,3),Point(3,4), Point(4,5), Point(5,2)};

    // vector<int> param = {7,11};
    // vector<Point> edge = {Point(3,2), Point(5,1),Point(1,6), Point(6,4), Point(7,2), Point(7,4), Point(4,2), Point(1,3),Point(6,3), Point(3,7), Point(5,6)};

    cout << s.solve(param, edge) << endl;
    return 0;
}
