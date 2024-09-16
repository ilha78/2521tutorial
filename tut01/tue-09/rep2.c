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
struct list *setupList();

int main(void) {
	struct list *list = setupList();

	printList(list);

	printf("List Length: %d\n", listLength(list));

	// printList(list->head);

	freeList(list);

	return 0;
}

// return the length of the list;
int listLength(struct list *list) {
	int counter = 0;
	struct node *curr = list->head;
	while (curr != NULL) {
		counter++;
		curr = curr->next;
	}

	return counter;

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
