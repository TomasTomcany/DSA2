#ifndef RED_BLACK_H
#define RED_BLACK_H

struct node
{
    int data;
    char color;
    struct node *left, *right, *parent;
};
struct node *search_rb(struct node *current, long value);
void LeftRotate(struct node **root,struct node *x);
void rightRotate(struct node **root,struct node *y);
void insertFixUp(struct node **root,struct node *z);
void insert_rb(struct node **root, long data);

#endif
