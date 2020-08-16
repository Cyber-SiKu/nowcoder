#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        set<int> s;
        for (size_t i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }
        for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
        {
            cout << *i << endl;
        }
    }

    return 0;
}