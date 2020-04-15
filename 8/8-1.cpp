/**
 * 从1开始广度优先遍历，找到1时返回
 * bug: 不宜使用广度优先，因为第一步和最后一步必然是邻接的点
*/
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::queue;

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
    string BFS(int start);
};


string Solution::solve(vector<int>& param, vector<Point>& edge) {
    map.resize(param[0]+1);
    isVisted.resize(param[0]+1, false);
    edge2map(edge);
    isVisted[1] = true;
    return BFS(1);
}

void Solution::edge2map(const vector<Point>& edge) {
    for(Point i : edge) {
        map[i.x].push_back(i.y);
        map[i.y].push_back(i.x);
    }
}

string Solution::BFS(int start) {
    queue<int> tmp;
    tmp.push(start);
    int pre = 0;
    while (!tmp.empty()) {
        /* 栈中仍有元素时 */
        int x = tmp.front();
        tmp.pop();
        isVisted[x] = true;
        for(int i : map[x]) {
            if(i == start) {
                // 可以从start 再回到start
                return "Yes";
            }
            if (isVisted[i] == false) {
                tmp.push(i);
            }
        }
    }
    return "No";
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
