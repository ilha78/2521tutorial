#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

void freeList(struct list *list);
void printList(struct list *list);
int listLength(struct list *list);
int doListLength(struct node *node);
struct list *setupList();

int main(void) {
	struct list *list = setupList();

	printList(list);

	printf("List Length: %d\n", listLength(list));
	listDelete(list, 4);

	freeList(list);

	return 0;
}

void listDelete(struct list *l, int value) {
	l->head = doListDelete(l->head, value);
}

struct list *doListDelete(struct node *l, int value) {
	// base cases
	if (l == NULL) return NULL;
	if (l->value == value) {
		struct node *temp = l->next;
		free(l);
		return temp;
	}
	// recursive case
	struct node *res = doListDelete(l->next, value);
	l->next = res;
	return l;
}

int listLength(struct list *list) {
	// call a helper that takes the first node in linked list
	return doListLength(list->head);
}

int doListLength(struct node *n) {
	// base case
	if (n == NULL) return 0;

	// recursive case
	return listLength(n->next) + 1;
}

void freeList(struct list *list) {
	struct node *n = list->head;
	while (n != NULL) {
		struct node *temp = n->next;
		free(n);
		n = temp;
	}
	free(list);
}

void printList(struct list *list) {
	struct node *n = list->head;
	printf("Printing Linked List:");
	while (n != NULL) {
		printf(" %d", n->value); 
		n = n->next;
	}
	printf("\n");
}

struct list *setupList() {
	// read input
	int n;
	printf("Enter size of linked list: ");
	scanf(" %d", &n);

	int *arr = malloc(sizeof(int) * n);
	for (int i = n - 1; i >= 0; --i) {
		scanf(" %d", &arr[i]);
	}

	// convert to linked list
	struct node *p = NULL;
	for (int i = 0; i < n; ++i) {
		struct node *n = malloc(sizeof(struct node));
		n->value = arr[i];
		n->next = p;
		p = n;
	}
	free(arr);

	struct list *l = malloc(sizeof(struct list));
	l->head = p;
	return l;

}
