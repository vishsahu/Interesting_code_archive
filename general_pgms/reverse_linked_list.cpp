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

void reverse_list(node** head)
{
    node* pnode = NULL;
    node* cnode = *head;
    node* nnode;
    while(cnode != NULL){
        nnode = cnode->next;
        cnode->next = pnode;
        pnode = cnode;
        cnode = nnode;
    }
    *head = pnode;
}

main()
{
    node* head=NULL;
    add_to_list(&head, 23);
    add_to_list(&head, 3);
    add_to_list(&head, 53);
    add_to_list(&head, 36);
    add_to_list(&head, 37);
    //print the list
    node *cnode = head;
    while(cnode != NULL){
        cout<<cnode->data<<" ";
        cnode = cnode->next;
    }
    cout<<endl;
    reverse_list(&head);
    cnode = head;
    while(cnode != NULL){
        cout<<cnode->data<<" ";
        cnode = cnode->next;
    }
    return 0;
}
