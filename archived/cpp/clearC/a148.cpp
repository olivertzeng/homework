#include <bits/stdc++.h>
using namespace std;

int main(){
	float n;
	while(cin >> n){
		float total = 0, temp;
		for(float i = 0;i<n;i++){
			cin >> temp;
			total += temp;
		}
		cout << (total / n > 59 ? "no" : "yes") << '\n';
	}
}
