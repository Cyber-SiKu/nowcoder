/**
 * 时间复杂度过大
 * tips : 使用哥德巴赫猜想算法是最快的
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
using std::max_element;

using vecIIter = vector<int>::iterator;
using setIIter = set<int>::iterator;

#define MAXSIZE 100000000+1

class Solution {
private:
    vector<bool> isPrime;
    vector<int> noLessPrime; // noLessPrime[i] 表示不小于i的最大质数
    vector<int> prime; // 存储已知的质数
    vector<int> lens; // 保存所有车站之间的距离
    vector<int> stationNum; // station_num[i] 表示距离为i时中间间隔的车站数量
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
     * @return void
     */
    void get_prime(int n);
    void init_lens(int *a, int aLen);
    int get_num_station(int len);
};

int main(int argc, char * argv[]) {
    // int input[] = {3, 0, 7, 11}; 
    // Solution s;
    // int ans = s.work(input[0], input+1, input[0]);
    // cout << ans << endl; // 4

    // int input[] = {8,0,1,4,11,12,21,22,29}; 
    // Solution s;
    // int ans = s.work(input[0], input+1, input[0]);
    // cout << ans << endl;

    // int input[] = {9,0,7,13,16,17,19,20,23,25}; 
    // Solution s;
    // int ans = s.work(input[0], input+1, input[0]);
    // cout << ans << endl;

    // int input[] = {7,0,3,10,15,16,24,28};
    // Solution s;
    // int ans = s.work(input[0], input+1, input[0]);
    // cout << ans << endl;

    int input[] = {100,0,3468,4269,4535,5503,9542,11309,11742,14146,19417,20684,24989,27559,30026,30711,32764,39052,39268,47877,48744,52531,56668,61808,62056,62757,65976,70481,74768,76471,83459,83826,88950,89367,90316,90735,91150,97140,100261,106049,111972,114857,115474,117210,118325,120562,120694,124466,135277,136177,138411,142416,143284,145585,156712,159499,163187,166472,172361,173612,174730,175064,178033,178234,178816,184272,190028,191195,196918,200386,201639,202339,206175,206676,212065,212198,213967,214083,220856,221091,223709,234235,236772,249567,256941,261628,271155,271920,275924,276026,276041,276127,279962,280431,283283,284251,288036,288871,290874,291207,295543};
    Solution s;
    int ans = s.work(input[0], input+1, input[0]);
    cout << ans << endl;

    return 0;
}

int Solution::work(int n, int* a, int aLen) {
    // write code here
    int num = aLen; // 车站的数量
    init_lens(a, aLen);
    int max = *max_element(lens.begin(), lens.end());
    get_prime(max);
    for (int i : lens) {
        num += get_num_station(i);
    }
    return num;
}

void Solution::get_prime(int n) {
    if (n < 2) {
        return ;
    }
    
    // 初始化一个布尔数组，用于记录每个数是否是素数
    isPrime.resize(n+1, true);
    
    noLessPrime.resize(n+1, 1);
    stationNum.resize(n+1, 0);

    vecIIter start = noLessPrime.begin();
    int max = 1;
    for (int i = 2; i <=n; i++) {
        if (isPrime[i]) {
            // 如果是素数则将[max,i)赋值为prime[max], prime[i] = i
            vecIIter begin = start+max;
            vecIIter end = start+i;
            int value = noLessPrime[max];
            generate(begin, end, [value]() { return value;});
            noLessPrime[i] = max = i;
            prime.push_back(i);
        }
        // 从第一个素数开始，将它的倍数设为非负数
        for (vecIIter j = prime.begin(), e = prime.end(); j != e && i*(*j) <= n; j++) {
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
    if (max != n) {
        // 最后一个数不是质数
        vecIIter begin = start+max;
        vecIIter end = start+n;
        int value = noLessPrime[max];
        generate(begin, end, [value]() { return value;});
        noLessPrime[n] = max;
    }
    
}

void Solution::init_lens(int *a, int aLen) {
    for (size_t i = 0; i < aLen-1; i++) {
        int len = a[i+1] - a[i];
        lens.push_back(len);
    }
}

int Solution::get_num_station(int len) {
    int tmp = len;
    int max_prime = noLessPrime[tmp];
    int sum = 0;
    while (!isPrime[tmp] && stationNum[tmp] == 0) {
        sum++;
        tmp -= max_prime;
        max_prime = noLessPrime[tmp];
    }
    stationNum[len] = sum + stationNum[tmp];
    return stationNum[len];
}