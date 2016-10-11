#include <iostream>
#include <stdlib.h>
#include <queue.h>
using namespace std;

typedef struct NODE {
    int data;
    char color;
    NODE *lc;
    NODE *rc;
} NODE;

NODE *(new_node)(int d) {
    NODE *t = NULL;
    t = (NODE *)malloc(sizeof(NODE));
    t->data = d;
    t->color = 'w';
    t->lc = NULL;
    t->rc = NULL;
    return t;
}

int max(int a, int b) {
    return a>b ? a : b;
}
int min(int a, int b) {
    return a<b ? a : b;
}
int depth(NODE *r) {
    if(r == NULL)
        return 0;
    else if(r->lc == NULL && r->rc == NULL)
        return 1;
    else 
        return 1 + max(depth(r->lc), depth(r->rc));
}

queue<NODE *> q;

int min_depth(NODE *r) {
    NODE *temp = NULL;
    if(r == NULL)
        return 0;
    else if(r->lc == NULL && r->rc == NULL)
        return 1;
    /**
     * recursive method, traverses entire tree to compute, BAD !
     */
    /*
    else 
        return 1 + min(min_depth(r->lc), min_depth(r->rc));
    */
    /**
     * BFS approach
     */
    else {
        q.push(r);
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            temp->color = 'b';
            if(!temp->lc)
                return c;
            else if(temp->lc->color == 'w')
                q.push(temp->lc);

            if(!temp->rc)
                return c;
            else if(temp->rc->color == 'w')
                q.push(temp->rc);

        }
    }
}

int main () {
    NODE *n = new_node(10);
    n->lc = new_node(12);
    n->rc = new_node(23);
    n->lc->rc = new_node(3);
    n->lc->lc = new_node(4);
    n->lc->rc->rc = new_node(3);
    cout << depth(n) << endl;
    return 0;
}