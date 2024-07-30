#include "stdio.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	switch (rand() % 4) {
	case 0:
		printf("拉麵\n");
		break;
	case 1:
		printf("水餃\n");
		break;
	case 2:
		printf("臭豆腐\n");
		break;
	case 3:
		printf("貢丸\n");
		break;
	}
	return 0;
}
