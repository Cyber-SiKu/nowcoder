/**
 * 运行时间：2ms
 * 占用内存：376k
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minSun(vector<int>& quality);
};

vector<int> Solution::minSun(vector<int>& quality)
{
    if (quality.size() == 1) {
        vector<int> ret { quality[0], 0 };
        return ret;
    }

    int sum[2] = { 0, 0 };
    sort(quality.begin(), quality.end());
    int left = 0, right = quality.size() - 1;
    sum[0] = quality[left];
    sum[1] = quality[right];
    while (left < right) {
        if (sum[0] <= sum[1]) {
            left++;
            if (left < right) {
                sum[0] += quality[left];
            }
        } else {
            right--;
            if (left < right) {
                sum[1] += quality[right];
            }
        }
    }

    vector<int> ret;
    if (sum[0] > sum[1]) {
        ret.push_back(sum[0]);
        ret.push_back(sum[1]);
    } else {
        ret.push_back(sum[1]);
        ret.push_back(sum[0]);
    }

    return ret;
}

int main(int argc, char* argv[])
{
    // vector<int> quality { 5, 1, 1, 1, 1, 1 };

    vector<int> quality;
    int x;
    char y;
    while (cin >> x >> y) {
        quality.push_back(x);
    }
    cin >> x;
    quality.push_back(x);

    vector<int> outs = Solution().minSun(quality);
    cout << outs[0] << "," << outs[1] << endl;
    return 0;
}
