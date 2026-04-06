#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	map<long long, pair<int, string>> people;
	cin >> n;
	for(int i = 0;i<n;i++){
		int op, color;
		long long id;
		string name;
		cin >> op;
		switch(op){
		case 1:
			cin >> name >> id >> color;
			people[id]={color, name};
		break;
		case 2:
			cin >> id >> name;
			people[id]={people[id].first, name};
		break;
		case 9:
			cin >> name;
			for(auto &e: people){
				if (e.second.second == name){
					cout << e.second.first << '\n';
				}
			}
		break;
		}
	}
}
