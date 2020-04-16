/*
暴力算法
FIX：内存过大
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const int MAXSIZE = (10e9)+1;
const int MAGICNUMBER = 1000000007;

class Solution {
private:
    vector<int> fb = {0, 1, 1}; // fb[i] // 表示斐波那契数列第i项
    vector<int> sum_fb = {0, 1, 2}; // 斐波那契数列前n项和
    vector<int> ssum_fb = {0, 1, 3}; // sum_fb前n项和
    vector<int> sssum_fb = {0, 1, 4}; // ssum_fb前n项和
public:
    /**
     * 
     * @param n int整型 
     * @return int整型
     */
    int getSum(int n);
    int fibo(int n);
    int sumFibo(int n);
    int sumSumFibo(int n);
    int sumSumSumFibo(int n);
    void init(int n) {
        fb.resize(n+1, 0);
        sum_fb.resize(n+1, 0);
        ssum_fb.resize(n+1, 0);
        sssum_fb.resize(n+1, 0);
    }
};

int Solution::getSum(int n) {
    return sumSumSumFibo(n);
}

int Solution::fibo(int n) {
    if (fb[n] != 0) {
        return fb[n] % MAGICNUMBER;
    }
    int ret = (fibo(n-1) + fibo(n-2)) % MAGICNUMBER;
    fb[n] = ret;
    return ret;
}
int Solution::sumFibo(int n ) {
    if (sum_fb[n] != 0) {
        return sum_fb[n] % MAGICNUMBER;
    }
    
    int ret = (fibo(n) + sumFibo(n-1)) % MAGICNUMBER;
    sum_fb[n] = ret;
    return ret;
}

int Solution::sumSumFibo(int n) {
    if (ssum_fb[n]!= 0) {
        return ssum_fb[n];
    }
    int ret  = (sumFibo(n) + sumSumFibo(n-1)) % MAGICNUMBER;
    ssum_fb[n] = ret;
    return ret;
}

int Solution::sumSumSumFibo(int n) {
    if (sssum_fb[n] != 0) {
        return sssum_fb[n];
    }
    int ret = (sumSumFibo(n) + sumSumSumFibo(n-1)) % MAGICNUMBER;
    sssum_fb[n] = ret;
    return ret;
}

int main(int argc, char *argv[]) {
    Solution s;

    // cout << s.getSum(1); // 1
    // cout << s.getSum(2); // 4
    
    cout << s.getSum(123) << endl; // 461485937

    return 0;
}