#include <bits/stdc++.h>

using namespace std;

class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here

        int start = 0, end = n - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (A[mid] == x) return mid;
            if (A[mid] < x) {
                if (A[mid] < A[start] && x > A[end]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (A[mid] > A[start] && x < A[start]) start = mid + 1;
                else end = mid - 1;
            }
        }

    }
};

};

int main() {
    vector<int> A{6, 1, 2, 3, 4, 5};
    cout << Finder().findElement(A, 6, 6) << endl;
    vector<int> B{13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
                  38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
                  63, 64, 65, 66, 67, 68, 69, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << Finder().findElement(B, 69, 18) << endl;
    vector<int> C{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
                  35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
                  60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 1, 2, 3, 4, 5, 6,
                  7, 8, 9};
    cout << Finder().findElement(C, 80, 6) << endl;
    return 0;
}
