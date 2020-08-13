#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> data(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        int pos;
        cin >> pos;
        cout << data[n - pos] << endl;
    }

    return 0;
}