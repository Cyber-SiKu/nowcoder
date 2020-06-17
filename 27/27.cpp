#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x, y, xlimit = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        xlimit = max(xlimit, y);
        f[x]++;
        f[y]--;
    }
    int maxi = 0, sum = 0;
    for (int i = 1; i <= xlimit; ++i) {
        sum += f[i];
        maxi = max(maxi, sum);
    }
    cout << maxi << endl;
}