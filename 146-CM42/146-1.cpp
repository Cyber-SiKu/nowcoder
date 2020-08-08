#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findMagicIndex(vector<int> A, int n)
    {
        // write code here
        bool ret = false;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int midle = (end - start) / 2 + start;
            if (A[midle] == midle) {
                ret = true;
                break;
            } else if (A[midle] < midle) {
                start = midle + 1;
            } else {
                end = midle - 1;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> data { 1, 2, 3, 4, 5 };
    cout << s.findMagicIndex(data, 5) << endl;

    data = vector<int> { 0, 1, 3, 5, 6, 9, 11, 13, 15, 18, 19, 22, 25, 27, 30, 33, 35, 37, 38, 39, 41, 43, 44, 45, 46, 49, 51, 54, 57, 60, 62, 63, 64, 65, 66, 68, 71, 72, 73, 75, 78, 81, 82, 83, 85, 86, 87, 90, 91, 93, 95, 98, 99, 100, 101, 103, 105, 106, 109, 112, 114, 116, 117, 120, 122, 125, 128, 131, 133, 135, 136, 139, 142, 144, 145, 147, 148, 151, 154, 157, 158 };
    cout << s.findMagicIndex(data, 81) << endl;

    data = vector<int> { -1, 1, 3, 4 };
    cout << s.findMagicIndex(data, 4) << endl;

    data = vector<int> { -1, 0, 2, 4 };
    cout << s.findMagicIndex(data, 4) << endl;

    return 0;
}
