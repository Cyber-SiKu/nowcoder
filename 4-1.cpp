/*
算法思路：
维护一个感染范围，每检查一个感染人根据她的形成更新这个范围
Bug : 算法时间复杂度过大
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
    Range = PeoplePosition[Personid-1]; //  将感染者初始化为第一个确认者的活动范围
    PeoplePosition.erase(PeoplePosition.begin()+Personid-1); // 删除第一个确认者
    int Infected; // 保存感染者的人数
    Infected = 1;
    for (size_t i = 0; i < PeoplePosition.size(); i++) {
        if (InRange(i, PeoplePosition, Range)) { 
            // 第 i 在感染范围之内
            ++Infected;
            int chnaged = UpdateRange(Range, PeoplePosition[i]);
            PeoplePosition.erase(PeoplePosition.begin()+i); // 删除确认者
            if (chnaged != 0) {
                // 感染范围未发生变化
                i = 0; // 重新开始排查感染者
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