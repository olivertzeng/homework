// Copyright (c) 2024 Oliver Tzeng. All Rights Reserved.

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int ans = rand() % 100 + 1;
  int usr;
  while (cin >> usr) {
    if (usr == ans) {
      cout << "Congrats\n";
      break;
    } else if (usr < ans) {
      cout << "Please guess a greater number\n";
    } else {
      cout << "Please guess a smaller number\n";
    }
  }
  return 0;
}
