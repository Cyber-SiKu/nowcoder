#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> M >> N;
    vector<int> data(N);
    for (int i = 0; i < N; ++i) {
        cin >> data[i];
    }

    unordered_map<int, int> dp;
    for (int i = 0; i < N; ++i) {
        unordered_map<int, int> tmp(dp);
        dp[data[i]] = 1;
        for (auto j : tmp) {
            if (dp.find(data[i] + j.first) == dp.end()) {
                dp[data[i] + j.first] = j.second + 1;
            } else {
                dp[data[i] + j.first] = min(dp[data[i] + j.first], j.second + 1);
            }
        }
    }
    if (dp.find(M) != dp.end()) {
        cout << dp[M] << endl;
    } else {
        cout << 0 << endl;

    }
    return 0;
}
