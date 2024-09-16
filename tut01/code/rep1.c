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
	printf("Delete the first instance of 2\n");
	list = listDelete(list, 2);

	printList(list);
	printf("List Length: %d\n", listLength(list));

	freeList(list);

	return 0;
}

struct node *listDelete(struct node *list, int value) {
	struct node *head = list;
	if (head == NULL) {
		return NULL;
	}
	if (head->value == value) {
		struct node *newHead = head->next;
		free(head);
		return newHead;
	}

	struct node *prev = head;
	struct node *curr = head->next;
	while (curr != NULL) {
		if (curr->value == value) {
			prev->next = curr->next;
			free(curr);
			break;
		}

		prev = curr;
		curr = curr->next;
	}
	return head;
}



// return the length of the list;
int listLength(struct node *list) {
	int counter = 0;
	for (; list != NULL; list = list->next) {
		counter++;
	}
	return counter;

}

void freeList(struct node *n) {
	while (n != NULL) {
		struct node *temp = n->next;
		free(n);
		n = temp;
	}

}

void printList(struct node *n) {
	printf("Printing Linked List:");
	while (n != NULL) {
		printf(" %d", n->value); 
		n = n->next;
	}
	printf("\n");
}

struct node *setupList() {
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

	return p;
}
