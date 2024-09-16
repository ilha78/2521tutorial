#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

void freeList(struct node *n);
void printList(struct node *n);
int listLength(struct node *list);
struct node *listDelete(struct node *list, int value);
struct node *setupList();

int main(void) {

	struct node *list = setupList();
	printList(list);

	printf("List Length: %d\n", listLength(list));

	int value;
	printf("Enter the value you want to delete (the first instance of occurring): ");
	scanf(" %d", &value);

	list = listDelete(list, value);
	printList(list);
	printf("List Length: %d\n", listLength(list));

	freeList(list);

	return 0;
}

// TODO
int listLength(struct node *list) {
	return 0;

}

// TODO
struct node *listDelete(struct node *list, int value) {
	return NULL;
}



// free list
void freeList(struct node *n) {
	while (n != NULL) {
		struct node *temp = n->next;
		free(n);
		n = temp;
	}

}

// print list
void printList(struct node *n) {
	printf("Printing Linked List:");
	while (n != NULL) {
		printf(" %d", n->value); 
		n = n->next;
	}
	printf("\n");
}

// read the size of linked list
// take input values into arr
// convert arr to list and return the first node
struct node *setupList() {
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

	return p;
}
