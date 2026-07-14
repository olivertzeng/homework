#include <stdio.h>
#include <stdlib.h>

typedef struct person {
	struct person *next;
	struct person *prev;
	int age;
	int height;
} person_t;

person_t *createPerson(int age, int height) {
	person_t *p = (person_t *)malloc(sizeof(person_t));
	p->age = age;
	p->height = height;
	p->next = NULL;
	p->prev = NULL;
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

void *findAndDelete(int targetAge, person_t *head) {
	while (head) {
		if (head->age == targetAge) {
			person_t *tempP = head->prev;
			person_t *tempN = head->next;
			tempP->next = tempN;
			tempN->prev = tempP;
			free(head);
			head = tempP;
			printf("Deleted node that has age %d\n", targetAge);
		}
		head = head->next;
	}
	return 0;
}

int main(int argc, char *argv[]) {

	person_t *head = createPerson(10, 100);
	person_t *node;

	node = createPerson(12, 120);
	head->prev = node;
	node->next = head;
	head = node;

	node = createPerson(13, 130);
	head->prev = node;
	node->next = head;
	head = node;

	node = createPerson(13, 150);
	head->prev = node;
	node->next = head;
	head = node;

	node = createPerson(14, 190);
	head->prev = node;
	node->next = head;
	head = node;

	node = createPerson(15, 170);
	head->prev = node;
	node->next = head;
	head = node;

	node = createPerson(16, 110);
	head->prev = node;
	node->next = head;
	head = node;

	person_t *temp = findAndDelete(13, head);
	person_t *result = findPerson(13, head);
	if (result) {
		printf("found person height: %d\n", result->height);
	} else {
		printf("not found\n");
	}

	return 0;
}
