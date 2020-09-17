#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, M;
    cin >> T >> M;
    vector<pair<int, int>> data(M);
    for (int i = 0; i < M; ++i) {
        cin >> data[i].first >> data[i].second;
    }
    sort(data.begin(), data.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
    int max_value = 0;
    map<int, int> time2value;
    vector<int> dp(T + 1, 0);
    for (int i = 0; i < M; ++i) {
        for (int j = T; j >= data[i].first; --j) {
            dp[j] = max(dp[j], dp[j - data[i].first] + data[i].second);
        }
    }
    cout << dp[T] << endl;
    return 0;
}
