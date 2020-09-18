#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    while (cin >> N) {
        vector<ll> data(N);
        for (int i = 0; i < N; ++i) {
            cin >> data[i];
        }
        int sum = 0, output = INT_MIN;
        for (int i = 0; i < N; ++i) {
            sum = max(sum+data[i], data[i]);
            output = max(output, sum);
        }
        cout << output << endl;
    }
    return 0;
}
