#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int type;
typedef struct node {
	type val;
	node *next;
} node;

void print_list(node **h) {
	node *curr = *h;
	while (curr != NULL) {
		cout << curr->val <<" ";
		curr = curr->next; 
	}
	cout <<"\n";
}

void insert_at_tail(node *tail, type val) {

}

void insert_at_front(node *head, type val) {

}

void partition_list(node *head, type pivot) {
	node *tail = head;
	node *temp = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	while (temp != NULL) {
		if (temp->val <= pivot)
			temp = temp->next;
		else {

		}

	}
}

void delete_positional_node()

void delete_nodes(node **head, type val) {
	node *prev = NULL;
	node *del = NULL;
    node *curr = *head;
    while (curr != NULL) {
        if (curr->val == val) {
            del = curr->next;
            if (!del) {
            	if (prev == NULL) {
                	*head = NULL;
                	break;
                }
                prev->next = NULL;
                free(curr);
                break;
            } 
            curr->val = curr->next->val;
            curr->next = curr->next->next;
            free(del);
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
}

void insert_node(node **h, type val) {
	node *temp = NULL;
	temp = (node *)malloc(sizeof(node));
	temp->val = val;
	temp->next = *h;
	*h = temp;
}

int main () {
	node *head = NULL;
	type key = 1;
	
	insert_node(&head, 133);
	insert_node(&head, 1);
	insert_node(&head, 1);
	insert_node(&head, 14);
	insert_node(&head, 1);
	insert_node(&head, 134);
	print_list(&head);
	delete_nodes(&head, key);
	print_list(&head);

}