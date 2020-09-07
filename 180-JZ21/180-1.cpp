#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int j = 0;
        for (int i = 0; i < pushV.size();) {
            if (!s.empty() && s.top() == popV[j]) {
                s.pop();
                ++j;
            } else {
                s.push(pushV[i]);
                ++i;
            }
        }
        while (!s.empty() && s.top() == popV[j]) {
            s.pop();
            ++j;
        }
        return s.empty();
    }
};

int main() {
    vector<int> pushV {1,2,3,4,5};
    vector<int> popV {4,3,5,1,2};
    cout << Solution().IsPopOrder(pushV, popV) << endl;
    return 0;
}
