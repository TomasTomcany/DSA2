#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
    long data;
    struct Node *left;
    struct Node *right;
    long height;
}node;

node *search(node *current, long value){
    long data = current->data;
    while (data != value){
        if (current == NULL) {return NULL;}                     // in case previous node was a leaf
        else if (data < value) {search(current->left, value);}  // move to left child
        else {search(current->right, value);}                   // move to right child
    }
    return current;
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

void preorder_print(node *node){
    if (node != NULL) {
        printf("%d ", node->data);
        preorder_print(node->left);
        preorder_print(node->right);
    }
}

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

int main(void){
    node *root = NULL;              // initializing root of the tree
    srand(time(0));                 // setting random number generator

//    root = insert(root, 30);
//    root = insert(root, 17);
//    root = insert(root, 11);
//    root = insert(root, 10);
//    root = insert(root, 27);
//    root = insert(root, 82);
//    root = insert(root, 78);
//    root = insert(root, 73);
//    root = insert(root, 79);
//    root = insert(root, 90);


    clock_t start = clock();
    for(long i=0;i<1000000;i++)
    {
        root=insert(root,(rand() % 10000000)+1);
    }
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);

    return 0;
}