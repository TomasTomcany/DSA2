#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "AVL.h"
#include "Red-Black.h"

void tree_tester(){
    node *root1 = NULL;                         // initializing root of the tree
    struct node *root2 = NULL;
    long size = 1000000;                        // size of tree and range of values
    srand(time(NULL));                 // setting random number generator

    // test insert avl
    clock_t start = clock();
    for(long i=0;i<size;i++)
    {
        root1=insert(root1,(rand() % size*10)+1);
    }
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation insert of AVL tree in ms: %f\n", elapsed);

    // test insert red-black
    start = clock();
    for (int i = 0; i < size; ++i)
        insert_rb(&root2, (rand() % size*10)+1);
    stop = clock();
    elapsed = (double)(stop - start)  * 1000/ CLOCKS_PER_SEC;
    printf("Operation insert of Red_Black tree in ms: %f\n",elapsed);

    // test search avl
    start = clock();
    for(long i=0;i<size;i++)
    {
        search(root1, (rand() % size*10)+1);
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation search of AVL tree in ms: %f\n", elapsed);

    // test search red-black
    start = clock();
    for(long i=0;i<size;i++)
    {
        search_rb(root2, (rand() % size*10)+1);
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation search of Red-Black tree in ms: %f\n", elapsed);
}

int main(void){
    tree_tester();
    return 0;
}