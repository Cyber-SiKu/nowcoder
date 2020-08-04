#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> getPath(vector<vector<int>> map, pair<int, int> start, pair<int, int> end)
{
    vector<pair<int, int>> ret;

    if (map[start.first][start.second] == 1) {
        return ret;
    }

    if (start == end) {
        ret.push_back(start);
        return ret;
    }

    if (start.second + 1 < map[0].size()) {
        vector<pair<int, int>> right = getPath(map, make_pair(start.first, start.second + 1), end);
        if (right.size() != 0) {
            ret.push_back(start);
            ret.insert(ret.end(), right.begin(), right.end());
        }
    }
    if (start.first + 1 < map.size()) {
        vector<pair<int, int>> down = getPath(map, make_pair(start.first + 1, start.second), end);
        if (down.size() != 0) {
            ret.push_back(start);
            ret.insert(ret.end(), down.begin(), down.end());
        }
    }

    return ret;
}

int main(int argc, char** argv)
{
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> map(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> map[i][j];
            }
        }

        vector<pair<int, int>> path = getPath(map, make_pair(0, 0), make_pair(n - 1, m - 1));

        for (const pair<int, int> i : path) {
            cout << "(" << i.first << "," << i.second << ")" << endl;
        }
    }

    return 0;
}
