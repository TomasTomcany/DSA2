#ifndef AVL_H
#define AVL_H

typedef struct Node
{
    long data;
    struct Node *left;
    struct Node *right;
    long height;
}node;
node *search(node *current, long value);
void *set_height(node *node);
node *rotate_right(node *x);
node *rotate_left(node *x);
long get_balance(node *node);
node *insert(node *node, long value);


#endif
