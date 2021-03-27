#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    long data;
    struct Node *left;
    struct Node *right;
    long height;
}node;

node *search(node *current, long value){
    if (current == NULL || current->data == value)      // base case, node is NULL or node value equals searched value
        return current;

    else if (value < current->data)                     // case of searched value being lower then node value
        return search(current->left, value);

    return search(current->right, value);               // case of searched value being greater then node value
}

// setting height of a node
void *set_height(node *node){
    long left_h, right_h;
    if (node == NULL){node->height = 0;}            // null node has a height of 0

    if (node->left == NULL){left_h = 0;}            // calculate left side height
    else {left_h = 1 + node->left->height;}

    if (node->right == NULL){right_h = 0;}          // calculate right side height
    else {right_h = 1 + node->right->height;}

    if (left_h > right_h){node->height = left_h;}   // set node height as maximum of left_h and right_h
    else {node->height = right_h;}
    return NULL;
}

node *rotate_right(node *x){
    node *y = x->left;
    node *z = y->right;

    // rotation
    y->right = x;
    x->left = z;

    // set new heights, node x is now lower so it has to be set first
    set_height(x);
    set_height(y);

    return y;
}

node *rotate_left(node *x){
    node *y = x->right;
    node *z = y->left;

    // rotation
    y->left = x;
    x->right = z;

    // set new heights, node x is now lower so it has to be set first
    set_height(x);
    set_height(y);

    return y;
}

// check if tree is balanced
long get_balance(node *node){
    long left_h, right_h;
    if (node == NULL){return 0;}

    if (node->left == NULL){left_h = 0;}        // setting up height of the left child
    else{left_h = node->left->height;}

    if (node->right == NULL){right_h = 0;}      // setting up height of the right child
    else{right_h = node->right->height;}

    return (left_h - right_h);                  // difference of heights of left and right subtree is balance

}

//void preorder_print(node *node){
//    if (node != NULL) {
//        printf("%ld ", node->data);
//        preorder_print(node->left);
//        preorder_print(node->right);
//    }
//}

node *insert(node *node, long value){
    // in case there is no node in tree yet
    if (node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
    }
        // inserting into tree based of on binary search
    else{
        if (value < node->data){
            node->left = insert(node->left, value);
            if (get_balance(node) > 1){                     // right-right rotation
                if (value > node->left->data){
                    node->left = rotate_left(node->left);    // change to right-left rotation
                }
                return rotate_right(node);
            }
        }
        else if (value > node->data){
            node->right = insert(node->right, value);
            if (get_balance(node) < -1){                      // left-left rotation
                if (value < node->right->data){
                    node->right = rotate_right(node->right); // change to left-right rotation
                }
                return rotate_left(node);

            }
        }
        else{return node;}                                  // cant enter the same value

        set_height(node);                                   // set height of node after new node has been inserted
    }

    return node;
}
