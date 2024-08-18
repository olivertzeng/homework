#include <bits/stdc++.h>
using namespace std;
long long person[1000000]; // 紀錄編號ai人的團體，宣告在全域預防記憶體超出
int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	long long n, m, a, t = 0;
	string s;
	queue<long long> team[1005], line; // 分為實際排隊情形與團體內排隊情形
	while (cin >> n) {
		memset(person, 0, sizeof(person));
		cout << "Line #" << ++t << "\n"; // 輸出需要
		for (long long i = 1; i <= n; i++) {
			cin >> m; // 每個團體的人數
			for (long long j = 0; j < m; j++) {
				cin >> a;
				person[a] = i; // 編號a的人是團體i的
			}
		}
		while (cin >> s) {
			if (s == "STOP")
				break;
			if (s == "ENQUEUE") { // 排隊進入
				cin >> a;		  // 編號a的人
				if (person[a] == 0) {
					line.push(
						a + 1300); // 如果這個人沒加入任何團體的話做個標記
								   // (因為團體的編號最多到1000因此可以以此標記)
				} else {
					if (team[person[a]].size() == 0) {
						line.push(
							person
								[a]); // 如果這團體首次有人進入的話將這個團體的編號放入排隊中
					}
					team[person[a]].push(a); // 將這個人加入團體的排隊中
				}
			} else {
				if (line.front() <= 1000) { // 確認有沒有被標記
					cout << team[line.front()].front()
						 << "\n"; // 從排隊中的團體編號找到團體中最前方的人
					team[line.front()].pop(); // 這個人進入了所以移除
					if (team[line.front()].size() ==
						0) { // 這個團體的人都進入了所以得移除該編號
						line.pop();
					}

				} else {
					cout << line.front() - 1300
						 << "\n"; // 移除剛剛的標記就是它真正的編號
					line.pop();
				}
			}
		}
	}
}
