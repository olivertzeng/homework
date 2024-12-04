#include <iostream>
#include <queue>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int n, m, w, s, d;
	std::priority_queue<int> pq;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> w >> s;
		if (w) {
			d = (s - m) * 0.05 + 25;
			if (d > 0)
				m += d;
			else
				m++;
		} else {
			d = (s - m) * 0.05 - 25;
			if (d < 0) {
				m += d;
				pq.push((d < -50 ? -d + 1 : 50));
			} else
				pq.push(d + 50);
		}
	}

	if (pq.size())
		m += (pq.top() > 0 ? pq.top() : 26);

	std::cout << m << '\n';
	return 0;
}
