#include <iostream>

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
	std::string lyrics = R"(
We've known each other for so long
Your heart's been aching, but you're too shy to say it
Inside we both know what's been going on
We know the game and we're gonna play it

Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you

We've known each other for so long
Your heart's been aching, but you're too shy to say it
Inside we both know what's been going on
We know the game and we're gonna play it

Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you

(Ooh, give you up)
(Ooh, give you up)

Never gonna give, never gonna give
(Give you up)
Never gonna give, never gonna give
(Give you up)

Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you
)";

	std::cout << lyrics << '\n';
	return 0;
}
