#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void visitIsland(vector<vector<int>>& map, const int w, const int h, const int row, const int col) {
	vector<pair<int, int>> dirs = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
	queue<pair<int, int>> pos_q;
	pos_q.push({row, col});
	map[row][col] = 0;

	while (!pos_q.empty()) {
		int cur_row = pos_q.front().first;
		int cur_col = pos_q.front().second;
		pos_q.pop();

		// 연결된 땅 방문처리
		for (int i = 0; i < 8; i++) {
			int next_row = cur_row + dirs[i].first;
			int next_col = cur_col + dirs[i].second;

			if (0 <= next_row && next_row < h && 0 <= next_col && next_col < w) {
				if (map[next_row][next_col] == 1) {
					map[next_row][next_col] = 0;
					pos_q.push({next_row, next_col});
				}
			}
		}
	}
}

int findIslands(vector<vector<int>>& map, const int w, const int h) {
	int num_of_island = 0;

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (map[row][col] == 1) {
				visitIsland(map, w, h, row, col);
				num_of_island++;
			}
		}
	}

	return num_of_island;
}

int main() {
	int w, h;

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		vector<vector<int>> map(h, vector<int>(w, 0));
		for (int row = 0; row < h; row++) {
			for (int col = 0; col < w; col++) {
				cin >> map[row][col];
			}
		}
		
		cout << findIslands(map, w, h) << endl;
	}

	return 0;
}