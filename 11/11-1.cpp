/**
 * 时间复杂度过大
*/
#include <iostream>
#include <vector>

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
        vector<long> c;
        long daily = 0;
        int count = 0; // 记录空果树的数量
        const int end_day = b.size();
        int day_number = 0;
        while (day_number != end_day) {
            for (size_t i = 0, e = a.size(); i != e; i++) {
                // 遍历所有树
                if (a[i] == 0) {
                    continue;
                } else if (a[i] < b[day_number]) {
                    daily += a[i];
                    a[i] = 0;
                } else {
                    daily += b[day_number];
                    a[i] -= b[day_number];
                }             
            }
            c.push_back(daily);
            day_number++;
            daily = 0;
        }
        return c;
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