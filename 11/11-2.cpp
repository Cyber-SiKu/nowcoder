#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printv(const vector<T> & a) {
    for (T i: a) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    /**
     * 
     * @param a int整型vector 
     * @param b int整型vector 
     * @return long长整型vector
     */
    vector<long> solve(vector<int>& a, vector<int>& b) {
        // write code here
        vector<long> c(b.size(), 0);
        sort(a.begin(), a.end());
        int count = 0;
        long sum = 0;
        for (size_t i = 0, e = a.size(); i != e; i++){
            if (a[i] < b[count]) {
                a[i] = 0;
                sum += b[count];
            }
        }
        
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> a = {10, 20, 10};
    vector<int> b = {5, 7, 2};
    vector<long> c = s.solve(a, b);
    printv<long>(c);
    return 0;
}