#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MAXSZIE = 2000 + 1;

class Solution {
private:
    const int breadPos = 0;
    const int breveragePos = 1;
    const int moneyPos = 1;
    int data[MAXSZIE][MAXSZIE];

public:
    /**
     * 
     * @param breadNum int整型 
     * @param beverageNum int整型 
     * @param packageSum int整型vector<vector<>> 每个一维数组中有三个数，依次表示这个包装里面的面包数量、饮料数量、花费
     * @return int整型
     */
    int minCost(int breadNum, int beverageNum, vector<vector<int>>& packageSum)
    {
        // write code here
        // 初始化
        memset(this->data, 0, sizeof(this->data));

        int pos_max = 0;
        for (size_t i = 0, e_i = packageSum.size(); i < e_i; i++) {
            data[0][packageSum[i][breveragePos]] = packageSum[i][moneyPos];
            if (packageSum[i][moneyPos] > packageSum[pos_max][moneyPos]) {
                pos_max = i;
            }
        }
        for (size_t i = pos_max, pre = pos_max; i > 0; i--) {
            if (data[0][i] == 0) {
                data[0][i] = data[0][pre];
            } else {
                pre = i;
            }
        }

        int sum_beverage = 0; // 已经购买饮料的数量
        for (size_t i = 0; i <= breadNum; i++) {
            for (size_t j = 0; j <= breveragePos; i++) {
                /* code */
            }
        }

        return data[breadNum][beverageNum];
    }
};

int main(int argc, char* argv[])
{
    int breadNum = 5, beverageNum = 60;
    vector<vector<int>> packageSum { { 3, 36, 120 }, { 10, 25, 129 }, { 5, 50, 250 }, { 1, 45, 130 }, { 4, 20, 119 } };
    Solution s;
    cout << s.minCost(breadNum, beverageNum, packageSum) << endl;
    return 0;
}
