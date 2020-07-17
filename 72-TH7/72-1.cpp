#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const int breadPos = 0;
    const int beveragePos = 1;
    const int moneyPos = 2;
    const int MAXSZIE = 200;

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

        int dp[MAXSZIE][MAXSZIE];
        memset(dp, 0x5f, sizeof(dp));
        dp[0][0] = 0;
        for (size_t i = 0; i < packageSum.size(); i++) {
            for (int j = breadNum; j >= 0; j--) {
                for (int k = beverageNum; k >= 0; k--) {
                    dp[j][k] = min(dp[j][k],
                        dp[max(j - packageSum[i][breadPos], 0)][max(k - packageSum[i][beveragePos], 0)]
                            + packageSum[i][moneyPos]);
                }
            }
        }

        return dp[breadNum][beverageNum];
    }
};

int main(int argc, char* argv[])
{
    int breadNum = 5, beverageNum = 60;
    vector<vector<int>> packageSum { { 3, 36, 120 }, { 10, 25, 129 }, { 5, 50, 250 }, { 1, 45, 130 }, { 4, 20, 119 } };
    // Solution s;
    cout << Solution().minCost(breadNum, beverageNum, packageSum) << endl;
    // cout << Solution1().minCost(breadNum, beverageNum, packageSum) << endl;
    return 0;
}
