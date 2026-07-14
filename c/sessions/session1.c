#include <stdio.h>

int main(int argc, char *argv[]) {
	typedef struct person {
		int age;
		int height;
	} person_t;

	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	person_t people[3] = {{1, 2}, {2, 3}};
	person_t *p1 = people;
	p1->age = 99;
	p1 += 2;
	p1->age = 33;
	p1->height = 90;
	printf("Hello, World!\n");
	for (int i = 0; i < 10; i++) {
		printf("%d th person age: %d, height: %d\n", i, people[i].age,
			   people[i].height);
	}

	return 0;
}
