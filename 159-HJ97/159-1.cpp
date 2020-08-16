#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int count = 0;
        vector<int> data;
        for (size_t i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp < 0) {
                count++;
            } else if (tmp > 0) {
                data.push_back(tmp);
            }
        }
        // cout << count << " " << double(accumulate(data.begin(), data.end(), 0) / double(data.size())) << endl;
        printf("%d %0.1f\n", count, double(accumulate(data.begin(), data.end(), 0) / double(data.size())));
    }

    return 0;
}