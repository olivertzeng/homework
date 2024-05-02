#include <bits/stdc++.h>
using namespace std;

int n, buf;
vector<int> score;
int main (int argc, char *argv[]) {
	cin >> n;
	while(n--){
		cin >> buf;
		score.push_back(buf);
	}
	sort(score.begin(), score.end(), greater<int>());
	cout << score[0] << "\n";
	return 0;
}
