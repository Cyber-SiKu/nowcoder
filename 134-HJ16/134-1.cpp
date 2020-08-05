#include <iostream>
#include <vector>

using namespace std;

class good {
public:
    int v;
    int p;
    int q;
    good(int v, int p, int q)
        : v(v)
        , p(p)
        , q(q)
    {
    }
};

int main()
{
    int n, m;
    while (cin >> n >> m) {
        vector<good> data;
        for (size_t i = 0; i < m; i++) {
            int v, p, q;
            cin >> v >> p >> q;
            data.push_back(good(v, p, q));
        }
    }

    return 0;
}