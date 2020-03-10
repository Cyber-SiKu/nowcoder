/*
算法思路：
维护一个感染范围，每检查一个感染人根据她的形成更新这个范围
先根据 x 值将数组排列，根据感染者将数组分为左右两组
    左边根据 y 进行排列选取 y 最大的与感染范围的 x 比较，若大于更新感染范围，重复直至 x == 0 或者左边没有没有结点
    右边根据 x 与感染范围的 y 进行比较，若小于更新感染范围，重复至 x 小于 y或者 无节点
    PS:只有左边能更新x的范围

优化空间：初始的排序算法可以不采取全局的排序方法，直接采取类似快排的第一步，减少运行时间
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::find_if;
using std::iterator;

struct Point {
    int x;
    int y;
};

class Solution {
private:
public:
    /**
     * 
     * @param Personid int整型 Personid
     * @param PeoplePosition Point类vector PeoplePosition
     * @return int整型
     */
    Solution();
    int CatchVirus(int Personid, vector<Point>& PeoplePosition);
    void input(int& Personid, vector<Point>& PeoplePosition);
    void output();

    bool InRange(int PersonID, vector<Point>& PeoplePosition, Point& Range);
    // 返回 Pid的活动范围是否在感染范围
    
    int UpdateRange(Point& Range, const Point& infected_range);
    // 根据感染者的活动范围 infected 更新 range ,感染域未发生变化返回 0
};

int main(int argc, char ** argv) {
    Solution S;
    int Pid;
    vector<Point> Position;
    
    S.input(Pid, Position);
    int n = S.CatchVirus(Pid, Position);
    cout << n << endl;

    return 0;
}

Solution::Solution() {
}

void Solution::input(int& Personid, vector<Point>& PeoplePosition) {
    cin >> Personid;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        Point temp;
        cin >> temp.x >> temp.y;
        PeoplePosition.push_back(temp);
    }
}

void Solution::output() {
    // cout << " Pid:" << Pid << endl;
    // cout << "People Position:" << endl;
    // for (size_t i = 0, e =  PeoplePosition.size(); i < e; i++)
    // {
    //     cout << "(" << PeoplePosition[i].x << "," << PeoplePosition[i].y << ")" << endl;
    // }
    
}

int Solution::CatchVirus(int Personid, vector<Point>& PeoplePosition){
    Point Range;
    Range = PeoplePosition[Personid]; //  将感染者初始化为第一个确认者的活动范围
    int Infected; // 保存感染者的人数
    Infected = 1;
    
    sort(PeoplePosition.begin(), PeoplePosition.end(),[] (Point a, Point b) {
        return a.x < b.x;
    }); // 按 x 升序排序
    
    vector<Point>::iterator mid_pos = find_if(PeoplePosition.begin(), PeoplePosition.end(),[Range](Point a){
        return (a.x == Range.x && a.y == Range.y);
    }); // 获取感染者的位置

    if (mid_pos != PeoplePosition.begin()) {
        // 左边位置有元素
        sort(PeoplePosition.begin(), mid_pos,[] (Point a, Point b) {
            return a.y < b.y;
        }); // 左边按 y 升序排列
        while (PeoplePosition.begin() != mid_pos-Infected+1) { // 直到排查到起始位置
            if ((*(mid_pos-Infected)).y >= Range.x) {
                // 左边 y 最大的大于感染的 x 说明感染
                // 更新感染范围,增加感染者，
                UpdateRange(Range, *(mid_pos-Infected));
                ++Infected;
            } else {
                // 左边再无感染者
                break;
            }
        }
    }

    if (mid_pos != PeoplePosition.end()) {
        // 右边位置有元素
        int count = 0;
        while (PeoplePosition.end()-1 != mid_pos+count) { // 排查至最右边
            if ((*(mid_pos+count+1)).x <= Range.y ) {
                // 右边元素的 x 小于感染的 y 说明感染
                // 增加感染者，更新感染范围
                ++Infected;
                ++count;
                UpdateRange(Range, *(mid_pos+count));
            } else {
                // 右边再无感染者
                break;
            }
            
        }
        
    }

    return Infected;
}

bool Solution::InRange(int PersonID, vector<Point>& PeoplePosition, Point& Range) {
    bool ret = true;
    if (PeoplePosition[PersonID].y < Range.x || PeoplePosition[PersonID].x > Range.y) {
        // 当 PersonID 在感染范围之外
        ret = false;
    }
    return ret;
}

int Solution::UpdateRange(Point& Range, const Point& infected_range) {
    int ret = 0;
    if (Range.x > infected_range.x) {
        Range.x = infected_range.x;
        ret = -1;
    } 
    
    if (Range.y < infected_range.y) {
        Range.y = infected_range.y;
        ret = 1;
    }
    return ret;
}
