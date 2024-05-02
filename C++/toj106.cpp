#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
	int buf = 2;
	while (buf % 71){
		buf *= 2;
		buf ++;
	}
	if (buf % 3){
		cout << "turn left\n";
	}else {
		cout << "turn right\n";
	}
	return 0;
}
