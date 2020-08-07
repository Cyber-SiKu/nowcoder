#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int getKinds(vector<pair<int, int>> data)
{
    unordered_set<int> fama;
    fama.insert(0);
    for (size_t i = 0; i < data.size(); i++) {
        vector<int> tmp;
        for (size_t j = 1; j <= data[i].second; j++) {
            for (const int k : fama) {
                tmp.push_back(k + j * data[i].first);
            }
        }
        for (const int& j : tmp) {
            fama.insert(j);
        }
    }
    return fama.size();
}

int main()
{
    int n;
    while (cin >> n) {
        vector<pair<int, int>> data(n);
        for (size_t i = 0; i < n; i++) {
            cin >> data[i].first;
        }
        for (size_t i = 0; i < n; i++) {
            cin >> data[i].second;
        }
        cout << getKinds(data) << endl;
    }

    return 0;
}