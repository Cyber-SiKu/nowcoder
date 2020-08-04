#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> getPath(const vector<vector<int>> &map) {
	vector<pair<int, int>> ret;
	pair<int, int> present_pos(0, 0);
	pair<int, int> end(map.size(), map[0].size());
	vector<vector<int>> isVisited(map.size() - 1,
			vector<int>(map[0].size() - 1, 0));
	ret.push_back(present_pos);

	while (present_pos != end && !ret.empty()) {
		present_pos = *ret.rbegin();
		if (map[present_pos.first][present_pos.second] == 0) {
			// 当前结点可以访问
			if (isVisited[present_pos.first][present_pos.second] == 0) {
				// 右边仍未访问
				isVisited[present_pos.first][present_pos.second]++;
				present_pos.second++;
				if (present_pos.second < map[0].size()) {
					ret.push_back(present_pos);
				}
			} else if (isVisited[present_pos.first][present_pos.second] == 1) {
				// 右边路不通
				isVisited[present_pos.first][present_pos.second]++;
				present_pos.first++;
				if (present_pos.first < map.size()) {
					ret.push_back(present_pos);
				}
			} else {
				// 右下两路不通
				ret.pop_back();
			}
		} else {
			ret.pop_back();
		}
	}

	return ret;
}

int main(int argc, char **argv) {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> map(n, vector<int>(m, 0));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];
			}
		}

		vector<pair<int, int>> path = getPath(map);

		for (const pair<int, int> i : path) {
			cout << "(" << i.first << "," << i.second << ")" << endl;
		}
	}

	return 0;

}

