#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int list[n], sorted[n];
	bool checked[200000] = {0};
	for(auto &e: list){
		cin >> e;
	}
	int maxI = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if((list[maxI] < list[j] && !checked[j]) || checked[maxI]){
				maxI = j;
			}
		}
		sorted[i] = list[maxI];
		checked[maxI] = 1;
	}
	for(auto &e: sorted){
		cout << e << '\n';
	}
}
