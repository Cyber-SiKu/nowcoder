#include <algorithm>

using namespace std;

class LCA {
public:
    int getLCA(int a, int b)
    {
        // write code here
        if (a == b) {
            return a;
        }
        return getLCA(max(a, b) / 2, min(a, b));
    }
};