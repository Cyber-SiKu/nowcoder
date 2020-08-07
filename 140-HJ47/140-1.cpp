#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> getMeasure(vector<pair<int, int>> data)
{
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i].first - 1 != data[i - 1].first) {
            int A = data[i - 1].second;
            int length = data[i].first - data[i - 1].first;
            int delta = (data[i].second - data[i - 1].second) / length;
            for (size_t k = 1; k < length; k++) {
                int insert_value = A + delta * k;
                data.insert(data.begin() + i + k, make_pair(data[i].first + k, insert_value));
            }
            i += (length - 1);
        }
    }

    return data;
}

int main()
{
    int m, n;
    while (cin >> m >> n) {
        vector<pair<int, int>> data(m);
        for (size_t i = 0; i < m; i++) {
            cin >> data[i].first >> data[i].second;
        }
        vector<pair<int, int>> output = getMeasure(data);
        for (const pair<int, int>& i : output) {
            cout << i.first << " " << i.second << endl;
        }
    }

    return 0;
}