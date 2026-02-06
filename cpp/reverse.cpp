#include <algorithm>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
    std::string usr;
    std::cin >> usr;
    std::reverse(usr.begin(), usr.end());
    std::cout << usr << '\n';

    return 0;
}
