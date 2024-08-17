// Description
//
// 在一個𝑛×𝑚的棋盤上有𝑘個魔王，一開始第𝑖魔王會位在(𝑟𝑖,𝑐𝑖)的位置上，並且每回合會移動(𝑠𝑖,𝑡𝑖)。也就是說，若本來在(𝑥,𝑦)位置，經過移動後會跳到(𝑥+𝑠𝑖,𝑦+𝑡𝑖)位置。
//
//
// 每個魔王都有不同的𝑟,𝑐,𝑠,𝑡值，每回合每個魔王移動前會在所在位置上放下一顆炸彈，然後才進行移動，而若魔王移動到已經被放有炸彈的位置，炸彈則會被引爆，該位置的魔王和炸彈則消失不見。如果兩個魔王同時踏到同一個炸彈上會一起被炸掉，如果同一位置上有多個炸彈也會被一起引爆。
//
//
// 當魔王移動超出整個棋盤的範圍，則被視為消失
//
// 請計算，當棋盤上沒有任何魔王時，盤面上總共剩下幾格有炸彈?
//
// Input
//
// 第一行輸入三個正整數𝑛(1≤𝑛≤100),𝑚(1≤𝑚≤100),𝑘(1≤𝑘≤500)代表盤面大小為𝑛×𝑚，上面一開始有𝑘個魔王。
//
// 接下來有𝑘行，第𝑖行有四個整數𝑟𝑖,𝑐𝑖,𝑠𝑖,𝑡𝑖(0≤𝑟<𝑛,0≤𝑐<𝑚)
//
// 配分
//
//     (50%)𝑛=1，𝑟𝑖=0,𝑠𝑖=0
//     (50%) 無其它限制
//
// Output
//
// 輸出當場上沒有魔王的時候剩下幾格有炸彈
#include <bits/stdc++.h>

using namespace std;

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
	cin >> n >> m >> k;
	BossLeft = k;
	boss BossList[k];
	for (int i = 0; i < k; i++) {
		cin >> BossList[i].r >> BossList[i].c >> BossList[i].s >> BossList[i].t;
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
	cout << BombLeft;
}
