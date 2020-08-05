#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        vector<int> data(n, 0);
        for (size_t i = 0; i < n; i++) {
            cin >> data[i];
        }

        vector<int> dp(n, 0); // 保存从 i 开始最多走多少
        int max_step = 0;
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            int max_next_step_j = i;
            for (int j = i + 1; j < n; j++) {
                if (data[j] > data[i] && dp[max_next_step_j] < dp[j]) {
                    max_next_step_j = j;
                }
            }
            dp[i] = dp[max_next_step_j] + 1;
            max_step = max(max_step, dp[i]);
        }

        cout << max_step << endl;
    }
    return 0;
}