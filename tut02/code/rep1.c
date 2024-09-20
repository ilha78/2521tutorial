#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

void freeList(struct node *n);
void printList(struct node *n);
int listLength(struct node *l);
int listCountOdds(struct node *l);
bool listIsSorted(struct node *l);
struct node *listDelete(struct node *l, int value);
struct node *setupList();

int main(void) {

	struct node *list = setupList();
	printList(list);

	printf("List Length: %d\n", listLength(list));
	printf("Number of odd valued nodes: %d\n", listCountOdds(list));
	if (listIsSorted(list)) {
		printf("Sorted!\n");
	} else {
		printf("Unsorted!\n");
	}
	list = listDelete(list, 4);
	printList(list);

	freeList(list);

	return 0;
}


// TODO:
int listLength(struct node *l) {
	// base case
	if (l == NULL) return 0;

	// recursive case
	return listLength(l->next) + 1;
}

// TODO:
int listCountOdds(struct node *l) {
	if (l == NULL) return 0;

	// the value is odd
	if (l->value % 2 == 1) {
		return listCountOdds(l->next) + 1;
	} 
	// the value is even
	return listCountOdds(l->next);
	
}

// TODO:
bool listIsSorted(struct node *l) {
	if (l == NULL || l->next == NULL) return true;
	if (l->value > l->next->value) return false;

	return listIsSorted(l->next);
}

// TODO:
struct node *listDelete(struct node *l, int value) {
	// base cases
	if (l == NULL) return NULL;
	if (l->value == value) {
		struct node *temp = l->next;
		free(l);
		return temp;
	}
	// recursive case
	struct node *res = listDelete(l->next, value);
	l->next = res;
	return l;
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
