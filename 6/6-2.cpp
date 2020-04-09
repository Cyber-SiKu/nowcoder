/*
算法思想:
    递归：
    假设有1..n-1排列 p'[], $\sum_{i=1}^{n-2}(s(p[i], p[i+!]))$最大
    则选择一个位置插入n即可
*/

#include <iostream>

using std::cout;
using std::endl;

using llong = long long;

class Solution {
private:
public:
    /**
     * @param n int整型 
     * @param seed1 long长整型 
     * @param seed2 long长整型 
     * @param seed3 long长整型 
     * @return long long长整型
     */
    llong work(int n, llong seed1, llong seed2, llong seed3);
};

int main(int argc, char *argv[]) {
    // int input[] = {3, 6, 7, 5};
    // Solution s;
    // llong ans = s.work(input[0], input[1],input[2],input[3]);
    // cout << ans << endl;

    int input[] = {4, 3, 9, 6};
    Solution s;
    llong ans = s.work(input[0], input[1],input[2],input[3]);
    cout << ans << endl;
    return 0;
}

llong Solution::work(int n, llong seed1, llong seed2, llong seed3) {
    // write code here
    long long sum=0;
        for(int i=1;i<n;i++){
            long long seed4=((seed1+seed2)%998244353)*seed3%998244353;
            sum+=(seed2*seed3%12131415);
            seed3=seed2;
            seed2=seed1;
            seed1=seed4;
             
        }
        return sum;
}
