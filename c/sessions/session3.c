#include <stdio.h>
#include <stdlib.h>

typedef struct person {
	struct person *next;
	int age;
	int height;
} person_t;

person_t *createPerson(int age, int height) {
	person_t *p = (person_t *)malloc(sizeof(person_t));
	p->age = age;
	p->height = height;
	p->next = NULL;
	return p;
}

person_t *findPerson(int targetAge, person_t *head) {
	while (head) {
		if (head->age == targetAge)
			return head;
		head = head->next;
	}
	printf("not found\n");
	return NULL;
}

int main(int argc, char *argv[]) {

	person_t *head = createPerson(10, 100);
	person_t *node;

	node = createPerson(12, 120);
	node->next = head;
	head = node;

	node = createPerson(13, 130);
	node->next = head;
	head = node;

	node = createPerson(14, 190);
	node->next = head;
	head = node;

	node = createPerson(15, 170);
	node->next = head;
	head = node;

	node = createPerson(16, 110);
	node->next = head;
	head = node;

	person_t* result = findPerson(13, head);
	printf(result ? "found person height: %d", result->height : "not found");

	return 0;
}
