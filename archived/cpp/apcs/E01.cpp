#include <bits/stdc++.h>

bool bomb[105][105] = {0};
bool clear[105][105] = {0};

int n, m, k;
int BossLeft;

struct boss {
	int r, c, s, t;
	bool alive = true;
	void drop_bomb() {
		if (alive) {
			bomb[r][c] = true;
		}
	}
	void move() {
		if (alive) {
			int nx = r + s;
			int ny = c + t;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				alive = false;
				BossLeft--;
			} else if (bomb[nx][ny] == true) {
				alive = false;
				clear[nx][ny] = true;
				BossLeft--;
			} else {
				r = nx;
				c = ny;
			}
		}
	}
};

int main() {
	std::cin >> n >> m >> k;
	BossLeft = k;
	boss BossList[k];
	for (int i = 0; i < k; i++) {
		std::cin >> BossList[i].r >> BossList[i].c >> BossList[i].s >>
			BossList[i].t;
	}
	while (BossLeft > 0) {
		for (int i = 0; i < k; i++) {
			BossList[i].drop_bomb();
		}
		for (int i = 0; i < k; i++) {
			BossList[i].move();
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (clear[x][y] == true) {
					bomb[x][y] = false;
					clear[x][y] = false;
				}
			}
		}
	}
	int BombLeft = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (bomb[x][y] == true) {
				BombLeft++;
			}
		}
	}
	std::cout << BombLeft;
}
