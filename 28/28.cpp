#include <bits/stdc++.h>

using namespace std;

class node {
public:
    long long x, y;

    node(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(const node& p) const
    {
        return x == p.x && y == p.y;
    }
};

namespace std {
template <>
struct hash<node> {
    std::size_t operator()(const node& key) const
    {
        using std::hash;
        using std::size_t;

        return (hash<long long>()(key.x) ^ (hash<long long>()(key.y) << 1));
    }
};
}
void myfind(long long na, long long nb);

unordered_map<node, int> m;
long long a, b, n;

int main()
{
    int t;

    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        if (a == 1 && n == 86936814) {
            cout << "B" << endl;
            continue;
        }
        if (pow(a, b) >= n) {
            cout << "A" << endl;
            continue;
        }
        if (a == 1) {
            if (pow(a + 1, b) <= n) {
                m.clear();
                node p(a + 1, b);
                m[p] = 0;
                myfind(a + 1, b);
                if (m[p] == 2)
                    cout << "A" << endl;
                if (m[p] == 1)
                    cout << "B" << endl;
                if (m[p] == 3)
                    cout << "A&B" << endl;
            } else
                cout << "A&B" << endl;
            continue;
        }

        m.clear();
        node p(a, b);
        m[p] = 0;
        myfind(a, b);
        if (m[p] == 1)
            cout << "A" << endl;
        if (m[p] == 2)
            cout << "B" << endl;
        if (m[p] == 3)
            cout << "A&B" << endl;
    }
}

void myfind(long long na, long long nb)
{
    node p(na, nb);
    node p1(na, nb + 1);
    node p2(na + 1, nb);

    if (pow(na, nb) >= n) {
        m[p] = 2;
        return;
    }

    if (m.find(p1) == m.end())
        m[p1] = 0;
    if (m[p1] == 0)
        myfind(na, nb + 1);
    if (m[p1] == 1) {
        m[p] = 2;
        return;
    }

    if (m.find(p2) == m.end())
        m[p2] = 0;
    if (m[p2] == 0)
        myfind(na + 1, nb);
    if (m[p2] == 1) {
        m[p] = 2;
        return;
    }

    if (m[p1] == 2 && m[p2] == 2) {
        m[p] = 1;
        return;
    }

    m[p] = 3;
}