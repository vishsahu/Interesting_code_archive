#include<iostream>
using namespace std;
#include<stdlib.h>

struct node{
    int data;
    node* next;
};

void add_to_list(node** head, int value)
{
    node* new_node;
    new_node = (node*)malloc(sizeof(new_node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

int count_nodes(node* head)
{
    int i=0;
    struct node* current = head;
    while(current != NULL){
        i++;
        current = current->next;
    }
    return i;
}

main()
{
    node* head=NULL;
    add_to_list(&head, 23);
    add_to_list(&head, 3);
    add_to_list(&head, 53);
    add_to_list(&head, 36);
    add_to_list(&head, 37);
    cout<<head<<endl;
    cout<<"#of nodes:"<<count_nodes(head)<<endl;

    return 0;
}
