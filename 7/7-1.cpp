/**
 * 时间复杂度过大
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::iterator;
using std::vector;
using std::generate;
using std::set;

using vecIIter = vector<int>::iterator;
using setIIter = set<int>::iterator;

#define MAXSIZE 100000000+1

class Solution {
private:
    int max = 3; // 记录已经筛选到的最大素数
    vector<int> noLessPrime = {1, 1, 2, 3}; // noLessPrime[i] 表示不小于i的最大质数
    vector<bool> isPrime = {true, true, true, true};
    vector<int> prime = {2,3}; // 存储已知的质数
public:
    /**
     * @param n int整型 
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @return int整型
     */
    int work(int n, int* a, int aLen);
    /**
     * 返回不低于 n 的最大质数
     * @param n int整型 
     * @return int整型
     */
    int get_prime(int n);
    /**
     * 返回距离为 n 时中间间隔车站的数量
     * @param len int整型 
     * @return int整型
     */
    int get_num_station(int len);
};

int main(int argc, char * argv[]) {
    int input[] = {3, 0, 7, 11}; 
    Solution s;
    int ans = s.work(input[0], input+1, 3);
    cout << ans << endl;
    return 0;
}

int Solution::work(int n, int* a, int aLen) {
    // write code here
    int num = aLen; // 车站的数量
    for (size_t i = 0; i < aLen-1; i++) {
        int len = a[i+1] - a[i];
        num += get_num_station(len);
    }
    return num;
}

int Solution::get_prime(int n) {
    if (n <= max) {
        return noLessPrime[n];
    }
    
    // 拓展用于记录每个数是否是素数的数组
    isPrime.resize(n+1, true);
    
    for (int i = 2; i <=n; i++) {
        if (isPrime[i] && i > max ) {
            // 如果是素数则将[max,i)赋值为prime[max], prime[i] = i
            noLessPrime.resize(i+1);
            vecIIter begin = max+noLessPrime.begin();
            vecIIter end = noLessPrime.end();
            int value = noLessPrime[max];
            generate(begin, end, [value]() { return value;});
            noLessPrime[i] = i;
            prime.push_back(i);
        }
        // 从第一个素数开始，将它的倍数设为非负数
        for (vecIIter j = prime.begin(), e = prime.end(); j != e && i*(*j) <= n; j++) {
            if (i*(*j) > max) {
                isPrime[i*(*j)] = false;
                /**
                 * 如果 i%(*j) == 0, 则 i = (*j) * a
                 * i * (*(j+1)) = (*j) * a * (*(j+1))
                 * (*j)已经筛过i * (*(j+1))这个数了，不需要用(*(j+1))再筛选一次
                 **/
                if (i % (*j) == 0) {
                    break;
                }
            }
        }
    }
    return noLessPrime[n];
}

int Solution::get_num_station(int len) {
    int max_prime = get_prime(len);
    int sum = 0;
    while(max_prime != len) {
        // 如果两个车站之间的距离不是质数，修建最大质数距离起始车站
        // 然后将该车站视为起始车站与终端车站之间判断是否需要修建车站
        sum++;
        len -= max_prime;
        max_prime = get_prime(len);
    }
    return sum;
}