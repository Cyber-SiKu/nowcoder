#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> tmp;
        do {
            tmp.insert(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return vector<vector<int>>(tmp);
    }
};