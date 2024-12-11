#include <iostream>
#include <string>

// NOTE: prev => previous element
// next => next element
// ad => address of the elemnet
// first => the first element of the pile
// last => the last element of the pile
// HACK: sauce =>
// https://alan23273850.github.io/Online-Judge-Problems/zerojudge/c073/

int prev[(int)1e5], next[(int)1e5], ad[(int)1e5], first[(int)1e5],
	last[(int)1e5];

void reset(int x) {
	// reset(x): reset ad[x] pile until meeting x
	// FIX: This is currently not functional
	int buf = prev[x], temp;
	while (buf != -1) {
		if (last[ad[buf]] == buf)
			last[ad[buf]] = prev[buf];
		if (first[ad[buf]] == buf)
			first[ad[buf]] = next[buf];
		if (next[buf] != -1)
			prev[next[buf]] = prev[buf];
		if (prev[buf] != -1)
			next[prev[buf]] = next[buf];
		next[buf] = first[buf];
		prev[first[buf]] = buf;
		temp = prev[buf];
		ad[buf] = first[buf] = buf;
		prev[buf] = -1;
		buf = temp;
	}
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	int a, b, n;
	std::string commandA, commandB;
	while (std::cin >> n) {
		for (int i = 0; i < n; i++)
			ad[i] = first[i] = last[i] = i, next[i] = prev[i] = -1;
		while (std::cin >> commandA && commandA != "quit") {
			std::cin >> a >> commandB >> b;
			if (a == b || ad[a] == ad[b])
				continue;
			if (commandA == "move")
				reset(a);
			if (commandB == "onto")
				reset(b);
			int ada = ad[a], adb = ad[b];
			if (next[a] == -1)
				first[ada] = last[ada] = -1;
			while (a != -1) {
				if (next[a] != -1)
					prev[next[a]] = prev[a];
				if (prev[a] != -1)
					next[prev[a]] = next[a];
				ad[a] = adb, next[a] = first[adb], prev[first[adb]] = a;
				first[adb] = a;
				a = prev[a];
			}
		}
		for (int i = 0; i < n; i++) {
			std::cout << i << ':';
			if (last[i] != -1) {
				int temp = last[i];
				while (temp != -1) {
					std::cout << ' ' << temp;
					temp = prev[temp];
				}
			}
			std::cout << '\n';
		}
	}

	return 0;
}
