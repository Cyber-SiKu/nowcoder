#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::iterator;

class Factory{
private:
public:
    int a;
    int b;
    Factory(int a,int b);
};

class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @param k int整型 
     * @param a int整型vector 
     * @param b int整型vector 
     * @return long长整型
     */
    long long solve(int n, int k, vector<int>& a, vector<int>& b);
    void translate(const vector<int>& a, const vector<int>& b, vector<Factory> &c);
};

Factory::Factory(int a,int b): a(a), b(b) {}

long long Solution::solve(int n, int k, vector<int>& a, vector<int>& b) {
    // write code here
    vector<Factory> c;
    translate(a, b, c);
    sort(c.begin(), c.end(), [](const Factory & a, const Factory &b){
        return a.a < b.a;
    });

    long long count = 0; // 记录天数
    int tmp = k; // 剩余码头数量
    for (vector<Factory>::iterator i = c.begin(), e = c.end(); i != e;) {
        if (i->b < tmp) {
            tmp -= i->b;
            ++i;
        } else if (i->b == tmp) {
            tmp = k;
            count++;
            ++i;
        } else { // i->a > k 
            i->b -= tmp;
            count++;
            tmp = k;
        } 
    }
    return count;
}

void Solution::translate(const vector<int>& a, const vector<int>& b, vector<Factory> &c) {
    for (size_t i = 0, e = a.size(); i < e; i++) {
        Factory tmp(a[i], b[i]);
        c.push_back(tmp);
    }
}

int main(int argc, char *argv[]) {
    int n = 3;
    int k = 2;
    vector<int> a = {1,2,3};
    vector<int> b = {5,5,5};
    Solution s;
    cout << s.solve(n, k ,a ,b) << endl;
    return 0;
}