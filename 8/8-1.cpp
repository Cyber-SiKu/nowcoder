#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

struct Point {
	int x;
	int y;
    Point(int x, int y): x(x), y(y) {}
};


class Solution {
public:
    /**
     * 能回到1号点返回 Yes，否则返回 No
     * @param param int整型vector param[0] 为 n，param[1] 为 m
     * @param edge Point类vector Point.x , Point.y 分别为一条边的两个点
     * @return string字符串
     */
    string solve(vector<int>& param, vector<Point>& edge) {
        // write code here
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    vector<int> param = {4,4};
    vector<Point> edge = {Point(1,2), Point(2, 3), Point(3,4), Point(4,1)};
    cout << s.solve(param, edge) << endl;
    return 0;
}