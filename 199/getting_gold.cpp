#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get_neighbors(int cursor_x, int cursor_y) {
	vector<pair<int, int>> neighbors = vector<pair<int, int>>();
	for (int i = cursor_x - 1; i <= cursor_x + 1; i++) {
		for (int j = cursor_y - 1; j <= cursor_y + 1; cursor_y++) {
			neighbors.push_back(make_pair(i, j));
		}
	}
	return neighbors;
}

int main() {
	int W, H, seed_r, seed_c;
	int num_gold = 0;
	cin >> W >> H;
	char** board = new char*[H];
	int** status = new int*[H];
	for (int h = 0; h < H; h++) {
		board[h] = new char[W];
		status[h] = new int[W];
	}
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			char ch;
			cin >> ch;
			board[r][c] = ch;
			status[r][c] = ch == '#' ? 1 : 0;
			seed_c = ch == 'P' ? c : seed_c;
			seed_r = ch == 'P' ? r : seed_r;
		}
	}
	stack<pair<int, int>> dfs = stack<pair<int, int>>();
	dfs.push(make_pair(seed_r, seed_c));
	status[seed_r][seed_c] = 1;
	while (!dfs.empty()) {
		pair<int, int> cursor = dfs.top();
		dfs.pop();
		int cursor_r = cursor.first;
		int cursor_c = cursor.second;
		cout << "Exploring " << cursor_r << " " << cursor_c << ": " << board[cursor_r][cursor_c] << endl;
		num_gold += board[cursor_r][cursor_c] == 'G' ? 1 : 0;
		vector<pair<int, int>> neighbors = get_neighbors(cursor_r, cursor_c);
		bool is_near_trap = false;
		for (pair<int, int> neighbor : neighbors) {
			int neigh_r = neighbor.first;
			int neigh_c = neighbor.second;
			if (board[neigh_r][neigh_c] == 'T') {
				is_near_trap = true;
				break;
			}
		}
		if (!is_near_trap) {
			for (pair<int, int> &neighbor : neighbors) {
				int neigh_r = neighbor.first;
				int neigh_c = neighbor.second;
				if (status[neigh_r][neigh_c] == 0) {
					status[neigh_r][neigh_c] = 1;
					dfs.push(neighbor);
				}
			}
		}
	}
	cout << num_gold << endl;	
	return 0;
}
