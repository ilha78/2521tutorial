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
struct list *listDelete(struct node *list, int value);

int main(void) {
	struct list *list = setupList();

	printList(list);
	printf("List Length: %d\n", listLength(list));

	int value;
	printf("Enter the value you want to delete (the first instance of occurring): ");
	scanf(" %d", &value);
	list->head = listDelete(list->head, value);
	printList(list->head);
	printf("List Length: %d\n", listLength(list));
	
	freeList(list);

	return 0;
}

// TODO
int listLength(struct list *list) {
	
	return -1;
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

	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = n - 1; i >= 0; --i) {
		scanf(" %d", &arr[i]);
	}

	// convert to linked list
	struct node *p = NULL;
	for (int i = 0; i < n; ++i) {
		struct node *n = (struct node *)malloc(sizeof(struct node));
		n->value = arr[i];
		n->next = p;
		p = n;
	}
	free(arr);

	struct list *l = (struct list *)malloc(sizeof(struct list));
	l->head = p;
	return l;

}
