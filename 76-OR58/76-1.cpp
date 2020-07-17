#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Stones {
public:
    vector<int> result(int A, int B, int n, vector<int> e, vector<int> a)
    {
        // write code here

        // 初始表示什么也不买
        int score_A[2][n + 1]; // score[0][i] A买i时A最高得分， score[1][i]B买i时A最高得分
        int left_power_A[2][n + 1]; // left_power[0][i] A买i时A剩余能量， left_power[1][i]B买i时A剩余能量
        int score_B[2][n + 1]; // score[0][i] B买i时B最高得分， score[1][i]A买i时B最高得分
        int left_power_B[2][n + 1]; // left_power[0][i] B买i时B剩余能量， left_power[1][i]A买i时B剩余能量
        memset(score_A, 0, sizeof(score_A));
        memset(left_power_A, 0, sizeof(left_power_A));
        memset(score_B, 0, sizeof(score_B));
        memset(left_power_B, 0, sizeof(left_power_B));
        left_power_A[0][0] = A;
        left_power_A[0][1] = A;
        left_power_B[0][0] = B;
        left_power_B[0][1] = B;

        for (size_t i = 1; i <= n; i++) {
            // 如果 A 购买了本次的
            // B 购买上次，或者A购买上次B，跳过本次
            if (score_A[0][i - 1] > score_A[1][i - 1]) {
            }

            // 如果 A 跳过, B 购买上次的
            score_A[1][i];
            left_power_A[0][i];

            // 如果 B 购买了本次 // 要么是 A 跳过 要么是A购买了上次的
        }
    }
};

int main(int argc, char* argv[])
{
    int A = 9, B = 0, n = 7;
    vector<vector<int>> data { { 66, 2, 6, 2, 8, 4, 3 }, { 7, 12, 65, 7, 4, 40, 15 } };

    vector<int> outs = Stones().result(A, B, n, data[0], data[1]);

    for (const int& i : outs) {
        cout << i << endl;
    }

    return 0;
}
