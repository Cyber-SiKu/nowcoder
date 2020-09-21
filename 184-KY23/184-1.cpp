#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> L(3);
    while (cin >> L[0]) {
        for (size_t i = 1; i < 3; i++) {
            cin >> L[i];
        }

        vector<int> C(3);
        for (size_t i = 0; i < 3; i++) {
            cin >> C[i];
        }

        int A, B;
        cin >> A >> B;
        int N;
        cin >> N;
        vector<int> map(N);
        for (size_t i = 0; i < N; i++) {
            cin >> map[i];
        }
    }

    return 0;
}